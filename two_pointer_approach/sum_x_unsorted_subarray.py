


test_cases = int(input())

def find_subarray(arr, len, xsum):
	i = j = 0
	index=0
	sum = 0
	
	while  j <= len:
		print("sum is", sum)
		if j == len and sum < xsum:
			return -1
	
		if sum == xsum:
			return i, index
		elif sum > xsum:
			sum -= arr[i]
			i+=1
		else:
			sum += arr[j]
			index = j
			j+=1
			



for i in range(test_cases):
	len = int(input())
	arr=[]
	xsum = int(input())
	for i in range(len):
		num = int(input())
		arr.append(num)
		
	print(find_subarray(arr, len, xsum))
