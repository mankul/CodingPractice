


test_cases = int(input())


def find_two_odd_counting_in_arr(arr):
	xor2=0
	for el in arr:
		xor2 = xor2 ^ el
	num = xor2
	position = 0
	while num & 1 != 1:
		position+=1
		num = num >> 1
	new_num = 1 << position
	num = 0
	for el in arr:
		print(el)
		if (el & new_num) != 0:
			num = num ^ el
	num2 = xor2 ^ num
	return num, num2		


for i in range(test_cases):
	arr_size = int(input())
	arr=[]
	for i in range(arr_size):
		num = int(input())
		arr.append(num)
	print(find_two_odd_counting_in_arr(arr))

