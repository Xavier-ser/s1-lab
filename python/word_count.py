text = input("Enter a line of text: ")

words = text.split()  

for word in set(words):   
    print(word, ":", words.count(word))
