


test_cases = int(input())


def gcd(number1, number2):

	if number1 == 1:
		return number1
	if number2 == 1:
		return number2
	if number1>number2 :
		if number1%number2 != 0:
			return gcd(number2, number1-number2)
		else:
			return number2
	else:
		if number2%number1 != 0:
			return gcd(number1, number2-number1)
		else:
			return number1
		



for i in range(test_cases):
	number1 = int(input())
	number2 = int(input())

	print(gcd(number1, number2))




