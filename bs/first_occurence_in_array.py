#sorted array


len = int(input())

arr = []

def first_occurence(arr, len, number):
	# iterative
	i = len-1
	while 1:
		print("iterating through index  ",i)
		if arr[i] > number:
			i /= 2
		elif arr[i] == number:
			return i
		elif arr[i] < number:
			i *=  2
		if i < 0:
			return -1
		if i >= number:
			return -1
	


number = int(input())
for i in range(len):
	# input sorted array
	num = int(input())
	arr.append(num)
index = first_occurence(arr,len, number)

if index != -1:

	while(index >= 0):
		if arr[index] != number:
			break
		index-=1
	print("index is ", index+1)
else:
	print("element not found")
