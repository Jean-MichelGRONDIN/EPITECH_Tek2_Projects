#!/usr/bin/python3

import math
import sys

import decimal

def do_factorial(nb):
    res = nb
    nb = nb - 1
    while nb > 1:
        res = decimal.Decimal(res * nb)
        nb = nb - 1
    return (decimal.Decimal(res))

def cohef(n, k):
    fac_n = decimal.Decimal(do_factorial(n))
    fac_k = decimal.Decimal(do_factorial(k)) * decimal.Decimal(do_factorial(n - k))
    res = decimal.Decimal(fac_n) / decimal.Decimal(fac_k)
    print('{0}-combinations of a set of size {1}:'.format(k, n))
    print("{:.0f}".format(res))
    return (res)

def main():
    if len (sys.argv) == 3:
        cohef(int(sys.argv[1]), int(sys.argv[2]))
        return (0)
    else:
        return (84)

main()