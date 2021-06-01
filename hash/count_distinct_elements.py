


# count distinct elements in the array

test_cases = input()

for  t in range(test_cases):
    n = input()
    dict={}
    for i in range(n):
        num = input()
        if num in dict.keys():
            dict[num]+=1
        else:
            dict[num] = 1
    count=0
    for key, value in dict.items():
        if value == 1:
            count+=1
    print(count)
