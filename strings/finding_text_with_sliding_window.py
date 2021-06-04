

test_cases = input()


for t in range(test_cases):
    text = raw_input()
    string_ = raw_input()
    
    # use a sliding window kind of algorithm

    sliding_window_length = len(string_)
    iterations = len(text) - sliding_window_length + 1

    pattern_matched_indices = []
    for iteration in range(iterations):
        pattern_matched = True
        string_index = 0
        for sliding_index in range(iteration, iteration + sliding_window_length):
            if text[sliding_index] != string_[string_index]:
                pattern_matched = False
                break
            string_index+=1
        if pattern_matched == True:
            pattern_matched_indices.append(iteration)
    print(pattern_matched_indices)
