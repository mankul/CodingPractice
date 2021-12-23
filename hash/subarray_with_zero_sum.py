
test_cases = input()

for t in range(test_cases):
    n = input()
    hash_map = {}
    sum = 0
    arr=[]
    for i in range(n):
        num = input()
        arr.append(num)

    for i in range(n):
        num = arr[i]
        sum+=num
        if sum == 0:
            print("sum is {} with index 0 and {}".format(sum, i))
            break
        if sum in hash_map.keys():
            print("sum is  with index {} and {}".format(hash_map[sum]+1, i))
        hash_map[sum] = i
        
