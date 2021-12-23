

# count the occurences of x in sorted array




test_cases = input()


def find_first_index(arr, index, start, x):
    while index > start:
        if arr[index] != x:
            return index+1
        index-=1
    if arr[index] != x:
        return -1
    else:
        return index

def find_last_index(arr, index, end, x):
    while index < end:
        if arr[index] != x:
            return index-1
        index+=1
    if arr[index] != x:
        return -1
    else:
        return index


def calculate_occurence(arr, start, end, index, x):
    last_occur = find_last_index(arr, index, end, x)
    first_occur = find_first_index(arr, index, start, x)

    if last_occur == -1 or first_occur == -1:
        return -1
    if last_occur == first_occur:
        return 1
    else:
        return last_occur - first_occur + 1

def find_index(arr, start, end, x):
    if start == end:
        if arr[start] == x:
            return 1
        else:
            return -1

    mid = (start + end)/2
    if arr[mid] == x:
        return calculate_occurence(arr, start, end, mid, x)

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