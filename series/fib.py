#fib series
mem={}

def fib(n):
    if(n==0):
        mem[0] = 0
        return mem[0]
    if(n == 1):
        mem[1] = 1
        return mem[1]

    if(n not in mem.keys()):
        mem[n] = fib(n-1) + fib(n-2)
    return mem[n]
while(1):
    num = int(input())
    print(fib(num))
