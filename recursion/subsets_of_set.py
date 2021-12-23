


test_cases = int(input())

def all_subsets(set_el):
	if len(set_el == 1):
		return [[],set_el]

	
	new_set_el = set_el[:-1]
	



def subsets(set_el):
	if len(set_el) == 1 :
		return [set_el]
	new_set_el = set_el[:-1][:]
	#print("recursion call set is ",new_set_el)
	el = set_el[-1]
	power_subsets = subsets(new_set_el)
	#print("power sets are ",power_subsets)
	new_subsets = []#power_subsets[:]
	#print(power_subsets)
	for subset in power_subsets:
		new_subset = subset[:]
		#print("subset is ", subset, el)
		new_subset.append(el)
		new_subsets.append(new_subset)
	#print("new subsets are ",new_subsets, power_subsets)
	power_subsets = power_subsets + new_subsets
	power_subsets.append([el])
	print(" total subsets are ",power_subsets) 
	return power_subsets
		
	

for i in range(test_cases):
	number = int(input())
	set_el=[]
	for i in range(number):
		el = raw_input()
		set_el.append(el)
	subset = subsets(set_el)
	subset.append([])
	print(subset)
