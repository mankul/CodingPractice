# You are given a string s. 
# You can convert s to a palindrome by adding characters in front of it.
# Return the shortest palindrome you can find by performing this transformation.
'''
Solution 1
class Solution(object):
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        # assume every index as middle point 
        # of the palindrome whose left end start at index 0
        # similar problem of finding maximum palindrome in string but 
        # with contraint of spanning to left index

        left = 0
        right = 0
        lengthOfString = len(s)
        upm = -1
        for ind in range(lengthOfString):
            right = ind
            left = ind
            while(right < lengthOfString and left >= 0 ):
                if(s[right] != s[left]):
                    break
                left -= 1
                right += 1
            if left == -1 and (right - left - 2) > upm:
                upm = right - 1
            
            right = ind + 1
            left = ind
            while(right < lengthOfString and left >= 0):
                if(s[right] != s[left]):
                    break
                left -= 1
                right += 1
            if left == -1 and (right - left - 2) > upm:
                upm = right - 1
        
        residueString = s[upm+1:lengthOfString]
        
        residueString = residueString[::-1]
        return residueString + s
'''


# Solution 2 . There is constraint of palindrome starting at left index
# #  use it

# class Solution(object):
#     def shortestPalindrome(self, s):
#         lengthOfString = len(s)
#         left  = 0
#         right = lengthOfString - 1
        
#         # assuming every index as middle
#         for index in range(lengthOfString/2):
#             left = 0
#             for mid in range(index + 1):
#                 if(s[left] != s[2*mid - left]):
#                     break




solution = Solution()
print(solution.shortestPalindrome("bababa"))