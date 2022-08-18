test_cases = int(input())
for i in range(test_cases):
    num = int(input())
    reverse = []
    count=0
    while num > 0:
        reverse.append(num%10)
        num = num/10
        count+=1
    output = 0
    for i in range(count):
        output *= 10
        output += (reverse[i])
    print(output)