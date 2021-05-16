

test_cases = int(input())


def bitwise_and(number1, number2):
	num = number1 & number2
	return num


for i in range(test_cases):
	number1 = int(input())
	number2 = int(input())

	print(bitwise_and(number1, number2))
