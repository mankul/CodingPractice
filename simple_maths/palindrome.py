
#palindrome
test_case = int(input())




def palindrome_function(number):
	palindrome = []
	count=0
	if number == 0:
		count=1
		print("palindrome\n")
		
	else:
		while(number>0):
			digit = number%10
			number = number/10
			palindrome.append(digit)
			count+=1
		for i in range(count/2):
			if palindrome[i]!=palindrome[count-i-1]:
				print("not a palindorme\n")	
				return
		print("palindrome\n")

for i in range(test_case):
	number = int(input())
	palindrome_function(number)
