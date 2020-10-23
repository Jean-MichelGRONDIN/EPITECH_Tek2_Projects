import unittest

from functions import calcMean, calcStdDev

class TestStringMethods(unittest.TestCase):

    def testMeanCalc(self):
        self.assertAlmostEqual(calcMean(12001, 297514, 299042), 297514.13, places=2)

    def testcalcStdDev(self):
        self.assertAlmostEqual(calcStdDev(12000, 297514, 4363, 299042), 4362.84, places=2)

    # def setUp(self):
    #     self.widget = Widget('The widget')

    # def test_isupper(self):
    #     self.assertTrue('FOO'.isupper())
    #     self.assertFalse('Foo'.isupper())

    # def test_split(self):
    #     s = 'hello world'
    #     self.assertEqual(s.split(), ['hello', 'world'])
    #     # check that s.split fails when the separator is not a string
    #     with self.assertRaises(TypeError):
    #         s.split(2)

if __name__ == '__main__':
    unittest.main()