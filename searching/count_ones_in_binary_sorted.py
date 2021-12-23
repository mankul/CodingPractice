# count ones in sorted array binary sorted



test_cases = input()


def count_ones(arr, start, end):
    if start == end:
        if arr[start]!=0:
            return -1
        else:
            return start
    mid = (start + end)/2
    if arr[mid] == 1:
        return mid
    else:
        return count_ones(arr, mid, end)





for i in range(test_cases):
    arr_len=input()
    arr=[]
    for j in range(arr_len):
        num = input()
        arr.append(num)
    index = count_ones(arr, 0 ,arr_len-1)
    if index == arr_len-1:
        print("1")
    elif index == -1:
        print("-1")
    else:
        print(arr_len - index)

