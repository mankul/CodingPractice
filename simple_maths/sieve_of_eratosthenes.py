


test_cases = int(input())


def find_primes(number):
	array = []
	for i in range(1,number):
		array.append(i+1)
	#print(array)
	for i in range(number-2):
		j = i
		if array[j] == 0:
			continue
		j+=array[i]
		while  j < number-1:
			array[j]=0
			j+= array[i]
			
	return array
	



for i in range(test_cases):
	# enter maximum number to find the list of eratosthenes numbers using sieve
	number = int(input())
	prime_numbers = find_primes(number)
	print(prime_numbers)
