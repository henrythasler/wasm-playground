#!/usr/bin/env python3
"""
Convert WAST (WebAssembly Text) files to Google Test C++ code.
Groups all assertions for one module into a single TEST statement.
"""

import re
import sys
from pathlib import Path
from typing import List, Dict, Tuple


class WASTParser:
    def __init__(self, content: str):
        self.content = content
        self.modules = []
        self.assertions = []
        
    def parse(self):
        """Parse WAST file and extract modules and assertions."""
        lines = self.content.split('\n')
        current_module = None
        module_assertions = []
        
        for line in lines:
            line = line.strip()
            
            # Detect module start
            if line.startswith('(module'):
                if current_module:
                    self.modules.append({
                        'name': current_module,
                        'assertions': module_assertions
                    })
                    module_assertions = []
                
                # Extract module name if present
                name_match = re.search(r'\$(\w+)', line)
                current_module = name_match.group(1) if name_match else f"module_{len(self.modules)}"
            
            # Parse assert_return
            elif 'assert_return' in line:
                assertion = self._parse_assert_return(line)
                if assertion:
                    module_assertions.append(assertion)
            
            # Parse assert_trap
            elif 'assert_trap' in line:
                assertion = self._parse_assert_trap(line)
                if assertion:
                    module_assertions.append(assertion)
            
            # Parse assert_invalid or assert_malformed
            elif 'assert_invalid' in line or 'assert_malformed' in line:
                assertion = self._parse_assert_invalid(line)
                if assertion:
                    module_assertions.append(assertion)
        
        # Add last module
        if current_module and module_assertions:
            self.modules.append({
                'name': current_module,
                'assertions': module_assertions
            })
        
        return self.modules
    
    def _parse_assert_return(self, line: str) -> Dict:
        """Parse assert_return statements."""
        # Example: (assert_return (invoke "add" (i32.const 1) (i32.const 2)) (i32.const 3))
        invoke_match = re.search(r'invoke \"(.+?)\" (.*?\))\)', line)
        result_match = re.search(r'\)\s*\(([^)]+)\)\s*\)', line)
        
        if invoke_match:
            func_name = invoke_match.group(1)
            params_str = invoke_match.group(2).strip()
            
            # Extract parameters
            params = self._extract_params(params_str)
            
            # Extract expected result
            expected = None
            if result_match:
                expected = result_match.group(1).strip()

            # print(func_name, params_str, params, expected)
            
            return {
                'type': 'assert_return',
                'function': func_name,
                'params': params,
                'expected': expected
            }
        return None
    
    def _parse_assert_trap(self, line: str) -> Dict:
        """Parse assert_trap statements."""
        # Example: (assert_trap (invoke "div" (i32.const 1) (i32.const 0)) "integer divide by zero")
        invoke_match = re.search(r'invoke \"(.+?)\" (.*?\))\)', line)
        error_match = re.search(r'"([^"]+)"\s*\)', line)
        
        if invoke_match:
            func_name = invoke_match.group(1)
            params_str = invoke_match.group(2).strip()
            params = self._extract_params(params_str)
            error_msg = error_match.group(1) if error_match else "trap"
            
            return {
                'type': 'assert_trap',
                'function': func_name,
                'params': params,
                'error': error_msg
            }
        return None
    
    def _parse_assert_invalid(self, line: str) -> Dict:
        """Parse assert_invalid/assert_malformed statements."""
        error_match = re.search(r'"([^"]+)"\s*\)', line)
        assert_type = 'assert_invalid' if 'assert_invalid' in line else 'assert_malformed'
        
        return {
            'type': assert_type,
            'error': error_match.group(1) if error_match else "invalid"
        }
    
    def _extract_params(self, params_str: str) -> List[Tuple[str, str]]:
        """Extract parameters from a parameter string."""
        params = []
        # Match patterns like (i32.const 42) or (f64.const 3.14)
        param_matches = re.findall(r'\((\w+)\.const\s+([^)]+)\)', params_str)
        for type_name, value in param_matches:
            params.append((type_name, value))
        return params


class GTestGenerator:
    def __init__(self, modules: List[Dict], test_suite_name: str = "WasmTest"):
        self.modules = modules
        self.test_suite_name = test_suite_name
    
    def generate(self) -> str:
        """Generate complete GTest C++ code."""
        code = self._generate_header()
        
        for module in self.modules:
            code += self._generate_test_case(module)
        
        code += self._generate_main()
        return code
    
    def _generate_header(self) -> str:
        """Generate C++ header includes and setup."""
        return '''#include <gtest/gtest.h>
#include <cmath>
#include <limits>

// WebAssembly module interface - implement these functions
// based on your actual WASM runtime/implementation

namespace wasm {
    // Add your WASM module execution functions here
    // Example:
    // int32_t invoke_i32(const char* func_name, ...);
    // float invoke_f32(const char* func_name, ...);
    // double invoke_f64(const char* func_name, ...);
}

'''
    
    def _generate_test_case(self, module: Dict) -> str:
        """Generate a single TEST case for a module with all its assertions."""
        test_name = self._sanitize_name(module['name'])
        code = f"TEST({self.test_suite_name}, {test_name}) {{\n"
        
        if not module['assertions']:
            code += "    // No assertions for this module\n"
        
        for i, assertion in enumerate(module['assertions']):
            if i > 0:
                code += "\n"
            code += self._generate_assertion(assertion)
        
        code += "}\n\n"
        return code
    
    def _generate_assertion(self, assertion: Dict) -> str:
        """Generate C++ code for a single assertion."""
        if assertion['type'] == 'assert_return':
            return self._generate_assert_return(assertion)
        elif assertion['type'] == 'assert_trap':
            return self._generate_assert_trap(assertion)
        else:
            return self._generate_assert_invalid(assertion)
    
    def _generate_assert_return(self, assertion: Dict) -> str:
        """Generate code for assert_return."""
        func = assertion['function']
        params = assertion['params']
        expected = assertion['expected']
        
        # Build parameter list
        param_list = ', '.join([self._convert_value(t, v) for t, v in params])
        
        # Determine the function call
        func_call = f'wasm::invoke_{params[0][0] if params else "void"}("{func}"'
        if param_list:
            func_call += f', {param_list}'
        func_call += ')'
        
        if expected:
            exp_type, exp_val = self._parse_expected(expected)
            expected_value = self._convert_value(exp_type, exp_val)
            return f'    EXPECT_EQ({func_call}, {expected_value});\n'
        else:
            return f'    {func_call};  // No return value expected\n'
    
    def _generate_assert_trap(self, assertion: Dict) -> str:
        """Generate code for assert_trap."""
        func = assertion['function']
        params = assertion['params']
        error = assertion['error']
        
        param_list = ', '.join([self._convert_value(t, v) for t, v in params])
        func_call = f'wasm::invoke_{params[0][0] if params else "void"}("{func}"'
        if param_list:
            func_call += f', {param_list}'
        func_call += ')'
        
        return f'    EXPECT_THROW({func_call}, std::runtime_error);  // {error}\n'
    
    def _generate_assert_invalid(self, assertion: Dict) -> str:
        """Generate code for assert_invalid/assert_malformed."""
        error = assertion['error']
        return f'    // {assertion["type"]}: {error}\n    // Module validation should fail\n'
    
    def _parse_expected(self, expected: str) -> Tuple[str, str]:
        """Parse expected value string."""
        match = re.match(r'(\w+)\.const\s+(.+)', expected)
        if match:
            return match.group(1), match.group(2)
        return 'i32', expected
    
    def _convert_value(self, type_name: str, value: str) -> str:
        """Convert WAST value to C++ value."""
        value = value.strip()
        
        if type_name == 'i32':
            return value
        elif type_name == 'i64':
            return f'{value}LL'
        elif type_name == 'f32':
            if 'nan' in value.lower():
                return 'std::numeric_limits<float>::quiet_NaN()'
            elif 'inf' in value.lower():
                return 'std::numeric_limits<float>::infinity()'
            return f'{value}f'
        elif type_name == 'f64':
            if 'nan' in value.lower():
                return 'std::numeric_limits<double>::quiet_NaN()'
            elif 'inf' in value.lower():
                return 'std::numeric_limits<double>::infinity()'
            return value
        return value
    
    def _sanitize_name(self, name: str) -> str:
        """Sanitize module name for use as C++ identifier."""
        # Replace non-alphanumeric characters with underscores
        name = re.sub(r'[^a-zA-Z0-9_]', '_', name)
        # Ensure it doesn't start with a number
        if name and name[0].isdigit():
            name = 'test_' + name
        return name if name else 'unnamed_module'
    
    def _generate_main(self) -> str:
        """Generate main function for standalone executable."""
        return '''int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
'''


def convert_wast_to_gtest(wast_file: Path, output_file: Path = None, test_suite_name: str = "WasmTest"):
    """Convert a WAST file to GTest C++ code."""
    # Read WAST file
    with open(wast_file, 'r') as f:
        content = f.read()
    
    # Parse WAST
    parser = WASTParser(content)
    modules = parser.parse()

    # print(modules)
    
    # Generate GTest code
    generator = GTestGenerator(modules, test_suite_name)
    cpp_code = generator.generate()
    
    # Write output
    if output_file:
        with open(output_file, 'w') as f:
            f.write(cpp_code)
        print(f"Generated GTest file: {output_file}")
    else:
        print(cpp_code)
    
    return cpp_code


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Usage: python wast_to_gtest.py <input.wast> [output.cpp] [test_suite_name]")
        sys.exit(1)
    
    input_file = Path(sys.argv[1])
    output_file = Path(sys.argv[2]) if len(sys.argv) > 2 else None
    test_suite = sys.argv[3] if len(sys.argv) > 3 else "WasmTest"
    
    if not input_file.exists():
        print(f"Error: Input file '{input_file}' not found")
        sys.exit(1)
    
    convert_wast_to_gtest(input_file, output_file, test_suite)