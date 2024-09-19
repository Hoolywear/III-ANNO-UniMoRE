# Operazioni base, sottomenu, costanti
from functools import cmp_to_key
from datetime import datetime

from utenti import *

SEP_ROW = '<-------------------------------------->\n'
utenti = [Utente('Iacopo', 'Ruzzier'), Utente('Maria', 'de Fornasari'), Utente('Rachele', 'Olivo')]
utenti.sort(key=cmp_to_key(cmp_utente))


def valida_datetime():
    try:
        g = int(input('Inserisci il giorno: '))
        m = int(input('Inserisci il mese: '))
        a = int(input('Inserisci l\'anno: '))
        return datetime.date(a, m, g)
    except ValueError:
        print('Alcuni parametri della data non sono validi')
        raise ValueError


def stampa_utenti(lista_utenti):
    if not lista_utenti:
        print('Nessun utente registrato')
    else:
        for ind in range(len(lista_utenti)):
            print(f'{ind}. {lista_utenti[ind]}')


def menu_seleziona_utente():
    print(SEP_ROW + 'Seleziona utente\n' + SEP_ROW)
    stampa_utenti(utenti)
    try:
        utente_i = int(input('Scegli l\'utente: '))
        print(SEP_ROW)
        if utente_i < 0:
            raise IndexError
        utente = utenti[utente_i]
        menu_op_utente(utente)
    except ValueError:
        print('Inserisci un numero!')
    except IndexError:
        print('Numero non valido!')


def menu_op_utente(utente):
    while True:
        print(SEP_ROW + f'Benvenuto, {utente.nome}!\n'
                        'Che operazione desideri fare?\n'
                        '0. Registra un\'operazione\n'
                        '1. Visualizza lo storico delle operazioni\n'
                        '2. Cerca per data\n'
                        '3. Ritorna al menu principale\n' +
              SEP_ROW
              )
        try:
            op_u = int(input('Inserisci l\'operazione da svolgere: '))
            print(SEP_ROW)
            if op_u < 0 or op_u > 3:
                raise IndexError
        except ValueError:
            print('Inserisci un numero!')
        except IndexError:
            print('Operazione non valida!')
        else:
            if op_u == 0:
                aggiungi_operazione(utente)
            elif op_u == 1:
                stampa_operazioni(utente.operazioni)
            elif op_u == 2:
                ricerca_operazioni(utente.operazioni)
            elif op_u == 3:
                break


def aggiungi_operazione(utente):
    while True:
        op_t = input('Inserisci un (P)relievo o un (V)ersamento: ').lower()
        if op_t not in ['p', 'v']:
            print("Tipo operazione non valido!")
        else:
            try:
                imp = int(input('Inserisci l\'importo: '))
                data = valida_datetime()
                utente.operazioni.append(crea_operazione(op_t, imp, data))
                break
            except ValueError as e:
                print(e)


def ricerca_operazioni(operazioni):
    while True:
        print(SEP_ROW + 'Ricerca operazioni per data\n' + SEP_ROW)
        try:
            print('Inserisci la data di inizio ricerca')
            data_inizio = valida_datetime()
            print('Inserisci la data di fine ricerca')
            data_fine = valida_datetime()
            op_richieste = list(filter(lambda x: data_inizio <= x.data <= data_fine, operazioni))
            stampa_operazioni(op_richieste)
            tot_v = 0
            tot_p = 0
            for op_r in op_richieste:
                if isinstance(op_r, Prelievo):
                    tot_p += op_r.importo
                else:
                    tot_v += op_r.importo
            print(SEP_ROW +
                  f'Totale prelievi: {tot_p}€\n'
                  f'Totale versamenti: {tot_v}€\n' +
                  SEP_ROW)
        except ValueError:
            print("Alcuni parametri non sono corretti!")


def menu_crea_utente():
    while True:
        print(SEP_ROW + 'Crea nuovo utente\n' + SEP_ROW)
        try:
            nome = input('Inserisci il nome dell\'utente: ').strip()
            cognome = input('Inserisci il cognome: ').strip()
            if len(nome) == 0 or len(cognome) == 0:
                raise ValueError
            utenti.append(Utente(nome, cognome))
            utenti.sort(key=cmp_to_key(cmp_utente))
            break
        except ValueError:
            print('Alcuni campi sono rimasti vuoti!')


def esci():
    print('Esco dal programma')
    quit()


OPERAZIONI = [menu_seleziona_utente, menu_crea_utente, esci]

# Main menu loop

while True:
    print(SEP_ROW +
          'Gestione delle transazioni bancarie\n'
          'Che operazione desideri fare?\n'
          '0. Scegli utente\n'
          '1. Crea utente\n'
          '2. Esci dal programma\n' +
          SEP_ROW)
    try:
        op = int(input('Inserisci l\'operazione da svolgere: '))
        print(SEP_ROW)
        if op < 0:
            raise IndexError
        op_menu = OPERAZIONI[op]
        op_menu()
    except ValueError:
        print('Inserisci un numero!')
    except IndexError:
        print('Operazione non valida!')
