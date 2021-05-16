# array is increasing then decreasing
# to find peak element

test_cases = int(input())

def peak_element(arr, start, end):
	if start == end:
		return start
	mid = (start + end)/2
	
	if arr[mid] > arr[start]:
		if arr[mid] > arr[mid+1]:
			if arr[mid-1] < arr[mid]:	
				return mid
			elif arr[mid-1] >= arr[mid]:
				return peak_element(arr, start, mid)		
		elif arr[mid] <= arr[mid+1]:
			if arr[mid-1] < arr[mid]:
				return peak_element(arr,mid,end)
		
	elif arr[mid] < arr[start]:
		return peak_element(arr, start,mid)
	


for i in range(test_cases):
	len =int(input())
	arr=[]
	for j in range(len):
		num = int(input())
		arr.append(num)
	print(peak_element(arr, 0 ,len-1))
