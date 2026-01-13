num=[]
print("enter 10 integers")
for i in range(10):
    num_new=int(input(f"enter number {i+1}"))
    num.append(num_new)
for i in num:
    if i>0:
        print(i)