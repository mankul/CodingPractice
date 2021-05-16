


test_cases = int(input())


def tower_of_hanoi(number, a , b, c):
	if(number == 0):
		return
	tower_of_hanoi(number-1, a, c, b)
	print("Move Disk " , number , " from ", a," to ", c)
	tower_of_hanoi(number-1, b, a, c)



for i in range(test_cases):
	number = int(input())
	a = "A"
	b = "B"
	c = "C"
	tower_of_hanoi(number, a, b, c)
