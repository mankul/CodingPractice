


test_cases = int(input())



def factorial_number(number):
	if number == 0 or number == 1:
		return 1
	return number * factorial_number(number-1)



for i in range(test_cases):
	number = int(input())
	print(factorial_number(number))
