# insertion sort. Sort by assuming the array from left is sorted and insert the element at the specific place.



test_cases = input()


def insertion_sort(arr, arr_len):
    # 2 1 3 5 4
    for i in range(1,arr_len):
        index = i
        while index > 0:
            if arr[index] < arr[index-1]:
                temp = arr[index]
                arr[index] = arr[index-1]
                arr[index-1] = temp

            else:
                break
            index -=1


for i in range(test_cases):
    arr_len = input()
    arr=[]
        
    for j in range(arr_len):
        num = input()
        arr.append(num)    
    insertion_sort(arr, arr_len)
    print(arr)