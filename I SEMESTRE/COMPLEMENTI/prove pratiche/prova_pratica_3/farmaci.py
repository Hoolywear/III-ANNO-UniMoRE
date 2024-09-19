class Farmaco:
    def __init__(self, nome, frequenza):
        self.__nome = nome
        self.__frequenza = frequenza

    def __str__(self):
        return f'{self.__nome} (ogni {self.__frequenza} giorni)'

    @property
    def nome(self):
        return self.__nome

    @property
    def frequenza(self):
        return self.__frequenza
