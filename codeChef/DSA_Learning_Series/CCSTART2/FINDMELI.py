line = raw_input().split(" ")
N=int(line[0])
K=int(line[1])
numbers = raw_input().split(" ")
get=-1
numbers = list(map(lambda x: int(x), numbers))
for num in numbers:
    if num == K:
        get = 1
        break
print(get)    