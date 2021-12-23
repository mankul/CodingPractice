


test_cases = int(input())

def check_power_of_2(number):
	count=0
	while number != 0:
		if number & 1 != 0:
			if count > 0:
				count+=1	
				break
			else:
				count+=1
		number = number >> 1
	if count == 1:
		return True
	else:
		return False
for i in range(test_cases):
	number = int(input())
	print(check_power_of_2(number))
	
