

def max_processing(n, OPT, processor ,A, B):
    if n == 0:
        if (n, processor) not in OPT.keys():
            OPT[(n,processor)] = 0
        return
    if n == 1:
        if processor == 0: #A
            OPT[(n,processor)] = A[n-1]
        else:
            OPT[(n,processor)] = B[n-1]
        return
    if (n,processor) not in OPT.keys():
        max_processing(n-1, OPT, processor, A, B)
        max_processing(n-2, OPT, 1-processor, A, B)
        maxA = max( OPT[(n-1,processor)], OPT[(n-2, 1-processor)]) 
        if processor == 0:
            OPT[(n,processor)] = maxA + A[n-1]
        else:
            OPT[(n,processor)] = maxA + B[n-1]
        # print("current calculated value is ", OPT[(n, processor)])


print("enter number of processes")
n = input()
print("enter A and B for {} minutes respectively".format(n))
print("enter A seperated with spaces")
A = raw_input().split(" ")
A = map( lambda x: int(x), A)

print("enter B seperated with spaces")
B = raw_input().split(" ")
B = map( lambda x: int(x), B)
OPT = {}
max_processing(n, OPT, 0, A, B)
max_processing(n, OPT, 1, A, B)
# print(OPT[(n,0)])
maxA = max( OPT[(n,0)], OPT[(n,1)])
print("maximum processing can be is {}  ".format(maxA))


