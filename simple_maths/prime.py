


test_cases = int(raw_input())

def prime(number , num):

	if num > number/2:
		return -1
	if number%num == 0:
		return 1
	else:
		return prime(number, num+2)
	
	
	

for i in range(test_cases):
	number = int(input())
	if number % 2 == 0:
		print 1
	else:
		print(prime(number,3))
