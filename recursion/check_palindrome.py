


test_cases = int(input())


def check_palindrome( inp):
	print(inp)
	print(len(inp))
	if(len(inp) == 1 or len(inp) == 0):
		return "yes"
	if ( inp[0] != inp[-1]):
		return "no"
	return check_palindrome(inp[1:-1])
	


for i in range(test_cases):
	inp = raw_input()
	print(check_palindrome(inp))
