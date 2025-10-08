def exchange_first_last(s):
    if len(s) <= 1:
        return s  
    return s[-1] + s[1:-1] + s[0]

string = input("Enter a string: ")
result = exchange_first_last(string)
print("After exchanging first and last characters:", result)
