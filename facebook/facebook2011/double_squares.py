

test_cases = input()



def find_double_squares(number):
    num = 0
    square = pow(num,2)
    square_table=[]
    while square <= number:
        square_table.append([num, square])
        num+=1
        square = pow(num, 2)

    print(square_table)

    index1 = 0
    length = len(square_table)
    index2 = length-1
    count = 0


    print(square_table[index1])
    print(square_table[index2])

    while index1<index2:
        square1 = square_table[index1][1]
        square2 = square_table[index2][1]

        if square1 == number or square2 == number:
            count+=1
            print("square is ",number)
            break
        if square1 * 2 == number:
            count+=1
            print("twice square is ", square)
            index1+=1
            
        if  square2 * 2 == number:
            count+=1
            index2-=1
    
        if square1 + square2 == number:
            count+=1
            index1+=1
            index2-=1
            print("sum found ",square1, square2)
    
        elif square1 + square2 > number:
            index2-=1
        elif square1 + square2 < number:
            index1+=1

    if index1 == index2 and (square_table[index2][1] == number or square_table[index2][1] *2 == number):
        count+=1
    return count







for i in range(test_cases):
    number = input()
    print(find_double_squares(number))