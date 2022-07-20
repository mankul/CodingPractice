# Given a signed 32-bit integer x, return x with its digits reversed. 
# If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1],
#  then return 0.
# Assume the environment does not allow you to store 64-bit integers (signed or unsigned).


# DONE

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sum = 0
        INTMAX = 1<<31
        if(x < 0):
            sign = -1
            INTMAX = INTMAX<<1 - 1
            print(INTMAX)
        else:
            sign = 1
        x = abs(x)
        while(x > 9):
            digit = x % 10
            x = x / 10
            sum *= 10 
            sum += digit
            if sum > INTMAX:
                return 0
        sum *= 10
        sum += x
        #  not check if it is inside the range 
        
        print("after right shift",sum)
        if sum > INTMAX:
            return 0
        return sign * sum

sol = Solution()
print(sol.reverse(-4236469))
print(sol.reverse(34236469))
print(sol.reverse(1563847412))
print(sol.reverse(1534236469))