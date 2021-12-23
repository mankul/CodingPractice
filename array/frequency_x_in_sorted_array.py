


test_cases = int(input())



def find_frequency(arr, x, start, end):
	if start == end:
		if x != arr[start]:
			return -1
		else:
			return start


	mid = (start + end)/2
	if x > arr[mid]:
		return find_frequency(arr, x, mid+1, end)
	elif x < arr[mid]:
		return find_frequency(arr, x, start, mid-1)
	else:
		return mid
		
		

for i in range(test_cases):
	len = int(input())
	x = int(input())
	arr = []	
	for i in range(len):
		num = int(input())
		arr.append(num)
	print(find_frequency(arr,x,0, len-1))
