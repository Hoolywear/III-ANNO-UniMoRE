import unittest
import io
import sys

from animali.cane import Cane



class TestCane(unittest.TestCase):
    def test_cane(self):
        c = Cane('F')
        self.assertEqual('F', c.sesso)
        self.assertEqual(True, c.malato)
        self.assertEqual(0, c.eta)
        self.assertEqual(False, c.spavaldo)
        self.assertEqual(True, c.coda)
        self.assertEqual(4, c.zampe)

        c = Cane('M', 2, False, 10)
        self.assertEqual('M', c.sesso)
        self.assertEqual(True, c.malato)
        self.assertEqual(10, c.eta)
        self.assertEqual(False, c.spavaldo)
        self.assertEqual(False, c.coda)
        self.assertEqual(2, c.zampe)

    def test_cane_abbaia(self):
        capturedOutput = io.StringIO()
        sys.stdout = capturedOutput
        c = Cane('F')
        c.abbaia()
        o = str(capturedOutput.getvalue().strip())
        sys.stdout = sys.__stdout__
        self.assertEqual("Sto abbaiando",o)

    def test_cane_camminare(self):
        c = Cane('F')
        res = c.camminare()
        self.assertEqual(10, res)



if __name__ == '__main__':
    unittest.main()