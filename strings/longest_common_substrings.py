

test_cases = input()

for t in range(test_cases):
    string1 = raw_input()
    string2 = raw_input()

    
    table = []
    len1 = len(string1)
    len2 = len(string2)
    for i in range(len1):
        temp_table = []
        for j in range(len2):
            if string1[i] == string2[j]:
                temp_table.append(1)
            else:
                temp_table.append(0)
        table.append(temp_table)
    
    

    max_match_first_index = -1
    max_match_last_index = -1
    first_index = -1
    last_index = -1
    i = j = 0
    carry_match = True
    while i < len1:
        print(table[i])
        j = 0
        # while j < len2:
        #     if table[i][j] == 1:
        #         if not carry_match:

        #             #
        #     j+=1
        i+=1
                

        # for j in range(len2):
        #     print("{} ".format(table[i][j]))
    
                