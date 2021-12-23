

test_cases = int(input())


def find_triplet(arr, len, num):
	
	for index in range(len-2):
		number = num - arr[index]
		i = index+1
		j = len - 1
		while(i != j):
			if (arr[i] + arr[j]) < number:
				i+=1
				
			elif arr[i] + arr[j] == number:
				return index, i,j
			else:
				j-=1
	return -1


for i in range(test_cases):
	len = int(input())
	number = int(input())
	arr=[]
	for j in range(len):
		num = int(input())
		arr.append(num)
	print(find_triplet(arr, len, number))
