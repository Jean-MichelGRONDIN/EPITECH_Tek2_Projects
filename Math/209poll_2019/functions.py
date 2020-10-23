##
## EPITECH PROJECT, 2020
## 209poll_2019
## File description:
## functions
##

from math import sqrt

def displayGivenVals(pSize, sSize, p):
    print("Population size:         {}".format(pSize))
    print("Sample size:             {}".format(sSize))
    print("Voting intentions:       {:.2f}%".format(p))

def displayCalcsRes(variance, confiNineFive, confiNineNine):
    print("Variance:                {:.6f}".format(variance))
    print("95% confidence interval: [{:.2f}%; {:.2f}%]".format(confiNineFive[0] * 100, confiNineFive[1] * 100))
    print("99% confidence interval: [{:.2f}%; {:.2f}%]".format(confiNineNine[0] * 100, confiNineNine[1] * 100))

def calcConfidenceInterval(pF, constVal, variance):
    tmp = [pF - (constVal * sqrt(variance)), pF + (constVal * sqrt(variance))]
    res = []
    for val in tmp:
        if val < 0:
            val = 0
        if val > 1:
            val = 1
        res.append(val)
    return (res)

def poll(pSize, sSize, p):
    try:
        pF = p / 100
        endPop = (pSize - sSize) / (pSize - 1)
        variance = (pF * (1 - pF) * endPop) / sSize
        confiNineFive = calcConfidenceInterval(pF, 1.96, variance)
        confiNineNine = calcConfidenceInterval(pF, 2.58, variance)
    except:
        return (84)
    displayGivenVals(pSize, sSize, p)
    displayCalcsRes(variance, confiNineFive, confiNineNine)
    return (0)

