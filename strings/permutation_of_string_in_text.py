# use sliding window protocol.
# search for a permutation of a string is present in text.

# example:
# text: abcdefgh
# string: abfgd

# strategy:
# count the chars in string in a dictionary.
# Now we shall see if a possible permutation of string is present in text, by using a sliding window. Grow the size of window each time character matches.
# start iterating over the text. Check if the character belongs to the string, and the count is not 0.
# If the character is found in the dictionary and the count is > 1. Reduce the count by 1.
# If character is not found, then refresh the variables and set dictionary to default dictionary and start over reading 
# Whenever the window size reaches the string size, we have got our permutation from present index to index - len(string)
#
#

# a better strategy:
# for n-k+1 substrings of length k present in the text, try to find if the string permutation is present in the text.
# This way we can identify all of substrings present.






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

    copy_char_dictionary = char_dictionary.copy()
    permutation_present = False

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
	if permutation_presnt is True:
        print("Permutation of string is present")
    else:
        print("Permutation is not present")


    # sliding window strategy. Need correction with some variables.
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


