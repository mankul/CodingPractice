

test_cases = input()

def classify(string_in):
    stack = []

    

    for char in string_in:
        if char == "(":
            stack.append([])
        elif char == ")":
            classify("".join(stack.pop()))
        else:
            stack[-1].append(char)
        
    print(stack)


def equivallence_classes(list_string):
    
    for st in list_string:
        classify(st)


for i in range(test_cases):
    eq = input()
    list_string=[]
    for j in range(eq):
        string = raw_input()
        list_string.append(string)

    equivallence_classes(list_string)