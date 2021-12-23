

test_cases = int(input())


def josephus(number, k):
	if ( number == 1):
		return number
	num = josephus(number - 1, k)
	return (num + k-1)%number + 1 
for i in range(test_cases):
	number = int(input())
	k = int(input())
	print(josephus(number, k))
	
