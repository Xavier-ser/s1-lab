import math

a = float(input("Enter coefficient a: "))
b = float(input("Enter coefficient b: "))
c = float(input("Enter coefficient c: "))

if a == 0:
    print("Coefficient 'a' cannot be 0 in a quadratic equation.")
else:
    d = b**2 - 4*a*c  

    if d >= 0:
        root2 = (-b - math.sqrt(d)) / (2*a)
    else:
        real = -b / (2*a)
        imag = math.sqrt(-d) / (2*a)
        root1 = f"{real} + {imag}i"
        root2 = f"{real} - {imag}i"

    print(f"Root 1: {root1}")
    print(f"Root 2: {root2}")
