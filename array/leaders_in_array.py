


test_cases = int(input())


def find_leaders(arr, len):
	i = len-1	
	leader = arr[i]
	leaders = [leader]
	i-=1
	while i >= 0:
		if arr[i] > leader:
			leader = arr[i]
			leaders.append(leader)
		i-=1
		
	return leaders

for i in range(test_cases):
	len = int(input())
	arr = []
	for i in range(len):
		num = int(input())
		arr.append(num)
	print(find_leaders(arr, len))
