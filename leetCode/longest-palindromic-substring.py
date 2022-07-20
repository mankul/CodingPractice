# longest-palindromic-substri
# Given a string s, return the longest palindromic substring in s.

# solution is to assume every element as middle.
# a) odd count
# b) even count


# DONE


from operator import le
from re import S


class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        lengthOfNumber = len(s)
        inf = lengthOfNumber
        upm = -1
        for ind in range(lengthOfNumber):
            left = ind
            right = ind
            #  if the palindrome is odd
            while(left >= 0 and right <= lengthOfNumber - 1):
                if(s[left] != s[right]):
                    break
                left -= 1
                right += 1
            if(right - left - 2 > (upm - inf)):
                upm = right - 1
                inf = left + 1
            print(ind, left, right, inf, upm)

            # if the substring palindrome and even
            if ind >=0 and ind < lengthOfNumber-1:
                left = ind
                right = ind + 1
                while(left >= 0 and right <= lengthOfNumber - 1):
                    if(s[left] != s[right]):
                        break
                    left -= 1
                    right += 1
            if right - left -2> upm - inf:
                upm = right-1
                inf = left+1
            print(ind, left, right, inf, upm , "even")                        
        return s[inf:upm+1]


solution = Solution()
print(solution.longestPalindrome("bababaa"))