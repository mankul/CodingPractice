

sum = input()


# counts = {}

# counts[1] = 0
# counts[3] = 0
# counts[4] = 0

# d is [n:[[1:x,3:y,4:z], count]]
d = {}

    if n < 0:
def func(n 3 in d.keys():
        if counts_dict[1] == d[n-1][0][1] and counts_dict[3] == d[n-1][0][3] and counts_dict[4] == d[n-1][0][4]:
            d3 = d[n-3][1]
    else:
        count_copy = counts_dict.copy()
        count_copy[3]+=1
        d3 = func(n-3, counts_copy)

    if n - 4 in d.keys():
        if counts_dict[1] == d[n-1][0][1] and counts_dict[3] == d[n-1][0][3] and counts_dict[4] == d[n-1][0][4]:
            d4 = d[n-4][1]
    else:
        count_copy = counts_dict.copy()
        count_copy[1]+=1
        d4 = func(n-1, counts_copy)

    
    return (d1 + d3 + d4)


    

    



