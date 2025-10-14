# Read two numbers from user
a = int(input("Enter first number: "))
b = int(input("Enter second number: "))

# Euclidean Algorithm for GCD
def find_gcd(x, y):
    while y != 0:
        x, y = y, x % y
    return x

# Calculate and print GCD
gcd = find_gcd(a, b)
print("GCD of", a, "and", b, "is:", gcd)
