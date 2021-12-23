
test_cases = int(input())

# recursion
def count_occurence(arr, len, index , number):
	if arr[index] == number:
		return index
	elif arr[index] > number:
		index/= 2
	elif arr[index] < number :
		index *= 2
	if index >= len:
		return -1
	if index <= 0 and arr[index] != number:
		return -1
	return count_occurence(arr,len,index, number)

def left_element_index(arr, index, number):
	while index >= 0:
		if arr[index] != number:
			break
		index-=1
	return index+1


def last_element_index(arr, index, number, len):
	while index < len:
		if arr[index] != number:
			break
		index+=1
	return index-1

for i in range(test_cases):
	len = int(input())
	arr=[]
	number = int(input())
	for j in range(len):
		num = int(input())
		arr.append(num)
	index = count_occurence(arr,len, len - 1, number)
	if index != -1:
		first_index = left_element_index(arr, index, number)
		last_index = last_element_index(arr, index, number, len)
		print(first_index," ", last_index)
	else:
		print("element not found")
	

