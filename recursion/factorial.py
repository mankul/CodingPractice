


test_cases = int(input())

def factorial(number):
	if(number == 0 or number == 1):
		return 1	
	else:
		return factorial(number-1) * number
for i in range(test_cases):
	number = int(input())
	print(factorial(number))

