
print("input text and string seperated by new lines")
text = raw_input()
string = raw_input()

char_dict = {}

for char in string:
    if char in char_dict.keys():
        char_dict[char] += 1
    else:
        char_dict[char] = 0


windows = len(text) - len(string)  + 1
substrings_ = []
substr_counts = 0


# sliding windows to find all possible substring permutations.

index = 0
subindex = 0
char_dict_copy = char_dict.copy()
count = 0

while index < windows:
    while subindex < len(string):
        if text[index + subindex] in char_dict_copy.keys():
            char_dict_copy[text[index + subindex]] -= 1
            if char_dict_copy[text[index + subindex]] == 0:
                char_dict_copy.pop(text[index + subindex])
            count += 1
            subindex += 1
        else:
            break
    if count == len(string):
        substr_counts += 1
        substrings_.append(text[index:index + count])

        char_dict_copy[text[index]] = 1
        count -= 1

        index += 1
        subindex -= 1
    else:
        count = 0
        char_dict_copy = char_dict.copy()

        index += subindex
        subindex = 0




# naive strategy
# all substrings are compared.
for index in range(windows):
    count = 0
    char_dict_copy = char_dict.copy()
    for subindex in range(len(string)):
        if text[index + subindex] in char_dict_copy.keys():
            if char_dict_copy[text[index + subindex]] > 0:
                char_dict_copy[text[index + subindex]] -= 1
                count += 1
            else:
                break
    if count == len(string):
        substrings_.append(text[index:index+count)
        substr_counts += 1

print("substrings count are {}".format(substr_counts))
print("substrings are {}".format(substrings_))


