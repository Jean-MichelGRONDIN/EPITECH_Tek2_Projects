import unittest

from functions import calcConfidenceInterval

class TestStringMethods(unittest.TestCase):

    def testconfiNineFivePfdExOne(self):
        res = calcConfidenceInterval((42.24 / 100), 1.96, 0.00046360501650165016)
        self.assertEqual(res[0], 0.3801982816535542)
        self.assertEqual(res[1], 0.4646017183464458)

    def testconfiNineNinePfdExOne(self):
        res = calcConfidenceInterval((42.24 / 100), 2.58, 0.00046360501650165016)
        self.assertEqual(res[0], 0.3668487585031479)
        self.assertEqual(res[1], 0.4779512414968521)

    def testconfiNineFivePfdExTwo(self):
        res = calcConfidenceInterval((45 / 100), 1.96, 0.002450495049504951)
        self.assertEqual(res[0], 0.35297514863614465)
        self.assertEqual(res[1], 0.5470248513638554)

    def testconfiNineNinePfdExTwo(self):
        res = calcConfidenceInterval((45 / 100), 2.58, 0.002450495049504951)
        self.assertEqual(res[0], 0.32228361402104755)
        self.assertEqual(res[1], 0.5777163859789525)

if __name__ == '__main__':
    unittest.main()