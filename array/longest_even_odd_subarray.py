

test_cases = int(input())

def longest_even_odd_subarray(arr,len):
    prev = arr[0] % 2
    sum = 1
    max_sum = 0
    for el in arr[1:]:
        cur = el % 2
        if cur == 0 and prev == 0:
            max_sum = max(max_sum, sum)
            sum = 1
        elif cur == 0 and prev ==1:
            sum+=1
            prev = 0
        elif cur ==1 and prev == 0:
            sum+=1
            prev = 1
        else:
            max_sum = max(max_sum, sum)
            sum = 1
    max_sum = max(max_sum, sum)
    return max_sum

for i in range(test_cases):
    len = int(input())
    arr=[]
    for j in range(len):
        num = int(input())
        arr.append(num)
    print(longest_even_odd_subarray(arr,len))