from operazioni import *


class Utente:
    def __init__(self, nome, cognome):
        self.nome = nome
        self.cognome = cognome
        self.operazioni = list()

    def __str__(self):
        return f'{self.cognome} {self.nome}'


def cmp_utente(self, utente):
    n1 = self.nome.lower()
    n2 = utente.nome.lower()
    c1 = self.cognome.lower()
    c2 = utente.cognome.lower()
    if c1 < c2:
        return -1
    elif c1 > c2:
        return 1
    else:
        if n1 < n2:
            return -1
        elif n1 > n2:
            return 1
        else:
            return 0
