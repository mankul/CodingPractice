


test_cases = int(input())




def tower_of_hanoi(number, a, b, c, d):
	if number == 1:
		print("move ", number," ", a, " to ", d)
		return
	
	if number == 2:
		print("move ", number-1," ", a, " to ", b)
		print("move ", number," ", a, " to ", d)
		print("move ", number-1," ", b, " to ", d)
		return
	if number == 3:
		print("move ", number-2," ", a, " to ", b)
		print("move ", number-1," ", a, " to ", c)
		print("move ", number," ", a, " to ", d)
		print("move ", number-1," ", c, " to ", d)
		print("move ", number," ", b, " to ", d)
		return

	tower_of_hanoi(number - 2, a, c, d, b)

	
	print("move ", number-1," ", a, " to ", c)
	print("move ", number," ", a, " to ", d)
	print("move ", number-1," ", c, " to ", d)
	
	tower_of_hanoi(number - 2, b, a, c, d)

for i in range(test_cases):
	number = int(input())
	tower_of_hanoi(number, "a", "b", "c", "d")
	
