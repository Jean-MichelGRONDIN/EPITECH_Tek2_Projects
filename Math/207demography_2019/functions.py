#!/usr/bin/env python3

from math import sqrt
from math import pow
from sys import stderr

def printFitOne(valOneX, valTwoX, rootMeanSqOne):
    print("Fit1")
    print("    Y = {:.2f} X - {:.2f}".format((valOneX / 1000000), abs(valTwoX / 1000000)))
    print("    Root-mean-square deviation: {:.2f}".format(rootMeanSqOne / 1000000))
    print("    Population in 2050: {:.2f}".format(((valOneX * 2050) - abs(valTwoX)) / 1000000))

def printFitTwo(valOneY, valTwoY, rootMeanSqTwo):
    print("Fit2")
    print("    X = {:.2f} Y + {:.2f}".format((valOneY * 1000000), valTwoY))
    print("    Root-mean-square deviation: {:.2f}".format(rootMeanSqTwo / 1000000))
    print("    Population in 2050: {:.2f}".format(((2050 - valTwoY) / valOneY) / 1000000))

def doCalc(vals, years):
    try:
        popMean = sum(vals) / len(vals)
        yearMean = sum(years) / len(years)
        devPop = [val-popMean for val in vals]
        devYear = [year-yearMean for year in years]
        covariance = [a*b for a,b in list(zip(devPop, devYear))]
        devPopSqare = [pow(x, 2) for x in devPop]
        devYearSqare = [pow(x, 2) for x in devYear]
        popStdDev = sqrt((sum(devPopSqare) / len(devPopSqare)))
        yearStdDev = sqrt((sum(devYearSqare) / len(devYearSqare)))
        covarianceMean = sum(covariance) / len(covariance)
        rootOne = (covarianceMean / (popStdDev * yearStdDev))
        valOneX = covarianceMean / pow(yearStdDev, 2)
        valTwoX = popMean - valOneX * yearMean
        valOneY = covarianceMean / pow(popStdDev, 2)
        valTwoY = yearMean - valOneY * popMean
        estimationOne = [(valOneX * year) - abs(valTwoX) for year in years]
        estimationTwo = [(year - abs(valTwoY)) / valOneY for year in years]
        rootMeanSqOne = sqrt(sum([pow(a-b, 2) for a,b in list(zip(estimationOne, vals))]) / len(estimationOne))
        rootMeanSqTwo = sqrt(sum([pow(a-b, 2) for a,b in list(zip(estimationTwo, vals))]) / len(estimationTwo))
    except:
        return (84)
    printFitOne(valOneX, valTwoX, rootMeanSqOne)
    printFitTwo(valOneY, valTwoY, rootMeanSqTwo)
    print("Correlation: {:.4f}".format(rootOne))
    return (0)

def demographie(codes):
    lines = []
    tmpVals = []
    tmptab = []
    vals = []
    ret = 0;
    try:
        file = open("207demography_data.csv", "r")
        lines = file.readlines()
        lines = [line.strip().split(';') for line in lines]
        countryNames = [line[0] for line in lines if (len(line) >= 2 and line[1] in codes)]
        if len(countryNames) != len(codes):
            print("Wrong country code detected !", file=stderr)
            raise NameError(5, 'toto')
        lines = [line[2:] for line in lines if (len(line) >= 2 and line[1] in codes)]
        for line in lines:
            tmptab = []
            for x in line:
                if (x):
                    tmptab.append(int(x))
                else:
                    tmptab.append(0)
            tmpVals.append(tmptab)
        vals = tmpVals[0]
        for tmp in tmpVals[1:]:
            vals = [a+b for a,b in list(zip(vals, tmp))]
    except:
        return(84)
    countryDisplay = "{}".format(countryNames[0])
    for country in countryNames[1:]:
        countryDisplay += ", {}".format(country)
    print("Country: {}".format(countryDisplay))
    years = [i for i in range(1960, 2018)]
    ret = doCalc(vals, years)
    return (ret)
