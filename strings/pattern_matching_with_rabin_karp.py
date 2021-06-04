
# use hash function for discarding the possibility of pattern match.
# use rehash to find hash of next window in O(1).
# This will make the comparision only for possible pattern.

test_cases = input()

d = 256
q = 1000000000


def calculate_hash(string_):
    hash = 0
    for char in string_:
        hash = (d*hash + ord(char))%q
    return hash

def calculate_rehash(hash, prev_char, next_char, string_length):

    intermediate = ((hash - ord(prev_char) * pow(d,string_length-1) ) * d + ord(next_char) ) % q
    return intermediate

for t in range(test_cases):
    text = raw_input()
    string_ = raw_input()

    string_length = len(string_)
    text_length = len(text)

    hash_string = calculate_hash(string_)
    hash_sliding_window = calculate_hash(text[:string_length])
    patterns = []
    for sliding_window_index in range(text_length - string_length + 1):
        if hash_string != hash_sliding_window:
            hash_sliding_window = calculate_rehash(hash_sliding_window, \
            text[sliding_window_index]\
             ,text[sliding_window_index +  string_length], \
             string_length \
             )
        else:
            # confirm the pattern is present
            pattern_matched = True
            for index in range(string_length):
                if string_[index] != text[sliding_window_index + index]:
                    pattern_matched = False
                    break
            if pattern_matched == True:
                patterns.append(sliding_window_index)
    print(patterns  )





