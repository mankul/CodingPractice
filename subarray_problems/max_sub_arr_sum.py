# given an array of positive and negative integers. get the sub array with maximum sum.

# -3,4,-5,4,-7

def max_sub_arr(arr):
    sum_ = 0
    max_sum = 0
    len_arr = len(arr)
    for i in range(len_arr):
        sum_ += arr[i]
        if sum_ > max_sum:
            max_sum = sum_
        elif sum_ < 0:
            sum_ = 0

    return max_sum


def max_sub_arr_with_index(arr):
    sum_ = 0
    max_sum=0
    max_left_index = 0
    max_right_index = 0
    left = 0
    arr_len = len(arr)
    for i in range(0,arr_len):
        sum_ += arr[i]
        if sum_ >= max_sum:
            max_sum = sum_
            max_right_index = i
            if max_left_index < left:
                max_left_index = left
        elif sum_ < 0:
            left = i + 1
            sum_ = 0
    return max_left_index, max_right_index, max_sum


def main():
    arr1 = [-1,-2,3,4,5,-9,19]
    arr2 = [-1,-2,3,4,5,-9,-19,29]
    print(arr1," : ",max_sub_arr(arr1))
    print(arr2," : ",max_sub_arr(arr2))

    print(arr1," : ",max_sub_arr_with_index(arr1))
    print(arr2," : ",max_sub_arr_with_index(arr2))

if __name__ == "__main__":
    main()
