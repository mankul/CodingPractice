# find the kth largest number in stream.
# numbers are
# find 10th largest in 
# 2, 3, 4, 6, 10, 15, 45,1,3,450,657,1000,999,400
# 2
# 2,3
# 2,3,4
# 2,3,4,6
# 2,3,4,6,10
# 2,3,4,6,10, 15
# 2,3,4,6,10, 15, 45
# 1,2,3,4,6,10, 15, 45
# 1,2,3,3,4,6,10,15,45
# 1,2,3,3,4,6,10,15,45, 450. [450]
# 1,2,3,3,4,6,10,15,45, 450,657 [450]
# 1,2,3,3,4,6,10,15,45, 450,657,1000 [450]
# 1,2,3,3,4,6,10,15,45, 450,657,1000,999 [450]
# 1,2,3,3,4,6,10,15,45,400,657,1000,999,450 [400]
# when kth number x is entered, entering into sorted order, The sorted position makes fix that number x is atmost number.next number will be atleast this much big.
# On next number if it is smaller than x, find the place in the subarray of 0 to k-2 position elements. insert it into the subarray and shift the previous kth element to end of array.
# If element is bigger than kth element. insert it into the end of the array

def insert_to_left(arr,el,k,eop):
    index = 0
    while(index < eop and index < k):
        if arr[index] > el:
            break
        index += 1
    while(index < eop and index < k):
        swap(arr, index, index + 1)
        index += 1
    return 
def swap(arr,k,l):
    temp = arr[k]
    arr[k] = arr[l]
    arr[l] = temp

def main():
    print("enter the k")
    arr = []
    k=int(input())
    print("enter the n array count, followed by n numbers")
    n=int(input())
    for num in range(n):
        x = int(input())

        if num < k:
            insert_to_left(arr,x,k,num)
        elif x < arr[k-1]:
            insert_to_left(arr,x,k,num)
            
        else:
            arr.append(x)
            

if __name__ == "__main__":
    main()
