
test_cases = int(raw_input())

def lcm(number1, number2):
	return (number1*number2)/gcd(number1, number2)


def gcd(number1, number2):
	if number1 == 1 or number2 == 1:
		return 1
	if number1 > number2:
		if number1%number2 != 0:
			return gcd(number1-number2, number2)
		else:
			return number2
	else:
		if number2%number1 != 0:
			return gcd(number2-number1, number1)
		else:
			return number1

for i in range(test_cases):
	number1 = int(raw_input())
	number2 = int(raw_input())
	print(lcm(number1, number2))

