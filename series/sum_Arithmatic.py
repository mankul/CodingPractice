# Write a program to find the sum of series 1+2+3..+N.


# a: first number, l : last element, d: difference , n : numbers, Arithmatic series.
# 2,4,6,8,10,12,14,16,....
# l = a + (n-1) * d
# a_k = a + (k-1) * d
# sum_n = n/2 * (a + l)

def sum_of_series(n, a, l):
    if(n == 0):
        return 0
    if( n == 1):
        return a
    else:
        return( n/2 * (a + l))

def nth_term(n, a, d):
    return a + (n-1) * d
print("a d n")
a = int(input())
d = int(input())
n = int(input())
l = nth_term(n, a, d)
print(sum_of_series(n, a, l))
