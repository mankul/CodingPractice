

# recursion


test_cases = input()


def find_element(arr, start, end, x):
    if start == end:
        if arr[start] == x:
            return start
        else:
            return -1
    mid = (start + end) / 2

    if arr[mid] == x:
        return mid
    elif arr[mid] < x:
        start = mid+1
        return find_element(arr, start, end, x)

    else:
        end = mid -1
        return find_element(arr, start, end, x)


for i in range(test_cases):
    arr_len = input()
    x= input()
    arr=[]
    for j in range(arr_len):
        num = input()
        arr.append(num)
    print(find_element(arr, 0 ,arr_len-1, x))
