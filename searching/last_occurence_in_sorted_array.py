# last_occurence_in_sorted_array


# use binary search



test_cases = input()


def find_last_index(arr, end, index, x):
    while index < end:
        if arr[index] != x:
            return index-1
        index+=1
    if arr[index] != x:
        return index-1
    else:
        return index

def find_index( arr, start, end, x):
    if start == end:
        if arr[start] == x:
            return start
        else:
            return -1

    mid = (start + end)/2
    if arr[mid] == x:
        return find_last_index(arr, end, mid, x)
    elif arr[mid] < x:
        return find_index(arr, mid+1, end, x)
    else:
        return find_index(arr, start, mid-1, x)



for i in range(test_cases):
    arr=[]
    arr_len = input()
    x = input()

    for j in range(arr_len):
        num = input()
        arr.append(num)
    print(find_index(arr, 0, arr_len-1, x))
    
