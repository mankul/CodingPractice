# 0 1 1  1 1 1 1 0 0 0 0 0 1 0 0 0 0 0  1 1 1 1 1 



def arrange(num):
    length = len(num)
    # i, j
    i = 0
    for ind in range(length):
        if(num[ind] == 0 and ind != 0):
            # swap i and ind
            temp = num[ind - 1]
            num[ind-1] = num[i]
            num[i] = temp
    return num

print(arrange([1,0,0,1]))
            