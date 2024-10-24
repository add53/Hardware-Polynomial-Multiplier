import numpy as np
from numpy.polynomial import polynomial as P

def read_parameters(filepath):
    lines = []
    with open(filepath, "r") as file:
        lines = file.readlines()
        n, q = list(map(lambda x: int(x.split("=")[1]), lines[0:2]))

        A, B = list(map(
            lambda x: list(np.fromstring(x.split("=")[1].strip("[]"), dtype=int, sep=",")), 
            lines[2:4]
        ))

        return (A, B, n, q)

def polynomial_ring_test(A, B, n, q):
    # random alpha < 1 value for gaussian distribution secret and error generation
    alpha = np.random.random()

    # irreducible polynomial x^n + 1
    xN_1 = [0] * (n + 1)
    xN_1[0] = 1
    xN_1[-1] = 1

    # A x s + e/ (x^(n-1) + 1) (mod q)
    print("a(x)", "\n\t", A,)
    print("b(x)", "\n\t", B)

    AB = np.polymul(A,B)%q
    print("c(x) = a(x) * b(x) (mod q)", "\n\t", AB)
    print("f(x)","\n\t", xN_1)

    print("c(x) / f(x) (mod q)", "\n\t", P.polydiv(AB,xN_1))

    result = P.polydiv(AB,xN_1)[1]%q
    print("remainder -> final polynomial", "\n\t", result)

    return result

if __name__ == "__main__":
    polynomial_ring_test(*read_parameters("NTTMultNumbers.txt"))