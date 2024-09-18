from users import *
from requests import *

utenti_registrati = []

# inizializzazione utenti placeholder
utenti_registrati.append(Responsabile('Giorgio', 'Giorgi', 15))
utenti_registrati.append(Subordinato('Paolo', 'di Paolo', 10, utenti_registrati[0]))
utenti_registrati[1].richieste.append(Richiesta(utenti_registrati[1], utenti_registrati[0], 8))
utenti_registrati[0].richieste.append(utenti_registrati[1].richieste[0])


def stampa_menu():
    print('<------------------------------------------>\n'
          'Benvenuto nel sistema di gestione personale!\n\n'
          'Che operazione desideri fare?\n\n'
          '1. Scegli un utente registrato (s)\n'
          '2. Crea un nuovo utente (c)\n'
          '3. Esci dal programma (q)\n'
          '<------------------------------------------>\n'
          )


def stampa_menu_operazioni(user):
    print('<------------------------------------------>\n'
          f'Benvenuto, {user.nome}!\n'
          'Che operazione desideri fare?\n\n'
          '1. Visualizza le richieste di pagamento'
          )
    if isinstance(user, Responsabile):
        print('2. Ritorna al menu principale')
    else:
        print('2. Fai una nuova richiesta\n'
              '3. Ritorna al menu principale')


def menu_operazioni(user):
    while True:
        stampa_menu_operazioni(user)
        try:
            op = int(input('Scegli l\'operazione da eseguire: '))
        except ValueError:
            print('Inserisci un numero!')
        else:
            if op == 1:
                user.stampa_richieste()
            elif isinstance(user, Responsabile):
                if op == 2:
                    break
                else:
                    print('Scelta non valida')
            else:
                if op == 2:
                    try:
                        ore_rich = int(input('Inserisci il numero di ore: '))
                        aggiungi_richiesta(user, ore_rich)
                    except ValueError:
                        print('Inserisci un numero!')
                elif op == 3:
                    break
                else:
                    print('Scelta non valida')


# Main menu loop

while True:
    stampa_menu()
    inp = input("Che operazione desideri fare? (s/c/q) ")
    if inp.lower() == 's':  # scelta utente per operazioni
        print('Scegli un utente tra quelli registrati\n')
        try:
            op_user = scegli_utente(utenti_registrati)
            menu_operazioni(op_user)
        except ValueError as e:
            print(e)

    elif inp.lower() == 'c':  # crea nuovo utente
        try:
            new_user = crea_utente(utenti_registrati)
            print(f'Creato nuovo utente: {new_user}')
            utenti_registrati.append(new_user)
        except ValueError as e:
            print(e)

    elif inp.lower() == 'q':  # esci dal programma
        break
    else:
        print("\n\n\nInserisci un'operazione valida\n\n\n")
