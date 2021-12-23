


def grid_travel(m,n, memo = {}):
    if (m == 0 or n == 0):
        return 0
    if (m == 1 and n == 1):
        return 1
    if (m,n) in memo.keys():
        return memo[(m,n)]
    memo[(m,n)] = grid_travel(m-1,n) + grid_travel(m,n-1)
    return memo[(m,n)]





test_cases = input()
for t in range(test_cases):
    interval = raw_input().split(" ")
    m = int(interval[0])
    n = int(interval[1])

    print(grid_travel(m,n))
