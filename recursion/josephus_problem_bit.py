

test_cases = int(input())


def josephus(number):
	num = number
	count=0
	while num ^ 1 != 0:
		#print(num)	
		num = num >> 1
		count+=1
	#print(count)
	new_number = number ^ (1<<count)
	new_number = new_number << 1
	new_number+=1
	return new_number	

	
for i in range(test_cases):
	number = int(input())
	print(josephus(number))
	
