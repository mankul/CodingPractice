

test_cases = input()

for t in range(test_cases):
    string_ = raw_input()

    string_length = len(string_)

    index = 0
    palindrome = True
    while index < string_length/2:
        if string_[index] != string_[string_length - 1 - index]:
            palindrome = False
            break
        index+=1
    if palindrome:
        print("Palindrome")
    else:
        print("Not a Palindrome")

