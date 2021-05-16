


test_cases = int(input())



def sum_of_digits(number):
	if number < 10:
		return number
	else:
		num = number % 10
		number = number / 10
		return num + sum_of_digits(number)	

	
for i in range(test_cases):
	number = int(input())
	print(sum_of_digits(number))
		
