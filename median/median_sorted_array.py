# find median of two sorted arrays


# solution is to get the median inplace and finding median in the sorted array

test_cases = int(input())


def find_median(arr1, arr2, len1, len2):
	i = j = 0
	len = len1 + len2
	med = -1
	print("median is",med)
	while i < len1 or j < len2:
		print(i,j,med)
		if (i + j) == med :
			if len % 2 == 1:
				return max(arr1[i], arr2[j])
			else:
				return arr1[i], arr2[j]
		if  i < len1 and j < len2:
			if arr1[i] < arr2[j]:
				i+=1
			else:
				j+=1
		elif i < len1 and j == len2-1:
			i+=1
		elif j < len2 and i == len1-1:
			j+=1
		else:
			break
	return -1

for i in range(test_cases):
	arr1 = []
	arr2 = []
	len1 = int(input())
	len2 = int(input())

	for i in range(len1):
		num = int(input())
		arr1.append(num)
	for i in range(len2):
		num = int(input())
		arr2.append(num)

	print(find_median(arr1, arr2, len1, len2))
