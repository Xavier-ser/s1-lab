import cmath

a = float(input("Enter coefficient a: "))
b = float(input("Enter coefficient b: "))
c = float(input("Enter coefficient c: "))

if a == 0:
    print("Coefficient 'a' cannot be 0 in a quadratic equation.")
else:
    d = cmath.sqrt(b**2 - 4*a*c)

    root1 = (-b + d) / (2*a)   
    root2 = (-b - d) / (2*a)

    print(f"Root 1: {root1}")
    print(f"Root 2: {root2}")

