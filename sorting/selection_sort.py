# selection sort


# find minimum element and push to the front, opposite of bubble sort

test_cases = input()


def selection_sort(arr, arr_len):
    for i in range(arr_len):
        min = i
        index = min+1
        while index < arr_len:
            if arr[index] < arr[min]:
                min = index
            index+=1
        temp =  arr[min]
        arr[min] = arr[i]
        arr[i] = temp



for i in range(test_cases):
    arr_len = input()
    arr= []

    for j in range(arr_len):
        num = input()
        arr.append(num)

    selection_sort(arr,arr_len)
    print(arr)