# trapping rain water probem
# 5 4 3 2 1 6 3 4 9




test_cases = int(input())


def find_trapped_water(arr, len): #2,3 ,4
    left_arr = [0 for i in range(len)]
    right_arr = [0 for i in range(len)]
    maxm = arr[len-1]#4
    index = len-2#1
    while index >= 0:#1, 0
        right_arr[index] = maxm# [0,4,0] [ 4,4,0]
        if maxm < arr[index]:#4, 4
            maxm = arr[index]
        index-=1#0 , -1
    maxm = arr[0] # 2
    index = 1
    while index <= len-1: # 1, 
        left_arr[index] = maxm #[0,2,0], [0,2,3]
        if maxm < arr[index]:# 3]
            maxm = arr[index] #3
        index+=1

    print(left_arr)
    print(right_arr)
    
    water_trapped = 0

    for i in range(1,len-1): # 1
        water_trapped+= max(min(left_arr[i], right_arr[i]) - arr[i], 0)

    return water_trapped
            



# def find_trapped_water(arr, len):
#     prev = 0
#     water_volume = 0
#     valley_array = []
#     for i in range(1,len):
#         if arr[prev] <= arr[i]:
#             for j in range(prev+1,i):
#                 water_volume += arr[prev] - arr[j]
#             prev = i
#         else:
#             valley_len = len(valley_array)
#             for index in range

for i in range(test_cases):
    len = int(input())
    arr=[]
    for j in range(len):
        num = int(input())
        arr.append(num)

    print(find_trapped_water(arr, len))