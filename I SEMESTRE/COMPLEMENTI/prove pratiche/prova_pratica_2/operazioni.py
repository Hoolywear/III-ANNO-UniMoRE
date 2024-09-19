import datetime


class Operazione:
    def __init__(self, imp, data):
        self.__importo = imp
        self.__data = data

    def __str__(self):
        return f'{self.__importo}€ in data {self.data}'

    @property
    def importo(self):
        return self.__importo

    @property
    def data(self):
        return self.__data


class Prelievo(Operazione):
    def __str__(self):
        return f'Prelievo di {super().__str__()}'


class Versamento(Operazione):
    def __str__(self):
        return f'Versamento di {super().__str__()}'


def stampa_operazioni(operazioni):
    if not operazioni:
        print('Non ci sono operazioni')
    else:
        for op in operazioni:
            print(op)


def crea_operazione(tipo, imp, data=datetime.date.today()):
    if tipo == 'p':
        return Prelievo(imp, data)
    elif tipo == 'v':
        return Versamento(imp, data)
    else:
        return None
