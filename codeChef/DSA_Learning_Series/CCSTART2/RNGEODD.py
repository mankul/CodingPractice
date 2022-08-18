ran = raw_input().split(" ")
l,r = map(lambda x: int(x),ran)
output = ""
for i in range(l,r+1):
    if i % 2 != 0:
        output+="{} ".format(i)
print(output)
