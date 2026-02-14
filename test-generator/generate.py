import sys
from dataclasses import dataclass
from pathlib import Path
import json
from pprint import pprint
from jinja2 import Environment, FileSystemLoader

# defines
NC = "\033[0m"
RED = "\033[0;31m"
GREEN = "\033[0;32m"

types_map = {
    "i32": "int32_t",
    "i64": "int64_t",
}

@dataclass
class Signature:
    type: str
    cpp_type: str

@dataclass
class Function:
    args: list[Signature]
    expected: list[Signature]


@dataclass
class Assert:
    function: str
    type: str
    args: list[str]
    expected: str

@dataclass
class Module:
    functions: dict[str, Function]
    asserts: list[Assert]


def generate_from_json(spectest: dict[str, Module], output_file: Path):
    env = Environment(
        loader=FileSystemLoader("test-generator"), trim_blocks=True, lstrip_blocks=True
    )
    template = env.get_template("gtest.cpp.j2")
    rendered = template.render(data=spectest)

    with open(output_file, "w") as f:
        f.write(rendered)


def load_spectest(input_file: Path) -> dict[str, Module] | None:
    with open(input_file, "r") as f:
        input = json.load(f)
        spec_test: dict[str, Module] = {}

        active_module = None

        for command in input["commands"]:
            if command["type"] == "module" and command["type"] not in spec_test:
                active_module = command["filename"]
                spec_test[active_module] = Module(functions=dict(), asserts=[])
            elif command["type"].startswith("assert") and active_module:
                function_name = command["action"]["field"]

                # collect function signature if not already known
                parameter = []
                expected = []
                for item in command["action"]["args"]:
                    if "type" in item:
                        parameter.append(Signature(type=item["type"], cpp_type=types_map[item["type"]]))
                for item in command["expected"]:
                    if "type" in item:
                        expected.append(Signature(type=item["type"], cpp_type=types_map[item["type"]]))

                # add or update current signature
                if function_name not in spec_test[active_module].functions.keys() or len(spec_test[active_module].functions[function_name].args) < len(parameter) or len(spec_test[active_module].functions[function_name].expected) < len(expected):
                    spec_test[active_module].functions[function_name] = Function(args=parameter, expected=expected)

                # transform asserts
                parameter = []
                expected = ""
                for item in command["action"]["args"]:
                    if "value" in item:
                        parameter.append("static_cast<{}>({}ULL)".format(types_map[item["type"]], item["value"]))
                for item in command["expected"]:
                    if "value" in item:
                        expected = "static_cast<{}>({}ULL)".format(types_map[item["type"]], item["value"])
                spec_test[active_module].asserts.append(Assert(function=function_name, type=command["type"].split('_')[1], args=parameter, expected=expected))

        # pprint(spec_test)
        return spec_test

    return None


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python generate.py path_to_jsons [output_directory]")
        sys.exit(1)

    allow_list = [
        "loop.json",
        "div.json",
        "linear-memory-data.json",
        "linear-memory-load.json",
        "linear-memory-store.json",
        "linear-memory-grow.json",
        "stack_overflow.json",
    ]

    # find all json files
    for input_file in Path(sys.argv[1]).rglob("*.json"):
        # for now, we only allow a specific set of files
        if input_file.name not in allow_list:
            continue

        spec_test = load_spectest(input_file)

        # extract filename without extension
        output_file = (
            Path(sys.argv[2]) / (input_file.stem + "_test.cpp")
            if len(sys.argv) > 2
            else None
        )
        print(
            "generating test from '{}' to '{}'...".format(input_file, output_file),
            end="",
        )
        if output_file and spec_test:
            generate_from_json(spec_test, output_file)
            print(GREEN, "OK", NC)
        else:
            print(RED, "Error", NC)
