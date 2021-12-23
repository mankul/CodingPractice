
# array of sorted 0s and ones
test_cases = int(input())


def find_left_index(arr,  start, end):
	
	if start == end :
		if arr[start] != 1:
			return -1
		else:
			return start
			
	mid = (start + end)/2
	print("mid is ", mid)
	if arr[mid] == 1:
		if arr[mid-1] == 0:
			return mid
		return find_left_index(arr,start, mid)
	else:
		if arr[mid+1] == 1:
			return mid+1
		return find_left_index(arr,mid + 1,end)


## why would i nedd to find the right index. its a sorted array
def find_right_index(arr, start, end):
	if start == end:
		if arr[start] != 1:
			return -1
	mid = (start + end) / 2
	
	if arr[mid] == 1:
		find_right_index(arr, mid , end)
	else:
		find_right_index(arr, start, mid)
		


for i in range(test_cases):
	len = int(input())
	arr = []
	for j in range(len):
		num = int(input())
		arr.append(num)
	left_index = find_left_index(arr,0,len-1)
	print(left_index)
