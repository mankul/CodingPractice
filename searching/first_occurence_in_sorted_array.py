

test_cases = input()

# sorted array, find first index of the element in O(logn)
# use binary search technique

def find_first_index(arr, index, start, x):
    while index > start:
        if arr[index] != x:
            return index+1
        index-=1
    if arr[index] == x:
        return start # or index 
    else:
        return index + 1



def first_index_element(arr, start, end, x):
    if start == end:
        if arr[start] != x:
            return -1
        else:
            return start

    index = (start + end)/2
    if arr[index] == x:
        return find_first_index(arr, index, start, x)
    elif arr[index] < x:
        return first_index_element(arr, index+1, end, x)
    else:
        return first_index_element(arr, start, index - 1, x)
for i in range(test_cases):
    arr=[]
    arr_len = input()
    x = input()
    for j in range(arr_len):
        num = input()
        arr.append(num)
    print(first_index_element(arr, 0, arr_len-1, x))