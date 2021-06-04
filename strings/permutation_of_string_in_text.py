# use sliding window protocol.

test_cases = input()

for t in range(test_cases):
    text = raw_input()
    string_ = raw_input()

    # find if the permutation of string is present in text.
    # store

    char_dictionary = {}
    for char in string_:
        if char not in char_dictionary.keys():
            char_dictionary[char] = 1
        else:
            char_dictionary[char] += 1

    copy_char_dictionary = char_dictionary.copy()
    permutation_present = True

    text_length = len(text)
    sliding_window_length = len(string_)

    for index in range(text_length-sliding_window_length + 1):
        for running_index in range(index, index+sliding_window_length):
            # check for permutation 
            running_char = text[running_index]
            if running_char in copy_char_dictionary.keys():
                if copy_char_dictionary[running_char] == 1:
                    copy_char_dictionary.pop(running_char)
                else:
                    copy_char_dictionary[running_char] -= 1
            else:
                permutation_present = False
                break
            
        if permutation_present == False:
            copy_char_dictionary = char_dictionary.copy()
            permutation_present = True
        else:
            print("Permutation Found")
            break
    if permutation_present == False:
        print("Permutation not found")


