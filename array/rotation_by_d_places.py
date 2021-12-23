


test_cases = int(input())


def rotate_array(arr, len, d):
	arr2=[]
	for i in range(d):
		arr2.append(arr[i])
	for i in range(len-d):
		arr[i] = arr[i+d]
	for i in range(d):
		arr[len-d+i] = arr2[i]
	return arr

for i in range(test_cases):
	len = int(input())
	d = int(input())
	arr=[]
	for j in range(len):
		num = int(input())
		arr.append(num)
	print(rotate_array(arr, len, d))
