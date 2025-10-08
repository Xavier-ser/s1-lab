colors = input("Enter colors separated by commas: ")

color_list = [color.strip() for color in colors.split(",")]

if len(color_list) == 0:
    print("No colors entered.")
else:
    print("First color:", color_list[0])
    print("Last color:", color_list[-1])
