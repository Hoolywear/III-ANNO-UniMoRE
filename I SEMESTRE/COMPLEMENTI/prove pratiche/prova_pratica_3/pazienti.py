from farmaci import *


class Paziente:
    def __init__(self, nome, cognome):
        self.__nome = nome
        self.__cognome = cognome
        self.farmaci = list()

    def __str__(self):
        return f'{self.__nome} {self.__cognome}'

    @property
    def nome(self):
        return self.__nome

    @property
    def cognome(self):
        return self.__cognome

    def add_farmaco(self, nome, frequenza):
        self.farmaci.append(Farmaco(nome, frequenza))

    def remove_farmaco(self, ind):
        return self.farmaci.pop(ind)

    def pp_farmaci(self, g=0, show_ind: bool = True):
        if not self.farmaci:
            print('Nessun farmaco')
            return False
        else:
            for ind in range(len(self.farmaci)):
                p_ind = '' if not show_ind else ind + 1
                if g % self.farmaci[ind].frequenza == 0:
                    print(f'{p_ind}: {self.farmaci[ind]}')
            return True

    def terapia(self, fine=1):
        for g in range(fine):
            print(f'######################## {g} ############################')
            self.pp_farmaci(g=g, show_ind=False)
        print('######################################################')
