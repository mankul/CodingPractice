# Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
# The overall run time complexity should be O(log (m+n)).

# DONE
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        listLength1 = len(nums1)
        listLength2 = len(nums2)
        newList = []
        index1 = 0
        index2 = 0
        median1 = (listLength1 + listLength2) / 2
        while(index1 < listLength1 or index2 < listLength2):

            if index1 == listLength1:
                newList.append(nums2[index2])
                index2+=1
            elif index2 == listLength2:
                newList.append(nums1[index1])
                index1+=1
            elif nums1[index1] < nums2[index2]:
                newList.append(nums1[index1])
                index1+=1
            else:
                newList.append(nums2[index2])
                index2+=1
        if (listLength1 + listLength2) % 2 == 0:
            return ( float(newList[median1]) + float(newList[median1-1]) )/2.0
        else:
            return newList[median1]



sol = Solution()
sol.findMedianSortedArrays([1,2],[3,4])
