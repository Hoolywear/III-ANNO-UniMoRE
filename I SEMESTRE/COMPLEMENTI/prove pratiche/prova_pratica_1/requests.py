class Richiesta:
    STATI = ['In attesa', 'Accettato', 'Negato']

    def __init__(self, user, resp, ore):
        self.__stato = self.STATI[0]
        self.__user = user
        self.__responsabile = resp
        self.__ore = ore
        self.__compenso = ore * user.stipendio

    def __str__(self):
        return f'[{self.__stato}] {self.__ore} ore, {self.__compenso} €'

    @property
    def stato(self):
        return self.__stato

    @property
    def user(self):
        return self.__user

    @property
    def responsabile(self):
        return self.__user

    @property
    def ore(self):
        return self.__ore

    @property
    def compenso(self):
        return self.__compenso

    def accetta(self):
        self.__stato = self.STATI[1]
        return self.__stato

    def nega(self):
        self.__stato = self.STATI[2]
        return self.__stato


def aggiungi_richiesta(user, ore):
    try:  # creo la richiesta e la aggiungo alle liste del subordinato e del responsabile
        new_richiesta = Richiesta(user, user.responsabile, ore)
        user.richieste.append(new_richiesta)
        user.responsabile.richieste.append(new_richiesta)
        print('Richiesta andata a buon fine!')
    except ValueError:
        print(f'Errore nella creazione della richiesta')
