


test_cases = input()


for t in range(test_cases):
    n = input()
    arr={}
    for i in range(n):
        num = input()
        if num not in arr.keys():
            arr[num] = 1
        else:
            arr[num]+=1
    
    for key, value in arr.items():
        print(key, value)
    

