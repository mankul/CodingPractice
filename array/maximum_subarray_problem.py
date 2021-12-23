

# maximum subarray problem


test_cases = int(input())


def maximum_subarray_sum(arr,len):
    sum = 0
    sum_arr = [0  for i in range(len)]

    for i in range(len):
        if sum + arr[i] <= 0:
            sum = 0
        else:
            sum+=arr[i]
            sum_arr[i] = sum
    max_sum = max(sum_arr)
    return max_sum
for i in range(test_cases):
    len = int(input())
    arr=[]
    for j in range(len):
        num = int(input())
        arr.append(num)
    print(maximum_subarray_sum(arr, len))