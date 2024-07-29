#soluzione degli esercizi descrittori e property
def myproperty(fun):
    class D:
        def setter(self, settfun):
            self.setfun = settfun
        def __set__(self, instance, value):
            self.setfun(instance, value)
        def __get__(self, instance, owner):
            return fun(instance)
    return D()

class Malato:
    def __init__(self):
        pass

    def __get__(self, instance, owner):
        if instance.spavaldo:
            return False
        return instance.__dict__.get('malato')

    def __set__(self, instance, value):
        instance.__dict__['malato'] = value


class Animale:
    malato = Malato()
    def __init__(self, sesso, zampe=4, coda=True, eta=0):
        self.sesso = sesso
        self.zampe = zampe
        self.coda = coda
        self.eta = eta
        self.malato = True
        self.spavaldo = False

    @myproperty
    def prova(self):
        return "ciao"

    @prova.setter
    def setprova(self, value):
        print("OK!")

    def __add__(self, other):
        if type(self) == type(other) and self.sesso != other.sesso:
            return type(self)('F')
        return None


class Cane(Animale):
    def abbaia(self):
        print('Sto abbaiando')


class Gatto(Animale):
    def miagola(self):
        print('Miao')

cane = Cane('M')
gatto = Gatto('M')

print(cane.malato)
print(gatto.malato)
cane.spavaldo = True
print(cane.malato)
print(gatto.malato)


print(cane.prova)
cane.prova = 10