class Time:
    def __init__(self, h, m):
        self.__hours = h     
        self.__minutes = m   

    def __add__(self, other):
        total_hours = self.__hours + other.__hours
        total_minutes = self.__minutes + other.__minutes

        if total_minutes >= 60:
            total_hours += total_minutes // 60
            total_minutes = total_minutes % 60

        return Time(total_hours, total_minutes)

    def show(self):
        print(f"{self.__hours:02d}:{self.__minutes:02d}")

t1 = Time(2, 50)
t2 = Time(1, 30)
t3 = t1 + t2   

print("Time 1:", end=" "); t1.show()
print("Time 2:", end=" "); t2.show()
print("Total :", end=" "); t3.show()
