


test_cases = int(input())

def check_sorted(arr, len):
	for i in range(len-1):
		if arr[i] > arr[i+1]:
			return -1
	return 1

for i in range(test_cases):
	len = int(input())
	arr = []
	for j in range(len):
		num = int(input())
		arr.append(num)
	print(check_sorted(arr,len))
