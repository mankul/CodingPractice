

class Solution:
    def __init__(self) -> None:
        pass

    def sortedArray(self,num1, num2, len1, len2):
        sorted_arr = []
        i = j = 0
        while i < len1 and j < len2:
            if(num1[i] < num2[j] ):
                sorted_arr.append(num1[i])
                i+=1
            else:
                sorted_arr.append(num2[j])
                j+=1
        if( i == len1 ):
            while(j < len2):
                sorted_arr.append(num2[j])
                j+=1
        else:
            while(i < len1):
                sorted_arr.append(num2[i])
                i+=1
        return sorted_arr


def main():

    s = Solution()
    num1 = [1,2,4,22,24]
    num2= [2,12,20,25]
    sorted_array = s.sortedArray(num1, num2, num1.len, num2.len)
    print(sorted_array)
if __name__ == "__main__": main()