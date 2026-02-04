import re
import sys
from pathlib import Path
import json
from jinja2 import Environment, FileSystemLoader

def generate_from_json(json_input: str, output_file: str = "generated.cpp"):
    with open(json_input, "r") as f:
        spectest = json.load(f)

    env = Environment(loader=FileSystemLoader("test-generator"), trim_blocks=True, lstrip_blocks=True)
    template = env.get_template("gtest.cpp.j2")
    rendered = template.render(data=spectest)

    with open(output_file, "w") as f:
        f.write(rendered)

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Usage: python generate.py path_to_jsons [output_directory]")
        sys.exit(1)
    
    allow_list = ["linear-memory-data.json"]

    # find all json files
    for input_file in Path(sys.argv[1]).rglob('*.json'):
        # for now, we only allow a specific set of files
        if input_file.name not in allow_list:
            continue

        # extract filename without extension
        output_file = Path(sys.argv[2]) / (input_file.stem + '_test.cpp') if len(sys.argv) > 2 else None
        print("generating test from '{}' to '{}'".format(input_file, output_file))
        if output_file:
            generate_from_json(input_file, output_file)
    
    print("\033[92mDone!\033[0m")