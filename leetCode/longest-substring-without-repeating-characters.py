
#  Done cpp code left

from re import S

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        current_min = 0
        current_max = 0
        min = 0
        max = 0
        dictionary = {}
        for index in range(length):
            element = s[index]
            if element not in dictionary.keys():
                dictionary[element] = index
                current_max = index
            else:
                # find position of the repeated element
                # and remove the elements from dictionary till that element
                # including that element also
                previousIndex = dictionary[element]
                for indToRemove in range(current_min, previousIndex + 1):
                    dictionary.pop(s[indToRemove])

                current_min = previousIndex + 1
                current_max = index
                dictionary[element] = index
            if current_max - current_min > max - min:
                    max = current_max
                    min = current_min
        return max - min
            


        # # element: index
        # for index in range(length):
        #     element = s[index]
        #     if element not in dictionary.keys():
        #         dictionary[element] = index
        #         current_max += 1
        #         if (max - min < current_max - current_min):
        #             max = current_max
        #             min = current_min
        #     else:
        #         sliding_window_min_index = dictionary[element]
        #         for index in range(current_min , sliding_window_min_index+1):
        #             newElement = s[index]
        #             dictionary.pop(newElement)
        #         current_min = sliding_window_min_index + 1
        #         dictionary[element] = index
        # return max - min

                
