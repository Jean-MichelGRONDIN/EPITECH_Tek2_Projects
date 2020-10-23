##
## EPITECH PROJECT, 2020
## CNA_trade_2019
## File description:
## BotClass
##

from sys import stderr

def getWhatIsAfter(str, after):
    res = ""
    try:
        res = str[(len(after) + 1):]
    except:
        return ""
    return res

def getFloatAfter(str, after):
    res = 0.0
    try:
        res = float(str[(len(after) + 1):])
    except:
        return None
    return res

def startIdentifier(str, start):
    res = False
    try:
        if (str[:-(len(str) - len(start))] == start):
            res = True
    except:
        return False
    return res

class candle():
    def __init__(self, format, serialized):
        self.format = format
        self.pair = ""
        self.date = ""
        self.high = 0.0
        self.low = 0.0
        self.open = 0.0
        self.close = 0.0
        self.volume = 0.0
        formatTab = format.split(",")
        candledata = serialized.split(",")
        i = 0
        for tmp in formatTab:
            if (tmp == "pair"):
                self.pair = candledata[i]
            if (tmp == "date"):
                self.date = candledata[i]
            if (tmp == "high"):
                self.high = float(candledata[i])
            if (tmp == "low"):
                self.low = float(candledata[i])
            if (tmp == "open"):
                self.open = float(candledata[i])
            if (tmp == "close"):
                self.close = float(candledata[i])
            if (tmp == "volume"):
                self.volume = float(candledata[i])
            i = i + 1
    def increasing(self):
        if (self.close > self.open):
            return (True)
        return (False)
    def average(self):
        res = (self.close + self.open) / 2
        return res

class TradingBot():
    def __init__(self):
        self.playerName = getWhatIsAfter(self.getInput(), "settings player_names")
        self.botName = getWhatIsAfter(self.getInput(), "settings your_bot")
        self.timebank = getFloatAfter(self.getInput(), "settings timebank")
        self.timePerMove = getFloatAfter(self.getInput(), "settings time_per_move")
        self.candleInterval = getFloatAfter(self.getInput(), "settings candle_interval")
        self.candleFormat = getWhatIsAfter(self.getInput(), "settings candle_format")
        self.candleTotal = getFloatAfter(self.getInput(), "settings candles_total")
        self.candleGiven = getFloatAfter(self.getInput(), "ssettings candles_given")
        self.initialStack = getFloatAfter(self.getInput(), "settings initial_stack")
        self.transactionFee = getFloatAfter(self.getInput(), "settings transaction_fee_percent")
        self.btcStack = 0.0
        self.ethStack = 0.0
        self.usdtStack = 0.0
        self.candles = []
        self.candlesBTH_ETH = []
        self.candlesUSDT_ETH = []
        self.candlesUSDT_BTC = []
    def getInput(self):
        res = ""
        try:
            res = input()
        except:
            return "nan"
        return res
    def updateStacks(self, cmd):
        vals = getWhatIsAfter(cmd, "update game stacks")
        tab = vals.split(",")
        for val in tab:
            if (startIdentifier(val, "USDT")):
                self.usdtStack = float(val.split(":")[1])
            if (startIdentifier(val, "BTC")):
                self.btcStack = float(val.split(":")[1])
            if (startIdentifier(val, "ETH")):
                self.ethStack = float(val.split(":")[1])
    def addNewCandle(self, candleStr):
        datas = candleStr.split(";")
        for data in datas:
            newCandle = candle(self.candleFormat, data)
            if (newCandle.pair == "BTC_ETH"):
                self.candlesBTH_ETH.append(newCandle)
            if (newCandle.pair == "USDT_ETH"):
                self.candlesUSDT_ETH.append(newCandle)
            if (newCandle.pair == "USDT_BTC"):
                self.candlesUSDT_BTC.append(newCandle)
    def buyOrSell(self, candles):
        last = candles[-1].average()
        min = last
        max = last
        pair = candles[0].pair
        close = candles[0].close
        for candle in candles:
            tmp = candle.average()
            if (min > tmp):
                min = tmp
            if (max < tmp):
                max = tmp
        try:
            res = (last - min) / (max - min)
            res = res * 100
        except ZeroDivisionError:
            res = 0
        if (res > 60):
            self.sell(pair, close)
            return (1)
        if (res < 40 and self.buy(pair, close) == True):
            return (1)
        return 0
    def buy(self, pair, close):
        if (startIdentifier(pair, "USDT") == True and self.usdtStack > 0.0001):
            print("buy {} {:f}".format(pair, self.usdtStack / close))
            return True
        if (startIdentifier(pair, "BTC") == True and self.btcStack > 0.0001):
            print("buy {} {:f}".format(pair, self.btcStack / close))
            return True
        if (startIdentifier(pair, "ETH") == True and self.ethStack > 0.0001):
            print("buy {} {:f}".format(pair, self.ethStack / close))
            return True
        return False
    def sell(self, pair, close):
        print("pass")
    def action(self):
        allCandles = [self.candlesBTH_ETH, self.candlesUSDT_BTC, self.candlesUSDT_ETH]
        for candles in allCandles:
            if (self.buyOrSell(candles) != 0):
                return
        print("pass")#, end="\n"
    def run(self):
        inputLine = self.getInput()
        while (inputLine):
            if (startIdentifier(inputLine, "action order") == True):
                self.action()
            if (startIdentifier(inputLine, "update game next_candles") == True):
                self.addNewCandle(getWhatIsAfter(inputLine, "update game next_candles"))
            if (startIdentifier(inputLine, "update game stacks") == True):
                self.updateStacks(inputLine)
            inputLine = self.getInput()
