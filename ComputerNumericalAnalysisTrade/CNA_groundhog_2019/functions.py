#!/usr/bin/env  python3

from math import sqrt

def calcG(period, inputList):
    res = 0.0
    try:
        res = sum(list(map(lambda x, y: max(0, x - y), inputList[-period:], inputList[-(period + 1) : - 1]))) / period
    except (ValueError, FloatingPointError, ZeroDivisionError):
            return "nan"
    return '{:.2f}'.format(res)

def calcR(period, inputList):
    res = 0.0
    try:
        res = round((inputList[-1] / inputList[-(1 + period)] - 1) * 100)
    except (ValueError, FloatingPointError, ZeroDivisionError):
        return "nan"
    return '{}'.format(res)


def calcS(period, inputList):
    res = 0.0
    tmpAverage = 0.0
    try:
        tmpAverage = sum(inputList[-period:]) / period
        res = sqrt(sum(map(lambda x: (x - tmpAverage)**2, inputList[-period:])) / period)
    except (ValueError, FloatingPointError, ZeroDivisionError):
        return "nan"
    return '{:.2f}'.format(res)

def checkSwitchOccurs(period, inputList):
    res = ""
    now = 0.0
    before = 0.0
    try:
        now = round((inputList[-1] / inputList[-(1 + period)] - 1) * 100)
        before = round((inputList[-2] / inputList[-(2 + period)] - 1) * 100)
        if (abs(before + now) != abs(before) + abs(now)):
            res = "      a switch occurs"
    except (ValueError, FloatingPointError, ZeroDivisionError):
        return ""
    return res


def calcGRS(period, inputList, nbSwitchs):
    gVal = "nan"
    rVal = "nan"
    sVal = "nan"
    switchMsg = ""
    ret = 0
    if (len(inputList) > period):
        gVal = calcG(period, inputList)
        rVal = calcR(period, inputList)
    if (len(inputList) >= period):
        sVal = calcS(period, inputList)
    if (len(inputList) > period + 1):
        switchMsg = checkSwitchOccurs(period, inputList)
    if (switchMsg != ""):
        ret = 1
    print("g={}      r={}%      s={}{}".format(gVal, rVal, sVal, switchMsg))
    return (ret)

def calcMobileAvg(period, inputList):
    res = 0.0
    try:
        res = sum(inputList[-period:]) / period
    except (ValueError, FloatingPointError, ZeroDivisionError):
        return None
    return res

def calcMobileDev(period, inputList):
    res = 0.0
    tmpAverage = 0.0
    try:
        tmpAverage = sum(inputList[-period:]) / period
        res = sqrt(sum(map(lambda x: (x - tmpAverage)**2, inputList[-period:])) / period)
    except (ValueError, FloatingPointError, ZeroDivisionError):
        return None
    return res
    # return '{:.2f}'.format(res)

def printExecLog(nbSwitchs, inputList, switchPosList, period):
    sortedList = []
    resList = []
    print("Global tendency switched {} times".format(nbSwitchs))
    switchPosList = list(map(lambda x : abs(x - 0.5), switchPosList))
    sortedList = sorted(switchPosList)
    resList = sortedList[-5:]
    resList = list(map(lambda x : inputList[switchPosList.index(x) + period  - 1], resList))
    print("5 weirdest values are {}".format(resList[::-1]))


def groundhog(period):
    inputVal = input()
    inputList = []
    nbSwitchs = 0
    mobileAvgList = []
    mobileDevList = []
    upLine = 0.0
    downLine = 0.0
    switchPosList = []
    while (inputVal != "STOP"):
        try:
            inputList.append(float(inputVal))
            nbSwitchs += calcGRS(period, inputList, nbSwitchs)
        except ValueError:
            return (84)
        if (len(inputList) >= period):
            mobileDevList.append(calcMobileDev(period, inputList))
            mobileAvgList.append(calcMobileAvg(period, inputList))
            mobileDevList = list(filter(None, mobileDevList))
            mobileAvgList = list(filter(None, mobileAvgList))
        try:
            downLine = mobileAvgList[-1] - 2 * mobileDevList[-1]#float(mobileDevList[-1])
            upLine = mobileAvgList[-1] + 2 * mobileDevList[-1]#float(mobileDevList[-1])
            switchPosList.append((inputList[-1] - downLine) / (upLine - downLine))
        except (IndexError, ZeroDivisionError):
            pass
        inputVal = input()
    if (len(inputList) < period):
        return (84)
    printExecLog(nbSwitchs, inputList, switchPosList, period)
    return (0)