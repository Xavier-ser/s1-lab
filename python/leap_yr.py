current_yr=int(input("Enter current yr"))
final_yr=int(input("Enter Final year : "))

for i in range(current_yr,final_yr+1):
    if (i%4==0 and i%100!=0) or (i%400==0):
        print(i);

  