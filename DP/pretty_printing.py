


# Cost is the difference of indices + 1

def findAlignment(n, optimalDictionary, costList, L):
    if n == 0:
        optimalDictionary[n] = 0
        return
    if n == 1:
        optimalDictionary[n] = costList[n-1]
        return

    minSlack = 10000000000
    for i in range(1,n):
        if i not in optimalDictionary.keys():
            findAlignment(i, optimalDictionary, costList, L)
        slack = optimalDictionary[i]
        costSum = sum(costList[i-1:n-1]) + (n-i-1) + costList[n-1]
        if minSlack > slack + (L - costSum):
            minSlack = slack + (L - costSum)
    
    optimalDictionary[n] = minSlack


print("enter L")
L = input()
print("number of words")
n = input()
print("enter the cost/size of n words seperated by space")
costList = raw_input().split(" ")
costList = map(lambda x: int(x), costList)
optimalDictionary = {}

findAlignment(n, optimalDictionary, costList)
print(optimalDictionary[n])



