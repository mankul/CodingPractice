a=int(input())
b=int(input())
c=int(input())

if a>b and a>c:
    if b>c:
        print(b)
    else:
        print(c)
elif a<b and a<c:
    if b>c:
        print(c)
    else:
        print(b)
else:
    print(a)


    
