num = int(input())
for i in range(num):
    output=""
    for t in range(num-i-1):
        output+=" "
    for t in range(i+1):
        output+="*"
    print(output)
