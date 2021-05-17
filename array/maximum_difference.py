


test_cases = int(input())


def maximum_difference(arr, len):
	# difference is max between smallest and maximum element
	# condition : larger number appears after smaller problem

	max = min = temp_min = 0
	
	for i in range(1,len):
		el = arr[i]

		if arr[i] - arr[min] > arr[max] - arr[min]:	
			max = i


		if arr[i] < arr[min]:
			temp_min = i
		
		if arr[i] - arr[temp_min] > arr[max] - arr[min]:
			min = temp_min 
			max = i
		# elif arr[i] -  arr[temp_min] > arr[i] - arr[min]:
			


	return arr[max] - arr[min]

for i in range(test_cases):
	len = int(input())
	arr=[]
	for i in range(len):
		num = int(input())
		arr.append(num)
	print(maximum_difference(arr,len))	
