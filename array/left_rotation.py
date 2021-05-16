


test_cases = int(input())


def left_rotation(arr , len):
	temp = arr[0]
	for i in range(len-1):
		arr[i] = arr[i+1]
	arr[len-1] = temp
	return arr


for i in range(test_cases):
	len = int(input())
	arr = []
	for j in range(len):
		num = int(input())
		arr.append(num)
	print(left_rotation(arr,len))
