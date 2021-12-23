


test_cases = int(input())

def check_kth_bit(number, k):
	num = 1 << k-1

	num = num & number
	if num == 0:
		return "bit not set"
	else:
		return "bit is set"

for i in range(test_cases):
	number = int(input())
	k = int(input())
	print(check_kth_bit(number, k))
