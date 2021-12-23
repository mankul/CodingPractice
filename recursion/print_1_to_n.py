


test_cases = int(input())

def print_1ton(number):
	if number == 1:
		print(number)
		return
	print_1ton(number-1)
	print(number)

for i in range(test_cases):
	number = int(input())
	print_1ton(number)
