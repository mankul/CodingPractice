num=int(input())

i = 2
factors = []
while i <= num:
    if num%i == 0:    
        factors.append(i)
    i+=1
    
output = "1 "
for factor in factors:
    output = output+"{} ".format(factor)
print(len(factors)+1)
print(output)

