# binary string of 0 1, find the minimum flips required to get string such that each kth substring has 
# atleast one 1



test_cases = int(input())



def minimum_flips(binary_string, k):
    count = 0
    # last_flip = -1
    last_one = -1
    length = len(binary_string)
    for i in range(length):
        if binary_string[i] != '1': 
            if i - last_one == k:
                print(i, last_one)
                # last_flip = i
                last_one = i
                count+=1
            
        else:
            print(i)
            last_one = i
    return count
for i in range(test_cases):
    binary_string = raw_input()
    k = int(input())
    # len = int(input())
    # arr = []
    # k = int(input())
    # for j in range(len):
    #     num = int(input())
    #     arr.append(num)
    print(minimum_flips(binary_string, k))