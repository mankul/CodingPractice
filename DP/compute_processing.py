
def computeProcessing(n, OPT, S, X, OPTReboot):
    if n == 0:
        if n not in OPT.keys():
            OPT[n] = 0
        return
    if n == 1:
        if n not in OPT.keys():
            OPT[n] = min(S[1], X[1])
            OPTReboot[n] = 0
        return
    maxOpt = 0
    for i in range(n):
        maxOpt += min(S[i], X[i])
        
    rebootIndex = -1
    for i in range(n):
        if i not in OPT.keys():
            computeProcessing(i, OPT, S, X, OPTReboot)
        opt = OPT[i]
        processing = 0
        for j in range(i+2, n):
            process = min(S[j-i-2], X[j-1])
            processing+= process
        if maxOpt < opt + processing:
            maxOpt = opt + processing
            rebootIndex = i

    OPT[n] = maxOpt
    OPTReboot[n] = rebootIndex + 1

print("enter number of processes")
n = input()
print("enter the processing requirement at day i with spaces")
X = raw_input().split(" ")
X = map(lambda x: int(x), X)
print("enter the processing power at day i with spaces")
S = raw_input().split(" ")
S = map(lambda x: int(x), S)
OPT = {}
OPTReboot = {}
computeProcessing(n, OPT, S, X, OPTReboot)
print("reboots are ",OPTReboot[n])
print("max processing are ",OPT[n])