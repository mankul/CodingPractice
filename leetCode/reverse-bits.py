# Reverse Bits of a given 32 bits unsigned integer.

# Note that in some languages, 
# such as Java, there is no unsigned integer type. 
# In this case, both input and output will be given as a signed integer type. 
# They should not affect your implementation, 
# as the integer's internal binary representation is the same, 
# whether it is signed or unsigned.
# In Java, the compiler represents the signed integers using 2's complement notation. 
# Therefore, in Example 2 above, the input represents the signed integer -3 
# and the output represents the signed integer -1073741825.

class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):

        num = 0

        while(n > 0):
            remainder = n % 2
            n = n / 2

            num = num * 2
            num += remainder
            
        return num


        number = 0
        for i in range(32):
            digit = int(n[31 -i]) & 1
            num = num << 1
            number *= 2
            num += digit
            number += digit
        return number
sol = Solution()
# print(sol.reverseBits('00000010100101000001111010011100'))
print(sol.reverseBits(43261596))