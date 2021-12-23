
test_cases = int(input())
for i in range(test_cases):
	number = int(input())
	digits=[]
	if(number == 0):
		digits.append(0)
		
	else:
		while(number>0):
			dig = number%10
			number = number/10
			digits.append(dig)
	
	print(digits)

