from msilib.schema import Media


class MedianOfTwoSortedArrays:
    def __init__(self) -> None:
        print("Finding Median of two sorted arrays")
    

    def getMedian(self, num1, num2, len1, len2):
        i = 0
        j = 0
        leftMedianElement = 0
        medianElement = 0
        pos = (len1 + len2)/2 + 1 
        median = 0
        while i < len1 and j < len2:
            if median == pos:
                break
            if num1[i] < num2[j]:
                leftMedianElement = medianElement
                medianElement = num1[i] 
                i += 1

            else:
                leftMedianElement = medianElement
                medianElement = num2[j]
                j += 1
            median += 1
        if(median < pos):
            while i < len1 and median < pos:
                leftMedianElement = medianElement
                medianElement = num1[i]
                i += 1
                median += 1
            while j < len2 and median < pos:
                leftMedianElement = medianElement
                medianElement = num2[j]
                j += 1
            
        if( len1 + len2) %2 == 0:
            return (leftMedianElement  + medianElement) / 2
        else:
            return medianElement


def main():
    num1 = [1,20,33,44,500]
    num2 = [12, 34, 55, 66, 900]

    sol = MedianOfTwoSortedArrays()
    arr = sol.getMedian(num1, num2, 5, 5)
    print(arr)

if __name__ == "__main__": main()