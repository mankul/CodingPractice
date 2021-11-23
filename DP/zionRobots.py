
# eva tardos exercise 8
def robotsDestruction(n, Optimum, X, f):
    if n == 0:
        Optimum[0] = 0
        return
    if n == 1:
        if n not in Optimum.keys():
            Optimum[n] = min(X[0], f[0])
        return
    maxOpt = -1
    m = n-1
    while m >= 0:
        if m not in Optimum.keys():
            robotsDestruction(m,Optimum, X, f)
        opt = Optimum[m]
        robotsKilled = min(X[n-1], f[n-m-1])
        if maxOpt < (opt + robotsKilled):
            maxOpt = opt + robotsKilled
        # print(n, m, opt, maxOpt)
        m-=1
    # print(n, maxOpt)
    print(Optimum)
    Optimum[n] = maxOpt

print("input number of iteration of robots coming")
n = input()
print("enter n robots count at each iteration visit, seperate with space")
X = raw_input().split(" ")
X = map(lambda x: int(x), X)
print("enter the EMP radiation as function of i, seperate by space")
f = raw_input().split(" ")
f = map(lambda x: int(x), f)
optimum = {}
print(X, f)
robotsDestruction(n, optimum, X, f)
print("{}".format(optimum[n]))