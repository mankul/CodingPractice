


test_cases = input()




def calculate_expression(expression):
    expr_len = len(expression)
    # ( ) / * + -, use stack, how
    stack=[]

    for char in expression:
        print(char)
        if char == "(":
            stack.append([])
        elif char == ")":
            expr_list=stack[-1]
            stack.pop()
            print("stack is ",expr_list)
            print("rest stack is ", stack)
            expr = calculate_math_expression(expr_list)
            print("calculation is",expr)

            stack[-1].append(expr)
            # for expr in expr_list:
            #     calculate_math_expression(expr)
        else:
            stack[-1].append(char)
    print(stack )
    

def calculate_math_expression(expr):
    stack_numerals = []
    stack_operators = []
    
    for char in expr:
        if char == "+":
            stack_operators.append("+")
        elif char == "-":
            stack_operators.append("-")
        elif char == "*":
            if stack_operators[-1] == "*" or stack_operators[-1] == "/":
                stack_operators.append("*")
            else:
                
        



def old_form(expr):


    # binary operator 
    if len(expr) == 1:
        return int(expr)
    
    stack_bodmass = []
    operator=""
    for char in expr:

        if char == "*":
            operator="*"

        elif char == "+":
            operator = "+"
        elif char == "-":
            operator = "-"
        elif char == "/":
            operator = "/"
        else:
            
            if operator == "*":
                item1 = int(stack_bodmass[-1])
                stack_bodmass[-1].pop()

                item2 = int(char)
                result = (item1) * (item2)

                stack_bodmass.append(result)

            elif operator == "/":
                item1 = int(stack_bodmass[-1])
                stack_bodmass[-1].pop()

                item2 = int(char)
                result = (item1) / (item2)

                stack_bodmass.append(result)

            elif operator == "-":
                stack_bodmass.append("-")
                stack_bodmass.append(char)

            elif operator == "+":
                stack_bodmass.append("-")
                stack_bodmass.append(char)

            else:
                stack_bodmass.append(char)
    operator = ""
    for char in stack_bodmass:
        if char == "+":
            operator = "+"
        elif char == "-":
            operator = "-"
        else:
            if operator == "":
                item1 = int(char)
            else:
                item2 = int(char)
                stack_bodmass.pop()
                if operator == "+":
                    stack_bodmass.append(item1 - item2)
                    operator = ""
                elif operator == "-":
                    stack_bodmass.append(item1+item2)
                    operator = ""


    return result


for index in range(test_cases):
    expression = raw_input()
    calculate_expression(expression)
    