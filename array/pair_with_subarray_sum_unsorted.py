

test_cases = input()


for t in range(test_cases):
    n=input()
    sum = input()
    arr=[]
    for i in range(n):
        num=input()
        arr.append(num)
    total_sum=0
    prev=0
    for i in range(n):
        total_sum+=arr[i]
        if total_sum > sum:
            total_sum-=arr[prev]
            prev+=1

        elif total_sum == sum:
            print(prev, i)
            break
    if total_sum != sum:
        print("no subarray sum found")



    