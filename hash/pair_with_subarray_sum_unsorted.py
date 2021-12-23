# 1 2 3 4 45 34 32 22 34 -23 -43 -33 -1 3 34 


test_cases = input()


for t in range(test_cases):
    n=input()
    sum = input()
    arr=[]
    sum_upto = 0
    sum_map = {}
    for i in range(n):
        num=input()
        arr.append(num)
        sum_upto+=num
        sum_map[sum_upto] = i
    total_sum=0

    for sum_to in sum_map.keys():
        if sum_to == sum:
            total_sum = 2
            break

        rest_sum = sum + sum_to

        if rest_sum in sum_map.keys():
            total_sum=1
            break

    if total_sum ==  0:
        print("no subarray sum found")
    elif total_sum == 2:
        print("0",sum_map[sum])
    else:
        print(sum_map[sum], sum_map[rest_sum])



    