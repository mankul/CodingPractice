# smaller_string.py


test_cases = input()


def find_smaller_strings(string_n, string_len, k):
    char_bound = []
    char_min = 0
    index = 0
        # odd 6 0,1,2
    while index < string_len/2:
        bound2 = ord(string_n[index]) - ord(string_n[string_len-index-1])
        if bound2 < 0:
            char_min=1
    
        bound = string_n[index]
        # print(bound)
        bound_value = ord(bound) - ord('a')
        
        char_bound.append(bound_value)
        index+=1
    if string_len%2 == 1:
        bound = string_n[index]
        bound_value = ord(bound) - ord('a')
        char_bound.append(bound_value)
    # print(char_bound)

    count=0
    index=0
    limit=0
    if string_len%2 == 0:
        limit = string_len/2
    else:
        limit = string_len/2+1
    while index < limit:
        if char_bound[index] > k:
            count+=pow(k,limit-index)
        else:
            count+=char_bound[index]*pow(k,limit-index-1)
        index+=1

    if char_min == 0:
        count+=1
    return count


    


for i in range(test_cases):
    ln = raw_input()
    string_len, k = ln.split(" ")
    string_len = int(string_len)
    k = int(k)
    string_n = raw_input()

    count = find_smaller_strings(string_n,string_len, k)
    print(count)