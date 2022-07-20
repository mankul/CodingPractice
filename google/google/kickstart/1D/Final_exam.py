
def find_value(s,p):
    nearest_pair=[]
    nearest_diff = 0
    nearest_value = ""
    for pair in p:
        if s == pair[1]:
            p.remove(pair)
            if pair[0] != pair[1]:
                p.append([pair[0],pair[1]-1])
            return s

        elif s >= pair[0] and s < pair[1]:
            p.remove(pair)  
            if s > pair[0]:
                p.append([pair[0],s-1])
                # if s != pair[1]:
            #     p.append([s+1,pair[1]])
            # else:
            p.append([s+1,pair[1]])
            return s
        
        else:
            if pair[0] > s:
                diff = pair[0] - s
                if nearest_diff == 0:
                    nearest_pair = pair
                    nearest_diff = diff
                    nearest_value = pair[0]
                else:
                    if diff < nearest_diff:
                        nearest_diff = diff
                        nearest_pair = pair
                        nearest_value = pair[0]
                    elif diff == nearest_diff and nearest_value > pair[0]:
                        nearest_value = pair[0]
                        nearest_diff = diff
                        nearest_pair = pair

            elif pair[1] < s:
                diff = s - pair[1]
                if nearest_diff == 0:
                    nearest_diff = diff
                    nearest_pair = pair
                    nearest_value = pair[1]
                else:
                    if diff < nearest_diff:
                        nearest_diff = diff
                        nearest_pair = pair
                        nearest_value = pair[1]
                    elif diff == nearest_diff and nearest_value > pair[1]:
                        nearest_value = pair[1]
                        nearest_diff = diff
                        nearest_pair = pair
    # print("nearest pair is ",nearest_pair)
    p.remove(nearest_pair)
    if nearest_pair[0] == nearest_value:
        if nearest_pair[0] != nearest_pair[1]:
            p.append([nearest_pair[0]+1,nearest_pair[1]])
        return nearest_pair[0]
    else:
        if nearest_pair[0] != nearest_pair[1]:
            p.append([nearest_pair[0], nearest_pair[1]-1])
        return nearest_pair[1]
    


test_cases = int(input())

for t in range(test_cases):
    interval = raw_input()
    interval = interval.split(" ")
    n = int(interval[0])
    m = int(interval[1])
    p=[]
    for count in range(n):
        interval = raw_input()
        interval = interval.split(" ")
        pair=[]
        pair.append(int(interval[0]))
        pair.append(int(interval[1]))
        p.append(pair)
    # print(p)
        # for p1 in range(pair):
        #     p.append(p1)
    # p.sort()
    s = []
    students = raw_input()
    students = students.split(" ")
    for count in range(m):
        s.append(int(students[count]))
    # print("st" , s)
    result = []

    for student in s:
        value = find_value(student,p)
        # print("new array is ",p)
        result.append(value)
    output = "Case #{}: ".format(t+1)#12 24 11 2
    for val in result:
        output+=" {}".format(val)
    print(output)







        


    
	
