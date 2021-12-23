


test_cases = input()

def find_count(num):
    G=num
    n=1
    count=0
    while (n*n - n) < 2*G:
        sum = G - n*(n-1)/2
        if sum%n == 0:
            count+=1
        n+=1
    return count
        


for i in range(test_cases):
    num = input()
    count=find_count(num)
    print("Case #{}: {}").format(i+1,count)