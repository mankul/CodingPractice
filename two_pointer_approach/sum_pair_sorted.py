

test_cases = int(input())


def find_pair(arr, len, number):
	i = 0
	j = len - 1
	while(i != j):
		if (arr[i] + arr[j]) < number:
			i+=1
			
		elif arr[i] + arr[j] == number:
			return i,j
		else:
			j-=1
	if i == j:
		return -1


for i in range(test_cases):
	len = int(input())
	number = int(input())
	arr=[]
	for j in range(len):
		num = int(input())
		arr.append(num)
	print(find_pair(arr, len, number))
