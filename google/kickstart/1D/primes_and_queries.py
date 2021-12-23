

test_cases = int(raw_input())

def get_factor(num, p):
    if num % p == 0:
        return 1 + get_factor(num/p,p)
    else:
        return 0


for t in range(test_cases):
    interval = raw_input()
    interval = interval.split(" ")
    n = int(interval[0])
    q = int(interval[1])
    p = int(interval[2])
    num_arr=[]
    interval = raw_input()
    interval = interval.split(" ")
    for val in interval:
        num_arr.append(int(val))
    result = []
    output = "Case #{}:".format(t+1)
    for i in range(q):
        query = raw_input()
        query = query.split(" ")
        if query[0] =="1":
            pos = int(query[1])
            val = int(query[2])
            num_arr[pos-1] = val
        else:
            count = 0
            s = int(query[1])
            l = int(query[2])
            r = int(query[3])
            for pos in range(l-1,r):
                if num_arr[pos]% p == 0:
                    count += (get_factor(num_arr[pos], p) * s)
                else:
                    count += 1
            print(num_arr)    
            output+=" {}".format(count)
    print(output)
            



    