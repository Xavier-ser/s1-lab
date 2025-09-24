a=int(input("enter first number:"))
b=int(input("enter second number:"))
c=int(input("enter third number:"))

if a>b>c:
    print(f"{a} is largest")
elif b>c:
    print(f"{b} is largest")
else:
    print(f"{c} is largest")   
    
