

# posssible solution
# take two loops and count the occurrences of each element, naive , TC o(n2)

# sort the array and do one loop to check TC o(nlogn + n)
 
# use hash, hash each element and store the count TC (n) SC (n)

# best solution bitwise XOR, Because XOR is commutative

test_cases = int(input())


def odd_occurence( arr ):
	num = 0
	for elem in arr:
		num = num ^ elem
	return num		

for i in range(test_cases):
	n = int(input())
	arr = []
	for i in range(n):
		num = int(input())
		arr.append(num)
	print(odd_occurence(arr))
