Fundamental solution to a dynamic problem is to reduce the problem to recursion. The recursion thus helps in saving the intermediate values or outputs in memory.

R(n) = R(n-1) + s
or
R(n) = R(n-1) + R(n-2) + R(n-3)

here we can see the recursion in the statements. If we calculate the R(i) and save it for future use, we can reduce the complexity from c^n to \theta(n).

