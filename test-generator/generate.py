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
    generate_from_json("./tests/assets/linear-memory-data.json", "./tests/linear_memory_data_test.cpp")