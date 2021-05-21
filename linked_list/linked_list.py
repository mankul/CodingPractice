#linked list application





class Node:


    def __init__(self, val) :
        self.value=val
        self.next=None



class LinkedList:

    def __init__(self) :
        self.head = None


    def insert_node_into_linked_list(self, node):
        if self.head == None:
            self.head = node
        else:
            ptr = self.head
            while ptr.next :
                ptr = ptr.next
            ptr.next = node


    def remove_node_with_value(val):
        ptr = self.head
        prev_ptr=ptr
        while ptr.next != None:
            if ptr.value == val:
                break
            prev_ptr = ptr
            ptr = ptr.next
        if ptr.next!=None:
            if ptr!= self.head:
                prev_ptr.next= ptr.next
            else:
                self.head = ptr.next
        else:
            print("value not found in linked list")




linked_list = LinkedList()

for i in range(10):
    node = Node(i)
    linked_list.insert_node_into_linked_list(node)

ptr = linked_list.head
while(ptr.next != None):
    print(ptr.value)
    ptr = ptr.next