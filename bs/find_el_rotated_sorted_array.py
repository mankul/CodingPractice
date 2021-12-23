
# array sorted in increasing order. and rotated

test_cases = int(input())

# 4 5 6 7 8 1 2 3 4 4 


def find_number(arr, number, start, end):
	if arr[start] == number:
		return start
	if start == end:
		if arr[start] != number:
			return -1
		else:
			return start

	mid = (start + end)/2
	if arr[mid] < number:
		if arr[start] < number:
			if arr[start] < arr[mid]:
				return find_number(arr, number, mid+1, end)
			
			elif arr[start] > arr[mid]:
				return find_number(arr, number, start, mid-1)
			else:
				return find_number(arr, number, mid+1, end)
				
		elif arr[start] > number:	
			return find_number(arr, number, mid+1 , end)
		else:
			return start
	elif arr[mid] == number:
		return mid
	else:
		if arr[start] > number:
			return find_number(arr, number, mid+1, end)
		elif arr[start] == number:
			return start
		else:
			return find_number(arr, number, start, mid-1)
for i in range(test_cases):
	len = int(input())
	arr= []
	number = int(input())
	for j in range(len):
		num = int(input())
		arr.append(num)
	print(find_number(arr, number, 0 , len-1))
		
