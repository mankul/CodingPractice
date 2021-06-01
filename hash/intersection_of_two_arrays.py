

test_cases = input()


for t in range(test_cases):
    n = input()
    m = input()
    dict={}
    arr=[]
    for i in range(n):
        num = input()
        if num not in dict.keys():
            dict[num] = 1
        else:
            dict[num]+=1
    intersection_array=[]
    for i in range(m):
        num = input()
        if num in dict.keys():
            intersection_array.append(num)

    print(intersection_array)
