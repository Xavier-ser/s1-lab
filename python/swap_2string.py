str1 = input("Enter first string: ")
str2 = input("Enter second string: ")

if len(str1) > 0 and len(str2) > 0:
    new_str1 = str2[0] + str1[1:]
    new_str2 = str1[0] + str2[1:]
    
    result = new_str1 + " " + new_str2
    
    print("Result after swapping first characters and merging:")
    print(result)
else:
    print("Both strings must be non-empty.")
