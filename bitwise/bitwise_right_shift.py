

test_cases = int(input())


def bitwise_right_shift(number1, shift):
	num = number1>>shift
	return num


for i in range(test_cases):
	number1 = int(input())
	shift = int(input())
	print(bitwise_right_shift(number1, shift))
