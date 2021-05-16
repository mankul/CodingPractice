
# cant make direct disk transfer between disc A and disc C

test_cases = int(input())



def tower_of_hanoi(number, a, b, c , direction):
	if number == 1:
		
		print("move ", number," ", a, " to ", b )
		print("move ", number," ", b, " to ", c)
		return 
	#print(number)
	tower_of_hanoi(number - 1, a , b , c , 1)
	
	print("move ", number," ", a, " to ", b )

	tower_of_hanoi(number - 1, c, b , a ,  0)

	print("move ", number," ", b, " to ", c)

	tower_of_hanoi(number-1 , a , b, c , 1)


for i in range(test_cases):
	number = int(input())
	a = "A"
	b = "B"
	c = "C" 
	tower_of_hanoi(number, a, b, c,  1)
