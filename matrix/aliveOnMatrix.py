# (i,j) initial position of mouse. square matrix m x m. 
# move in all direction along axis in each step. n number of steps.
# find probability of mouse to be alive, if he jumps out of matrix board. it will die


# f(n):- total paths for alive
# g(n):- total paths

# prob(n) = f(n)/g(n)

# where
# f(n, i, j) = f(n-1, i-1, j) + f(n-1, i, j-1) + f(n-1, i + 1, j) + f(n-1 , i, j+1)
# g(n, i, j) = g(n-1, i-1, j) + g(n-1, i, j-1) + g(n-1, i + 1, j) + g(n-1 , i, j+1)

class Solution:
    def __init(self):
        print(" solution class instance")


    def matrix(self, n, m , i, j ):

        if( i < 0 or i >= m or j < 0 or j >= m):
            return 0 , 1
        if( n == 0):
            return 1 , 1
        f1, g1 = self.matrix(n - 1, m, i-1, j )
        f2, g2 = self.matrix(n - 1, m, i, j-1 )
        f3, g3 = self.matrix(n - 1, m, i+1, j )
        f4, g4 = self.matrix(n - 1, m, i,  j + 1)
        return (f1 + f2 + f3 + f4) , (g1 + g2 + g3 + g4)

def main():
    s = Solution()
    f, g = s.matrix(3, 2, 0, 0) 
    print(f/g)

if __name__ == "__main__": main()

    
