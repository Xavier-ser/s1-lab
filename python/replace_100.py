nums = list(map(int, input("Enter numbers: ").split()))
result = ["over" if n > 100 else n for n in nums]
print(result)
