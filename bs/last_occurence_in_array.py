



def last_occurence(arr, len, number):
	index = len-1
	while 1:
		if arr[index] == number:
			return index
		elif arr[index] > number:
			index /= 2
		elif arr[index] < number:
			index *= 2
		if index < 0:
			return -1
		elif index >= number:
			return -1


len = int(input())
number = int(input())
arr=[]
for i in range(len):
	num = int(input())
	arr.append(num)
index = last_occurence(arr, len, number)	
if index != -1:
	while index < len :
		if arr[index] != number:
			break
		index+=1
	print("index is ", index-1)
else:
	print("element not found")


