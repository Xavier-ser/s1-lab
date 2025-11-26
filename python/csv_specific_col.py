import csv

columns_to_read = ["name", "age"]

with open("data.csv", "r", newline="") as file:
    reader = csv.DictReader(file)

    for row in reader:
        for col in columns_to_read:
            print(f"{col}: {row[col]}")
        print("---")
