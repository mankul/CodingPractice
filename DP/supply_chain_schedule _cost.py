

def find_optimal_cost(n, S, Opt, c, r):
    if n == 0:
        if n not in Opt.keys():
            Opt[n] = 0
        return
    if n < 4:
        if n not in Opt.keys():
            cost = sum(S[:n]) * r
            Opt[n] = cost
        return
    if n == 4:
        if n not in Opt.keys():
            costA = sum(S[:n]) * r
            costB = 4 * c
            if costA < costB:
                
                Opt[n] = costA
            else:
                Opt[n] = costB
        return
    if n not in Opt.keys():
        find_optimal_cost(n-4, S, Opt, c, r)
        find_optimal_cost(n-1, S, Opt, c, r)

        costA = Opt[n-4] + 4 * c
        costB = Opt[n-1] + S[n-1] * r

        # print(" cost A {} for {}".format(costA, n))
        # print(" cost B {} for {}".format(costB, n))
        if costA < costB:
            Opt[n] = costA
        else:
            Opt[n] = costB
print("enter number of weeks for the schedule")
n = input()
print("enter the frieght in pound numbers in a line seperated by space for {} weeks".format(n))
S = raw_input().split(" ")
S = map(lambda x: int(x), S)
print("enter the cost per pound for A vendor")
r = input()
print("enter fixed amount per week for vendor B")
c = input()
Opt = {}
find_optimal_cost(n,S, Opt, c, r)
print("minimum cost is {} ".format(Opt[n]))