# check if a number is a power of 2


def main():
    num = int(input())
    if num & (num-1) == 0:
        print("{} Number is power of 2".format(num))
        power = 0
        while num > 0:
            if num == 1:
                print("and the power is {}".format(power))
		    
            num = num >> 1
            power += 1
			
    else:
        print("{} Number is not power of 2".format(num))



if __name__ == "__main__":
    main()
