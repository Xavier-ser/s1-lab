def addition(a, b):
    return a + b

def subtraction(a, b):
    return a - b

def multiplication(a, b):
    return a * b

def division(a, b):
    if b != 0:
        return a / b
    else:
        return "Error: Division by zero"

def reminder(a, b):
    if b != 0:
        return a % b
    else:
        return "Error: Division by zero"

a = int(input("Enter a number: "))
b = int(input("Enter a number: "))
c = input("Enter operation (+, -, *, /, %): ")

if c == "+":
    result = addition(a, b)
elif c == "-":
    result = subtraction(a, b)
elif c == "*":
    result = multiplication(a, b)
elif c == "/":
    result = division(a, b)
elif c == "%":
    result = reminder(a, b)
else:
    result = "Invalid operation"

print("Result:", result)
