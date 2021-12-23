# if there exists a combination of numbers, which will result in sum with unlimited number of numbers being present






def cansum(sum, numbers, memo = {}):
    if sum in memo.keys():
        return memo[sum]
    for num in numbers:
        res = cansum(sum-num, numbers, memo)
        if res == True:
            memo[sum] = True
            return True
    memo[sum] = False
    return False
        


test_cases = input()


for t in range(test_cases):
    sum = input()
    n = input()
    numbers = []
    for i in range(n):
        num = input()
        numbers.append(num)

    print(cansum(sum, numbers))

