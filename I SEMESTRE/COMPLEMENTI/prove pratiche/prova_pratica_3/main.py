from pazienti import *
from datetime import date

pazienti = [Paziente('gino','suppancig'), Paziente('paolo', 'de marchis')]


def operazioni_paziente(p):
    while True:
        print(f'{p}\n' +
              '1. Inserisci un farmaco\n'
              '2. Elimina un farmaco\n'
              '3. Visualizza terapia di oggi\n'
              '4. Visualizza terapie dei giorni successivi\n'
              '5. Menu principale\n')
        try:
            op_p = int(input('Inserisci l\'operazione: '))
            if not 1 <= op_p <= 5:
                raise IndexError
        except IndexError:
            print('Inserisci un operazione valida')
        else:
            if op_p == 1:
                try:
                    nome_f = input('Inserisci il nome del farmaco: ').strip()
                    freq_f = int(input('Inserisci la frequenza di assunzione: '))
                    if len(nome_f) == 0:
                        raise ValueError
                    p.add_farmaco(nome_f, freq_f)
                except ValueError:
                    print('Errore nell\'inserimento dei dati')
            elif op_p == 2:
                if not p.pp_farmaci():
                    continue
                try:
                    freq_f = int(input('Inserisci l\'indice del farmaco da rimuovere: '))
                    if freq_f <= 0:
                        raise IndexError
                    p.remove_farmaco(freq_f - 1)
                except ValueError:
                    print('Inserisci un numero')
                except IndexError:
                    print('Indice errato')
            elif op_p == 3:
                p.terapia()
            elif op_p == 4:
                try:
                    giorni = int(input('Inserisci il numero di giorni di terapia da visualizzare (almeno 2): '))
                    if giorni <= 1:
                        raise ValueError
                    p.terapia(giorni)
                except ValueError:
                    print('Errore nell\'inserimento dei dati')
            elif op_p == 5:
                break


def visualizza_pazienti():
    while True:
        if not pazienti:
            print('Nessun paziente registrato')
            break
        else:
            for ind in range(len(pazienti)):
                print(f'{ind + 1}. {pazienti[ind]}')
            try:
                ind_paz = int(input('Scegli il paziente: '))
                if ind_paz <= 0:
                    raise IndexError
                paz = pazienti[ind_paz - 1]
            except ValueError:
                print('Inserisci un numero')
            except IndexError:
                print('Scegli un indice valido')
            else:
                operazioni_paziente(paz)
                break


def crea_scheda():
    while True:
        try:
            nome = input('Inserisci il nome del paziente: ').strip()
            cognome = input('Inserisci il cognome del paziente: ').strip()
            if len(nome) == 0 or len(cognome) == 0:
                raise ValueError
            pazienti.append(Paziente(nome, cognome))
            break
        except ValueError:
            print('Alcuni campi sono rimasti vuoti')


def esci():
    print('\nUscita dal programma')
    quit()


OPERAZIONI = [visualizza_pazienti, crea_scheda, esci]

# main loop

while True:
    print('Casa di cura - distribuzione farmaci\n'
          '1. Visualizza i pazienti in cura\n'
          '2. Crea una scheda paziente\n'
          '3. Esci')
    try:
        op = int(input('Inserisci l\'operazione: '))
        if not 1 <= op <= 3:
            raise IndexError
        print('******')
        OPERAZIONI[op - 1]()
        print('******')
    except ValueError:
        print('Inserisci un numero')
    except IndexError:
        print('Operazione non consentita')
