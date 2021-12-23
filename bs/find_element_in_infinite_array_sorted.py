

test_cases = int(input())

arr=[]

for i in range(1024):
	arr.append(i)
# array is a huge array


def find_number_in(arr, start, end, number):
	if start == end:
		if arr[start] != number:
			return -1
		else:
			return start
	mid = (start + end)/2
	
	if arr[mid] < number:
		return find_number_in(arr,mid+1, end,number)
	elif arr[mid] > number:
		return find_number_in(arr, start, mid-1, number)
	else:
		return mid
		

def find_number(arr,index, number):
	if index > 1000:
		return
	print(index)
	if arr[index] == number:
		return index
	
	if arr[index] > number:
		new_index = (index + index/2)/2
		return find_number(arr, new_index, number)
	elif arr[index] < number:
		new_index = 2*index
		return find_number_in(arr, index, new_index, number)
	else:
		return index
		

for i in range(test_cases):

	number = int(input())
	if arr[0] == number:
		print("0")
	else:
		print(find_number(arr, 1, number))
