class Cane:
    def __init__(self, sesso, zampe=4, coda=True, eta=0):
        self.sesso = sesso
        self.zampe = zampe
        self.coda = coda
        self.eta = eta
        self.malato = True
        self.spavaldo = False

    def abbaia(self):
        print('Sto abbaiando')

    def camminare(self):
        return 10

def stessoLuogo(cane1, cane2):
    return cane1.eta == cane2.eta


if __name__ == "__main__":
    c = Cane('M')
    c.abbaia()