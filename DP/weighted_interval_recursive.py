def calculate_maximum_interval_set(interval_array, job_index , n, memo):
    print("job index is ", job_index    )
    if (n-job_index) <= 0 : 
        return 0
    
    if memo[n - job_index] != 0:
        return memo[n - job_index]

    value1 = calculate_maximum_interval_set(interval_array, job_index+1, n, memo) + interval_array[job_index][2]

    next_index = job_index + 2
    for next_index in range(job_index+2, n):
        if interval_array[next_index][0] >= interval_array[job_index][1]:
            break
        # next_index = index 
    
    value2 = calculate_maximum_interval_set(interval_array, next_index, n, memo)

    if value2 < value1:
        memo[n - job_index] = value1
    else:
        memo[n - job_index] = value2
    return memo[n-job_index]





n=int(input())
interval_array = []
print("input {} intervals in each line with starting, ending, weight respectively with space".format(n))

for i in range(n):
    line = raw_input()
    start, end, weight = line.split(" ")
    interval_array.append([int(start), int(end), int(weight)])
interval_array = sorted(interval_array, key = lambda x: x[0])
print(interval_array)
memo = [0 for i in range(n+1)]
print(memo)
print(calculate_maximum_interval_set(interval_array,0, n, memo))
