// Given a string s, find the length of the longest substring without repeating characters.

// start iterating string
// make a dictionary with key as element and value as element index
// save maximum count in indices as pair min, max
// see if next element is saved
// if yes , find position of element in
// selected maximum string, slide window begining to
// the next element of previous index, insert current element
// compare the current_max - current_min with max - min
// if greater. replace max and min

// python code:- 