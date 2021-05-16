


test_cases = int(input())

def generate_power_set( arr):
	size = len(arr)
	pow_set=[]
	pow_size = pow(2,size)
	for i in range(pow_size):
		temp_set=[]
		for j in range(size):
			if i & (1<<j):
				temp_set.append(arr[j])
		pow_set.append(temp_set)
	return pow_set
					


for i in range(test_cases):
	size = int(input())
	arr = []
	for i in range(size):
		num = int(input())
		arr.append(num)
	print(generate_power_set(arr))
