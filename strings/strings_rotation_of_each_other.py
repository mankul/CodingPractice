

test_cases = input()


for t in range(test_cases):
    string1 = raw_input()
    string2 = raw_input()

    string_length1 = len(string1)
    string_length2 = len(string2)

    rotation = True

    if string_length1 != string_length2:
        print("Not equal strings")
        break
    else:
        for index in range(string_length1):
            rotation = True

            running_end = (index + string_length2 )% string_length2

            compare_index = 0

            for running_index in range(index, string_length2):
                if string1[compare_index] != string2[running_index]:
                    rotation = False
                    continue
                compare_index+=1
            for running_index in range(running_end):
                if string1[compare_index] != string2[running_index]:
                    rotation = False
                    continue
                compare_index+=1

            if rotation == True:
                print("Strings are rotation to each other")
                break
        

        if rotation == False:
            print("Not Rotation")
