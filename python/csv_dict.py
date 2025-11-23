import csv

data = [
    {"name": "Jithu", "age": 21, "city": "TVM"},
    {"name": "Arun",  "age": 22, "city": "Kochi"},
    {"name": "Anu",   "age": 23, "city": "Calicut"}
]

# Write dictionary to CSV
with open("output.csv", "w", newline="") as file:
    writer = csv.DictWriter(file, fieldnames=data[0].keys())
    writer.writeheader()
    writer.writerows(data)

# Read CSV and display content
with open("output.csv") as file:
    reader = csv.DictReader(file)
    for row in reader:
        print(row)
