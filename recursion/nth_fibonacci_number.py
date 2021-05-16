


test_cases = int(input())


# nth fibonacci number. 


def fib_num(number1, number2, count, number):
	if number == 0 :
		return 0
	if number == 1:
		return 1
	if count<number:
		return fib_num(number2, number1 + number2,count+1 , number)
	if count == number:
		return number2
for i in range(test_cases):
	number = int(input())
	if number == 0:
		print("0")
	elif number == 1:
		print("1")
	elif number == 2:
		print("2")
	else:
		print(fib_num(1,2,3,number))
