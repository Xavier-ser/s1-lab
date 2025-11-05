input_file = "area.py"
output_file = "output.txt"

with open(input_file, 'r') as infile:
    lines = infile.readlines()

with open(output_file, 'w') as outfile:
    for i, line in enumerate(lines, start=1):
        if i % 2 != 0:
            outfile.write(line)

print(f"Odd lines copied from '{input_file}' to '{output_file}' successfully.")
