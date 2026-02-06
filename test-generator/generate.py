import sys
from collections import defaultdict
from pathlib import Path
import json
from pprint import pprint 
from jinja2 import Environment, FileSystemLoader

# defines
NC = "\033[0m"
RED = "\033[0;31m"
GREEN = "\033[0;32m"

def generate_from_json(spectest: dict[str, defaultdict[str, list]], output_file: Path):
    env = Environment(loader=FileSystemLoader("test-generator"), trim_blocks=True, lstrip_blocks=True)
    template = env.get_template("gtest.cpp.j2")
    rendered = template.render(data=spectest)

    with open(output_file, "w") as f:
        f.write(rendered)

def load_spectest(input_file: Path) -> dict[str, defaultdict[str, list]] | None:
    with open(input_file, "r") as f:
        input = json.load(f)
        spec_test: dict[str, defaultdict[str, list]] = {}

        active_module = None

        for command in input["commands"]:
            if command["type"] == "module" and command["type"] not in spec_test:
                active_module = command["filename"]
                spec_test[active_module] = defaultdict(lambda: [])
            elif command["type"].startswith("assert") and active_module:
                spec_test[active_module][command["action"]["field"]].append({"args": command["action"]["args"], "expected": command["expected"], "type": command["type"].split('_')[1]})

        # pprint(spec_test)
        return spec_test
    
    return None

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Usage: python generate.py path_to_jsons [output_directory]")
        sys.exit(1)
    
    allow_list = [
        "loop.json",
        "div.json",
        "linear-memory-data.json",
        "linear-memory-load.json",
        ]

    # find all json files
    for input_file in Path(sys.argv[1]).rglob('*.json'):
        # for now, we only allow a specific set of files
        if input_file.name not in allow_list:
            continue

        spec_test = load_spectest(input_file)

        # extract filename without extension
        output_file = Path(sys.argv[2]) / (input_file.stem + '_test.cpp') if len(sys.argv) > 2 else None
        print("generating test from '{}' to '{}'...".format(input_file, output_file), end="")
        if output_file and spec_test:
            generate_from_json(spec_test, output_file)        
            print(GREEN,"OK", NC)
        else:
            print(RED, "Error", NC)