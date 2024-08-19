# use sliding window protocol.
# search for a permutation of a string is present in text.

# example:
# text: abcdefgh
# string: abfgd

# a simple strategy:
# for n-k+1 substrings of length k present in the text, try to find if the string permutation is present in the text.
# This way we can identify all of substrings present.

# smart strategy: Use a sliding window to remember the last matched characters. In case matching fails, the current position is the place where we are sure, we dont find a match.
# count the chars in string in a dictionary.
# Now we shall see if a possible permutation of string is present in text, by using a sliding window. Grow the size of window each time character matches.
# start iterating over the text. Check if the character belongs to the string, and the count is not 0.
# If the character is found in the dictionary and the count is > 1. Reduce the count by 1.
# If character is not found, then refresh the variables and set dictionary to default dictionary and start over reading from position where we have stopped the window, and refresh the window size to 1 and position at index + subindex.
# Whenever the window size reaches the string size, we have got our permutation from present index to index - len(string)
#
#






test_cases = input()

for t in range(test_cases):
    text = raw_input()
    string_ = raw_input()

    # find if the permutation of string is present in text.
    # a better strategy

    char_dictionary = {}
    for char in string_:
        if char not in char_dictionary.keys():
            char_dictionary[char] = 1
        else:
            char_dictionary[char] += 1

    permutation_present = False


    # sliding window code
    text_length = len(text)
    windows_ = text_length - len(string_) + 1
    index = 0
    while index < windows_:
        count = 0
        copy_char_dictionary = char_dictionary.copy()
        for subindex in range(len(string_)):
            if text[index + subindex] in copy_char_dictionary.keys():
                copy_char_dictionary[text[index + subindex]] -= 1
                if copy_char_dictionary[text[index + subindex]] == 0:
                    copy_char_dictionary.pop(text[index + subindex])
                count += 1
            else:
                break
        if count < len(string_):
            index += (subindex + 1)
        elif count > len(string_):
            print("Not possible. code seems buggy.")
        else:
            permutation_present = True
            print("Permutation is {}".format(text[index:index + len(string_))
            break
                
            
    exit(0)
    # simple strategy
    text_length = len(text)
    sliding_window_length = len(string_)
    for index in range(text_length-sliding_window_length + 1):
        count = 0
        for subindex in range(sliding_window_length):
            if text[subindex] in copy_char_dictionary.keys():
                if copy_char_dictionary[text[subindex]] > 0:
                    copy_char_dictionary[text[subindex]] -= 1
                    count += 1
            else:
            copy_char_dictionary = char_dictionary.copy()
                break
        if count == len(string_):
            permutation_present = True
            break
	if permutation_present is True:
        print("Permutation of string is present")
    else:
        print("Permutation is not present")


    # sliding window strategy code . Need correction with some variables.
        # for running_index in range(index, index+sliding_window_length):
            # check for permutation 
            # running_char = text[running_index]
            # if running_char in copy_char_dictionary.keys():
            #     if copy_char_dictionary[running_char] == 1:
            #         copy_char_dictionary.pop(running_char)
            #     else:
            #         copy_char_dictionary[running_char] -= 1
            # else:
            #     permutation_present = False
            #     break
        #     
        # if permutation_present == False:
        #     copy_char_dictionary = char_dictionary.copy()
        #     permutation_present = True
        # else:
        #     print("Permutation Found")
        #     break
    # if permutation_present == False:
    #     print("Permutation not found")


