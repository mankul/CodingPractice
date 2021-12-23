# maximum consecutive ones

test_cases = int(input())

def max_cons_ones(arr):
    # left_index = right_index = 0
    sum = 0
    max_sum = 0

    for el in arr:
        print(max_sum, sum)
        if el == 1:
            sum+=1
        else:
            if sum > max_sum:
                max_sum = sum
                sum = 0
    if sum > max_sum:
        max_sum = sum
    return max_sum


    # temp_left_index = temp_right_index = 0

    # for i in range(len):

    #     if (arr[i] == 1):
    #         # temp_right_index += 1
    #         sum+=1
    #     else:
    #         if sum>0:
    #             print(sum)
    #             if max_sum < sum:
    #                 # left_index = temp_left_index
    #                 # right_index = temp_right_index
    #                 max_sum = sum
    #             sum = 0


            
    #         # temp_left_index = i+1
    #         # temp_right_index = i
    # return max_sum



for i in range(test_cases):
    len = int(input())
    arr=[]
    for j in range(len):
        num = int(input())
        arr.append(num)
    print(max_cons_ones(arr))