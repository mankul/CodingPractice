sum = input()


num = [1,3,4]

d = {}

def func(n):
    if n == 0 or n == 1 or n == 2:
        return 1
    elif n == 3:
        return 2
    
    if (n-1) not in d.keys():
        d1 = func(n-1)
    else:
        d1 = d[n-1]
    if (n-3) not in d.keys():
        d3 = func(n-3) 
    else:
        d3 = d[n-3]
    if (n-4) not in d.keys():
        d4 = func(n-4)

    else:
        d4 = d[n-4]

    return (d1+d3+d4)


print(func(sum))