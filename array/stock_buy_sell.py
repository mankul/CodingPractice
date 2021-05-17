


# stock buy sell
# value decreasing 120 100 

# as value increases, buy stock

# stock bought, as the value increases keep it, as the value decreases buy it


# 10 20 40 50 50 70 60 30 80 500 400 450 440 10000



test_cases = int(input())


def get_max_stock_profit( arr, len):
    buy=0
    buy_index = 0
    profit = 0
    for i in range(len-1):
        if buy == 0:
            if arr[i] < arr[i+1]:
                buy = 1
                buy_index = i
        if buy == 1:
            if arr[i] > arr[i+1]:
                buy = 0
                profit += ( arr[i] - arr[buy_index])
    if buy == 1:
        if arr[len-1] > arr[buy_index]:
            profit+=(arr[len-1] - arr[buy_index])
    return profit  
            

for i in range(test_cases):
    len = int(input())
    arr = []
    for j in range(len):
        num = int(input())
        arr.append(num)
    print(get_max_stock_profit(arr, len))