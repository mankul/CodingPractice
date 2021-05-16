


test_cases = int(input())



def CR(prize_list, length, prize_dict):
	if length == 0:
		return 0
	if length not in prize_dict.keys():
		max_prize = -1
		for i in range(0,length):
			max_prize = max(max_prize, prize_list[i] + CR(prize_list, length - i - 1, prize_dict))
		prize_dict[length] = max_prize
	
	return prize_dict[length]
	
	

for i in range(test_cases):
	length = int(input())
	prize_list = []
	for i in range(length):
		#length = int(input())
		prize = int(input())
		prize_list.append(prize)
		prize_dict = {}
	
	print(CR(prize_list, length, prize_dict))
	print(prize_dict)	
