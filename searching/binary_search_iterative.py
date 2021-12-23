

test_cases = input()


def find_element(arr, arr_len, x):
    index = 0
    start = 0
    last = arr_len-1
    while index < arr_len:
        if start == last:
            if arr[start] != x:
                return -1
            else:
                return start

        index = (start + last)/2

        if arr[index] == x:
            return index
        
        elif arr[index] < x:
            start = index + 1

        else:
            last = index - 1
            


for i in range(test_cases):
    # enter the sorted array length, number to be searched and the array elements
    arr=[]
    arr_len = input()
    x = input()
    for j in range(arr_len):
        num = input()
        arr.append(num)
    print(find_element(arr, arr_len, x))