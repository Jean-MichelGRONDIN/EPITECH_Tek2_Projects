#!/usr/bin/env  python3

from math import sqrt
from math import pow

def do_input():
    while (1):
        print("Enter next value: ", end="")
        try:
            res = input()
            res = int(res)
        except ValueError:
            continue
        except EOFError:
            exit(0)
        else:
            return (res)

def calcMean(nb, mean, newVal):
    return (mean + (newVal - mean) / nb)

def calcStdDev(n, a, sd, newVal):
    return(sqrt(((((pow(sd, 2) + pow(a, 2)) * n) + pow(newVal, 2)) / (n + 1) - pow((((a * n) + newVal) / (n + 1)), 2))))

def loop(n, a, h, sd):
    inputVal = do_input()
    new_n = n
    new_a = a
    new_h = h
    new_sd = sd
    quad_res = -1
    while (inputVal != "END"):
        try:
            new_n = n + 1
            new_sd = calcStdDev(n, a, sd, inputVal)
            new_a = calcMean(n + 1, a, inputVal)
            quad_res = sqrt(pow(new_sd, 2) + pow(new_a, 2))
            new_h = 1 / calcMean(n + 1, 1/h, 1/inputVal)
        except ZeroDivisionError:
            return (84)
        print("   Number of values:   {}".format(new_n))
        print("   Standard deviation: {:.2f}".format(new_sd))
        print("   Arithmetic mean:    {:.2f}".format(new_a))
        print("   Root mean square:   {:.2f}".format(quad_res))
        print("   Harmonic mean:      {:.2f}".format(new_h), end="\n\n")
        inputVal = do_input()
        n = new_n
        a = new_a
        h = new_h
        sd = new_sd
    return (0)