




test_cases = int(input())



for t in range(test_cases):
	xa = input()
	xb = input()
	Xa = input()
	Xb = input()

	
	if Xa < xa:
		sa = 1
	elif Xa%xa != 0:
		sa = Xa/xa + 1
	else:
		sa = Xa/xa
	
	if Xb < xb:
		sb = 1
	elif Xb%xb != 0:
		sb = Xb/xb + 1
	else:
		sb = Xb/xb

	print(sa+sb)
	
	


