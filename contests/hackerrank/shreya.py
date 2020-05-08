import math
XPrime = 100
N = 2


def nth_root(num, root):
    answer = num ** (1/root)
    return answer


gInteger = math.floor(nth_root(X, N))
array = [0] * (gInteger+1)

array[0] = 0
array[1] = 1

for i in range(2, gInteger+1):
    array[i] = i ** N


noOfWays = 0

usedNumbers = []
usedIndex = []

def nWay(X, N):
    global noOfWays
    global XPrime
    if X == 0:
        noOfWays = noOfWays + 1
        value = (math.floor(XPrime ** (1/N)) - 1)**N
        X = XPrime - value
        return nWay(X, N)

    elif X < 0:
        return 0

    else:
        temp = X ** (1/N)
        temp = math.floor(temp)
        X = X - array[temp]
        return nWay(X, N)


a = nWay(100, 2)
print(a)
