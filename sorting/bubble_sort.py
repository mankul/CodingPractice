

test_cases = input()


def bubble_sort(arr, arr_len): # 2 1 3 5 4
    for i in range(1,arr_len): # 0 1 2 3 4
        index = 0
        while index < arr_len-i: # 0 1 2 3
            # 1 2 3 4 5
            if arr[index] > arr[index+1]: # 2 1
                temp = arr[index] # 2
                arr[index] = arr[index+1] # 1
                arr[index+1] =  temp # 2
            index+=1
        print(arr)
    print(arr)
    



for i in range(test_cases):
    arr_len = input()
    arr = []

    for j in range(arr_len):
        num = input()
        arr.append(num)
    bubble_sort(arr, arr_len)
    print(arr)