even_list = []
for i in range(2, 11):  
    even_list.append(i)

print("Original even list:", even_list)

i = 0
while i < len(even_list):
    if even_list[i] % 2 == 0:
        even_list.pop(i)
    else:
        i += 1  

print("List after removing even numbers:", even_list)

