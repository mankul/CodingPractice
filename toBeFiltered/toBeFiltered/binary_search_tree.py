### incomplete code

class Node:
    left=None
    right=None
    value=0

    def __init__(self, value):
        self.left = None
        self.right = None
        self.value = value



node_list = []


preorder_list = []


def enter_preorder_nodes(number_of_nodes):
    global preorder_list
    for i in range(number_of_nodes):
        node = int(raw_input())
        preorder_list.append(node)
        


enter_preorder_nodes(10)
def create_bst():
    global preorder_list
    for node in preorder_list:
        
