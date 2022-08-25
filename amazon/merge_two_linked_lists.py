

def createLinkedList(listOfElements):
    headPointer = None
    pointer = None
    for item in listOfElements:
        if(headPointer == None):
            headPointer = LinkedList()
            pointer = headPointer
        else:
            pointer.nextNode = LinkedList()
            pointer = pointer.nextNode
        pointer.val = item
    return headPointer

        

class LinkedList:
    def __init__(self):
        self.val = 0
        self.nextNode = None

def mergeTwoLists(head1, head2):
    pointer1 = head1
    pointer2 = head2

    mergeList=None
    mergePointer=None

    count = 0
    while(count < 100):
        if pointer1 == None and pointer2 == None:
            break
        if pointer1 == None:
            if(mergeList == None):
                mergeList = LinkedList()
                mergeList = pointer2
            else:
                mergePointer.nextNode = pointer2
            break
        if pointer2 == None:
            if(mergeList == None):
                mergeList = LinkedList()
                mergeList = pointer1
            else:
                mergePointer.nextNode = pointer1
            break


        if pointer1.val > pointer2.val:
            if(mergeList == None):
                mergeList = pointer2
                mergePointer = mergeList
            else:
                mergePointer.nextNode = pointer2
                mergePointer = mergePointer.nextNode

            pointer2 = pointer2.nextNode
        else:
            if(mergeList == None):
                mergeList = pointer1
                mergePointer = mergeList
            else:
                mergePointer.nextNode = pointer1
                mergePointer = mergePointer.nextNode
            pointer1 = pointer1.nextNode
        count+=1
    return mergeList
            
            
            

def displayLinkedList(linkedList):
    while(linkedList != None):
        print(linkedList.val)
        linkedList = linkedList.nextNode


def main():
    list1 = [1,2,3,4,5,6,7,8]
    list2 = [3,44,55,66,88]
    list1 = createLinkedList(list1)
    list2 = createLinkedList(list2)

    mergedList = mergeTwoLists(list1, list2)
    
    displayLinkedList(mergedList)


if __name__ == "__main__": main()