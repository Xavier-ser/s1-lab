my_dict = {'b': 3, 'a': 5, 'd': 1, 'c': 4}

keys = []
for key in my_dict:
    keys.append(key)

for i in range(len(keys)):
    for j in range(0, len(keys) - i - 1):
        if keys[j] > keys[j + 1]:
            keys[j], keys[j + 1] = keys[j + 1], keys[j]

asc_dict = {}
for key in keys:
    asc_dict[key] = my_dict[key]

desc_dict = {}
for i in range(len(keys)-1, -1, -1):
    desc_dict[keys[i]] = my_dict[keys[i]]

print("Original Dictionary:", my_dict)
print("Ascending Order:", asc_dict)
print("Descending Order:", desc_dict)
