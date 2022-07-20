# Reversing an integer means to reverse all its digits.
# For example, reversing 2021 gives 1202. 
# Reversing 12300 gives 321 as the leading zeros are not retained.
# Given an integer num, reverse num to get reversed1, 
# then reverse reversed1 to get reversed2. 
# Return true if reversed2 equals num. Otherwise return false.

#DONE


class Solution(object):
    def isSameAfterReversals(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if(num != 0 and num%10 == 0):
            return False
        else:
            return True
solution = Solution()
print(solution.isSameAfterReversals(1300))
print(solution.isSameAfterReversals(1301))


