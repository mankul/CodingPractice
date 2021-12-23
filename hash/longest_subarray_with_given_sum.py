
# only case left is 0

test_cases = input()


for i in range(test_cases):
    n=input()
    sum=input()
    arr=[]
    sum_=0
    # dict={}
    diff=0
    for j in range(n):
        num = input()
        sum_+=num
        arr.append(sum_)


    sum_index = 0
    diff_index = 0
    close_index = 0
    for j in range(n):
        if arr[j]==sum:
            if sum_index < j:
                sum_index = j
        else:
            rest_sum = arr[j] - sum
            if rest_sum in arr:
                if diff_index < i:
                    


        # if sum_ in dict.keys():
        #     if diff<i:
        #         diff=i
        #         dict[sum_] = i
        # dict[sum_] = i

    for j in range(n):
