class Gatto:
    def __init__(self, sesso, zampe=4, coda=True, eta=0):
        self.sesso = sesso
        self.zampe = zampe
        self.coda = coda
        self.eta = eta
        self.malato = True
        self.spavaldo = False

    def miagola(self):
        print('Miao')


def stessoLuogo(gatto1, gatto2):
    return gatto1.eta == gatto2.eta

if __name__ == "__main__":
    c = Gatto('M')
    c.miagola()