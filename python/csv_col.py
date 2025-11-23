import csv

with open("data.csv") as file:
    reader = csv.reader(file)
    for row in reader:
        print(row[1], row[0])
