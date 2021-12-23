


test_cases = int(input())


bit_table= [0 for i in range(256)]

for i in range(256):
	bit_table[i] = (i & 1) + bit_table[i/2]

def count_set(number):
	count = bit_table[(number & 255)] + bit_table[(number>>8 ) & 255] + bit_table[(number >> 16) & 255] + bit_table[(number >> 24) & 255]
	return count


for i in range(test_cases):
	number = int(input())
	print(count_set(number))
