

test_cases = input()

def factorial(n):
    if n == 1 or n == 0:
        return 1
    else:
        return n * factorial(n-1)


for t in range(test_cases):
    string = raw_input()
    

    string_dictionary={}
    for char in string:
        if char not in string_dictionary:
            string_dictionary[char] = 1
        else:
            string_dictionary[char]+=1
    
    string_length = len(string) - 1
    char_factorial_dict = {}
    rank_count = 0
    char_factorial_dict[string_length] = factorial(string_length)
            
    for char in string_dictionary.keys():
        if string_dictionary[char] not in char_factorial_dict.keys():
            string_dictionary[char] = factorial(string_dictionary[char])
    
    for char in string:
        if string_length == 0:
            break
        small_char_list = [char2 for char2 in string_dictionary.keys() if char > char2]

        current_char_counts = string_dictionary[char] - 1
        if current_char_counts not in char_factorial_dict.keys():
            char_factorial_dict[current_char_counts] = factorial(current_char_counts)


        if string_length not in char_factorial_dict.keys():
            char_factorial_dict[string_length] = factorial(string_length)
        length_count_fact = char_factorial_dict[string_length]

        if string_dictionary[char] == 1:
            string_dictionary.pop(char)
        else:
            string_dictionary[char]-=1


            

        for small_char in small_char_list:

            divide_fact = 1
            divide_fact *= char_factorial_dict[current_char_counts]

        
        # for small_char in small_char_list:
            small_char_count = string_dictionary[small_char]
            if small_char_count not in char_factorial_dict.keys():
                char_factorial_dict[small_char_count] = factorial(small_char_count)
            small_char_fact = char_factorial_dict[small_char_count]
            divide_fact*=small_char_fact

            rank_count += (length_count_fact/divide_fact)

        string_length -= 1
            # temp_count = string_dictionary[char]-1
    rank_count+=1
    print(rank_count)
            




