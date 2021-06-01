

test_cases = input()


for t in range(test_cases):
    n = input()
    m = input()

    dict1={}
    union_array=[]

    for i in range(n):
        num = input()
        if num not in dict1.keys():
            dict1[num] = 1
            union_array.append(num)
        else:
            dict1[num]+=1

    for m in range(m):
        num = input()
        if num not in dict1.keys():
            dict1[num] = 1
            union_array.append(num)
    print(union_array)