


test_cases = int(input())

def find_next_factor(number, factor, factor_list):

	while(factor< number):
		factorFound=0
		for num in factor_list:
			if factor % num == 0:
				factorFound=1
				break
		if factorFound == 1:
			factor+=1
			continue
		else:
			return factor
	if factor == number:
		return factor

	elif factor > number:
		return -1	
		
	
	
				
def check_prime(number):
	num = 2
	is_prime = True
	while(num < number):
		if number % num == 0:
			is_prime=False
			break	
		num+=1
	return is_prime

def prime_factors(number, factor, factor_list):
	if number % factor == 0:
		number = number/factor
		if check_prime(number):
			if number not in factor_list:
				factor_list.append(factor)
		next_factor = find_next_factor( number, factor+1, factor_list)
		prime_factors(number, next_factor, factor_list)
	else:
		new_factor = find_next_factor(number, factor+1 , factor_list)
		if new_factor != -1:
			prime_factors(number, new_factor, factor_list)
		


def find_factor(factor, factor_list):
	is_factor = True
	for num in factor_list:
		if factor % num == 0:
			is_factor = False
			factor+= 1
			break
	if is_factor == False:
		factor = find_factor(factor, factor_list)
	return factor

def find_all_prime_factors(number, factor, factor_list):

	if number == 2:
		factor_list.append(number)
		return factor_list

	
	if number % factor == 0:
		# its a factor
		if check_prime(factor) and factor not in factor_list:
			while(number % factor == 0):
				number/=factor
			factor_list.append(factor)
	factor+=1
	factor=find_factor(factor, factor_list)
	print(factor)
	if factor > number:	
		return factor_list
	return find_all_prime_factors(number, factor, factor_list)

for i in range(test_cases):
	number = int(input())
	factor_list = []
	factor = 2
	#prima_factors(number, factor, factor_list)
	factor_list = find_all_prime_factors(number, factor, factor_list)

	print(factor_list)
