


class Heap:
    

    def __init__(self) :
        self.root=None



class Node:
    def __init__(self, val) :
        self.value = val
        self.left=None
        self.right=None



        



def heapify( )








test_cases = input()



for i in range(test_cases):
    # heap sorting.
    arr_len = input()
    arr = []
    for j in range(arr_len):
        num = input()
        arr.append(num)

    print(heap_sort(arr, arr_len))