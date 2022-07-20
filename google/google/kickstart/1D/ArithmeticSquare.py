test_cases = int(raw_input())
results = []



def calculate_count(matrix):
    temp_count = 0
    if(matrix[1][1] - matrix[1][0] == matrix[1][2] - matrix[1][1]):
        temp_count+=1
    if(matrix[1][1] - matrix[0][0] == matrix[2][2] - matrix[1][1]):
        temp_count+=1
    if(matrix[1][1] - matrix[0][1] == matrix[2][1] - matrix[1][1]):
        temp_count+=1
    if(matrix[1][1] - matrix[2][0] == matrix[0][2] - matrix[1][1]):
        temp_count+=1
    return temp_count



for t in range(test_cases):
    matrix=[]
    for row in range(3):
        line = raw_input()
        nums = line.split(" ")
        # print(nums)
        temp_arr=[]
        for col in nums:
            if(row == 1):
                temp_arr.append(int(nums[0]))
                temp_arr.append(" ")
                temp_arr.append(int(nums[1]))
                #matrix.append(temp_arr)
                break   
            else:
                temp = int(col)
            temp_arr.append(temp)
        matrix.append(temp_arr)
    # print(matrix)
    count = 0

    if(matrix[0][1] - matrix[0][0] == matrix[0][2] - matrix[0][1]):
        count+=1
        
    if(matrix[2][1] - matrix[2][0] == matrix[2][2] - matrix[2][1]):
        count+=1

    if(matrix[1][0] - matrix[0][0] == matrix[2][0] - matrix[1][0]):
        count+=1

    if(matrix[1][2] - matrix[0][2] == matrix[2][2] - matrix[1][2]):
        count+=1


    
    
    num1 = matrix[0][0] + matrix[2][2]
    num2 = matrix[2][0] + matrix[0][2]
    num3 = matrix[0][1] + matrix[2][1]
    num4 = matrix[1][0] + matrix[1][2]
    nums = [num1,num2, num3, num4]
    temp_count = 0
    for num in nums:
        if num%2 == 0: 
            num /= 2
            matrix[1][1] = num
            temp_count = max(temp_count,calculate_count(matrix))


    # if num2%2 == 0: 
    #     num2 /= 2
    # else:
    #     num2 = ""
    
    # if num3%2 == 0:
    #     num3 /=2
    # else:
    #     num3 = ""
    # if num4%2 == 0: 
    #     num4 /= 2
    # else:
    #     num4 = ""
    
    # # print(num1, num2, num3, num4)

    # temp_count = temp_count1 = temp_count2 = 0

    # if num1 != "":
    #     if num1 == num2:
    #         if num2 == num3:
    #             if num3 == num4:
    #                 temp_count=4
    #             else:
    #                 temp_count=3
    #         elif num2 == num4:
    #             temp_count=3
    #         else:
    #             temp_count=2
    #     elif num1 == num3:
    #         if num3 == num4:
    #             temp_count=3
    #         else:
    #             temp_count=2
    #     elif num1 == num4:
    #         temp_count=2
    #     else:
    #         temp_count = 1


    # if num2 == num3:
    #     if num3 == num4:
    #         temp_count1 = 3
    #     else:
    #         temp_count1 = 2

    # elif num2 == num4:
    #     temp_count1 = 2
    # else:
    #     temp_count1 = 1

    

    # if num3 == num4:
    #     temp_count2 = 2

    # else:
    #     temp_count2 = 1

    # print(temp_count, temp_count2, temp_count1)


    count += temp_count
    results.append(count)
for t in range(test_cases):
    print("Case #{}: {}".format(t+1,results[t]))

    







    

