


test_cases = int(input())

def find_index(number, start, end):
	if start == end:
		if number != pow(start,2):
			return -1
		else:
			return start

	square = pow(start,2)
	print(square, "square")
	if square == number:
		return start
	

	mid = (start + end)/2
	square = pow(mid,2)
	
	if square == number:
		return mid
	elif square < number:
		return find_index(number, mid+1, end)
	else:
		return find_index(number, start, mid)


def find_square(number, index):
	square = pow(index,2)
	print("square" , square)
	if square == number:
		return index
	elif square < number:
		return find_square(number, index*2)
		
	else:
		return find_index(number, index/2+1, index)
		

for i in range(test_cases):
	number = int(input())
	if number == 0:
		print("0")
	else:
		index = 1
		
		print(find_square(number, index))
		
