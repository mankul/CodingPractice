num = input()
if(num%5== 0 and num %11 == 0):
    print("BOTH")
elif(num%5 == 0 or num%11 == 0):
    print("ONE")
else:
    print("NONE")
