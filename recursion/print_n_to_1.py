


test_cases = int(input())


def reverse_print(arr, index, num):
	if index == num-1:
		print(arr[index])
		return
	reverse_print(arr, index+1, num)
	print(arr[index])


for i in range(test_cases):
	number = int(input())
	arr=[]
	for j in range(number):
		num = int(input())
		arr.append(num)
	print(arr)
	reverse_print(arr, 0, number)		


