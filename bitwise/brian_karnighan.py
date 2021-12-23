


test_cases = int(input())

def count_set_digits(number):
	count = 0
	while number != 0:
		count+=1
		number = number & (number-1)
	return count
for i in range(test_cases):
	number = int(input())
	print(count_set_digits(number))
