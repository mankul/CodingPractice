

test_cases = int(input())


def find_pair(arr, len, number):
	
	for i in range(len):
		for j in range(len):
			num = arr[i] + arr[j]
			print(num, number)
			if num == number:	
				return i, j
	return -1

for i in range(test_cases):
	len = int(input())
	num = int(input())
	arr=[]
	for j in range(len):
		number = int(input())
		arr.append(number)
	print(find_pair(arr,len, num))
