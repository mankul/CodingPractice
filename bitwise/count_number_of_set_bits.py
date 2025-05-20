# count number of set bits in a number with bitwise operator.



def main():
    number=input()
    number = int(number)
    counter = 0
    while number > 0:
        if number & 1 == 1:
            counter += 1
        number >>= 1
    print(counter)


if __name__ == "__main__":
    main()
