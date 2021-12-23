# find an element in sorted and rotated array





test_cases = input()



def find_element(arr, start, end, x):

    mid = (start + end)/2

    if arr[mid] == x:
        return mid
    elif arr[mid] < x:
        if arr[end] > x:
            return find_element(arr, mid+1, end,x)
        else:
            return find_element(arr, start, mid-1,x)

    else:
        if x < arr[start]:
            return find_element(arr, mid+1, end,x)
        else:
            return find_element(arr, start, mid-1,x)

for i in range(test_cases):
    arr=[]
    arr_len=input()
    x=input()

    for j in range(arr_len):
        num = input()
        arr.append(num)

