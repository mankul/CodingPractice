# merge sort


test_cases = input()


# u1 u2 mid, mid+1


def merge_sort(arr, start, end):

    if start==end:
        return [arr[start]]
    if start == end-1:
        if arr[start] > arr[end]:
            return [arr[end], arr[start]]
        else:
            return [arr[start], arr[end]]

    mid = (start + end)/2
    arr1 = merge_sort(arr, start, mid-1)
    arr2 = merge_sort(arr, mid, end)

    len1 = len(arr1)
    len2 = len(arr2)
    index1 = index2 = 0
    new_arr = []
    while index1 < len1 or index2 < len2:
        if index1 == len1:
            new_arr += arr2[index2:]
            break
        elif index2 == len2:
            new_arr += arr1[index2:]
            break   
        if arr1[index1] < arr2[index2]:
            new_arr.append(arr1[index1])
            index1+=1
        else:
            new_arr.append(arr2[index2])
            index2+=1
        

    return new_arr

for i in range(test_cases):
    arrlen = input()
    arr = []

    for j in range(arrlen):
        num = input()
        arr.append(num)
    print(merge_sort(arr, 0 ,arrlen-1))