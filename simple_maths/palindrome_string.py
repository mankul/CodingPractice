


test_cases = int(input())




def palindrome_string(name):
	length = len(name)
	for i in range(length/2):
		if name[i] != name[length-1-i]:
			print("Not a Palindrome")
			return
	print("Palindrome")

for i in range(test_cases):
	name = raw_input()
	palindrome_string(name)

