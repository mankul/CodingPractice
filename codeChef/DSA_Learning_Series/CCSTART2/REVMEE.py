num = int(input())
numbers = raw_input().split(" ")
numbers = list(map(lambda x: int(x),numbers))
reverse_numbers = []
output = ""
for i in range(num):
    output+="{} ".format(numbers[num-i-1])
# reverse_numbers.append(numbers[num-i-1])
# for number in reverse_numbers:
# output+="{} ".format(number)
print(output)