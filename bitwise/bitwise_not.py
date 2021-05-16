

test_cases = int(input())


def bitwise_not(number1):
	num = ~number1
	return num


for i in range(test_cases):
	number1 = int(input())

	print(bitwise_not(number1))
