


test_cases = input()


for t in range(test_cases):
    string1 = raw_input()
    string2 = raw_input()

    string1_map={}
    string2_map={}
    for char in string1:
        if char in string1_map.keys():
            string1_map[char]+=1
        else:
            string1_map[char]=1

    for char in string2:
        if char in string2_map.keys():
            string2_map[char]+=1
        else:
            string2_map[char]=1
    anagram = 1
    for key, value in string1_map.items():
        if key not in string2_map.keys():
            anagram = 0
            break
        else:
            if string2_map[key] != value:
                anagram = 0
                break
        string1_map.pop(key)
        string2_map.pop(key)
    if anagram == 0:
        print("not anagram")
    else:
        if string2_map != {} or string1_map!= {}:
            print("not anagram")
        else:
            print("Both are anagram")
    