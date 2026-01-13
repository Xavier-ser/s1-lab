num = int(input("Enter number: "))
lim = int(input("Multiplication upto: "))

for i in range(1,lim+1):
    print(f"{i} * {num} = {num*i}")