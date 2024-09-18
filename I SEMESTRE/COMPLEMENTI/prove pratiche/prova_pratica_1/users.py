class Utente:
    def __init__(self, nome, cognome, stipendio):
        self.nome = nome
        self.cognome = cognome
        self.stipendio = stipendio

    def __str__(self):
        return f'{self.nome} {self.cognome}'


class Subordinato(Utente):
    def __init__(self, nome, cognome, stipendio, responsabile):
        super().__init__(nome, cognome, stipendio)
        self.responsabile = responsabile

    def __str__(self):
        return f'(SUBORDINATO) {super().__str__()}'


class Responsabile(Utente):
    def __str__(self):
        return f'(RESPONSABILE) {super().__str__()}'


def stampa_utenti(utenti):
    for ind in range(len(utenti)):
        print(f'{ind}. {utenti[ind]}')


def scegli_utente(utenti):
    if len(utenti) > 0:
        while True:
            stampa_utenti(utenti)
            try:
                scelta = int(input('Inserisci il numero dell\'utente: '))
                return utenti[scelta]
            except IndexError:
                print('Numero utente non valido!')
            except ValueError:
                print('Inserisci un numero!')
    else:
        raise ValueError('Nessun utente registrato')


def scegli_ruolo():
    while True:
        scelta = input('Ruolo del nuovo utente ((s)ubordinato/(r)esponsabile): ')
        if scelta.lower() == 's':
            return 'Subordinato'
        elif scelta.lower() == 'r':
            return 'Responsabile'
        else:
            print('Valore non valido\n')


def crea_utente(utenti):
    print('Inserisci i dati di base del nuovo utente')
    n = input("Nome del nuovo utente: ").strip()
    c = input("Cognome del nuovo utente: ").strip()
    if len(n) <= 0 or len(c) <= 0:
        raise ValueError('Alcuni campi sono vuoti! Creazione utente fallita')
    try:
        s = int(input("Stipendio orario del nuovo utente: "))
    except ValueError:
        raise ValueError('Inserisci un valore numerico!')
    r = scegli_ruolo()

    if r == 'Responsabile':
        return Responsabile(n, c, s)
    else:
        print('Scegli uno tra i responsabili da assegnare al nuovo utente')
        try:
            resp = scegli_utente(list(filter(lambda x: isinstance(x, Responsabile), utenti)))
            return Subordinato(n, c, s, resp)
        except ValueError:
            raise ValueError('Non ci sono responsabili! Creazione utente fallita')
