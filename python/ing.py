def add_ing_or_ly(s):
    if s.endswith("ing"):
        return s + "ly"
    else:
        return s + "ing"

word1 = input("Enter a sting: ")

print(add_ing_or_ly(word1)) 

