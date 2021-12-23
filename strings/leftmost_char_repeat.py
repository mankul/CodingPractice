
test_cases = input()


for i in range(test_cases):
    string1 = raw_input()

    string_dict = {}
    leftmost_char = 0
    for char in string1:
        if char not in string_dict.keys():
            string_dict[char] = 1
        else:
            leftmost_char = char
            break
    if leftmost_char != 0:
        print(char)
    else:
        print("-1")
