

# array is unsorted


test_cases = input()




for t in range(test_cases):
    hash = {}
    pair_sum = input()
    n = input()
    for i in range(n):
        num = input()
        hash[num] = num
    
    for num in hash.keys():
        another = pair_sum - num
        if another in hash.keys():
            print(num, another)
            break
        

    


         
