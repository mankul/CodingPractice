


test_cases = int(input())


def tower_of_hanoi(number,a , b, c):
	if number == 1:	
		print("move ", number," ", a, " to ", b)
		print("move ", number," ", b, " to ", c)
		return

	tower_of_hanoi(number - 1, a, b, c)
	print("move ", number," ", a, " to ", b)
	tower_of_hanoi(number - 1, c, b, a)
	print("move ", number," ", b, " to ", c)
	tower_of_hanoi(number - 1, a, b, c)




for i in range(test_cases):
	number = int(input())
	tower_of_hanoi(number, "a", "b","c")
