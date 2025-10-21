def char_frequency(s):
    freq = {}
    for ch in s:
        if ch in freq:
            freq[ch] += 1
        else:
            freq[ch] = 1
    return freq

string = input("Enter a string: ")
result = char_frequency(string)

print("Character frequencies:")
for ch, count in result.items():
    print(ch, ":", count)
# print(result)