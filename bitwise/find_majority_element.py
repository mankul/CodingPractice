

test_cases = int(input())

def find_majority(arr, num):
	len = 32 # integer length
	number = 0
	for i in range(len):
		count = 0
		for j in range(num):
			if arr[j] & 1<<i:
				count+=1
		if count > num/2:
			number+=(1<<i)
	if number:
		return number
	else:
		return -1 	


for i in range(test_cases):
	num = int(input())
	arr = []
	for j in range(num):
		number = int(input())
		arr.append(number)
	#print(arr)
	number =  find_majority(arr, num)
	count = 0
	for el in arr:
		if el == number:
			count+=1

	if count > num / 2:
		print(number)
	else:
		print("-1")
