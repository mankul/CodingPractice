from curses import keyname


T = int(input())
for t in range(T):
    N = int(input())
    colorHash = {}
    durabHash = {}
    for i in range(N):
        str = input()
        param = str.split(" ")
        color = param[0]
        dur = int(param[1])
        id = int(param[2])
        colorHash[id] = color
        durabHash[id] = dur

    colorDictNew = [k for k, v in sorted( colorHash.items() , key= lambda item: item[1])]
    durabDictNew = [k for k, v in sorted( durabHash.items() , key= lambda item: item[1])]

    print(colorDictNew)
    print(durabDictNew)
    positionCount = 0
    for i in range(N):
        if(colorDictNew[i] == durabDictNew[i]):
            positionCount += 1

    print("Case #",t,":",positionCount) 
