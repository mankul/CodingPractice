

test_cases = int(input())

def prefix_sum(arr, arr_len):
    prefix_sum = []
    sum = 0
    for i in range(arr_len):
        prefix_sum.append(sum)
        sum+=arr[i]

    return prefix_sum


for i in range(test_cases):
    arr_len = int(input())
    arr = []
    for j in range(arr_len):
        num = int(input())
        arr.append(num)
    print(prefix_sum(arr, arr_len))