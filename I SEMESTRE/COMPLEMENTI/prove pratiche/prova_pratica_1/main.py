from users import *

utenti_registrati = []


def stampa_menu():
    print('<------------------------------------------>\n'
          'Benvenuto nel sistema di gestione personale!\n\n'
          'Che operazione desideri fare?\n\n'
          '1. Scegli un utente registrato (s)\n'
          '2. Crea un nuovo utente (c)\n'
          '3. Esci dal programma (q)\n'
          '<------------------------------------------>\n'
          )


def stampa_menu_operazioni(utente):
    print('<------------------------------------------>\n'
          f'Benvenuto, {utente.name}!\n'
          'Che operazione desideri fare?\n\n'
          )


# main menu loop

while True:
    stampa_menu()
    inp = input("Che operazione desideri fare? (s/c/q) ")
    if inp.lower() == 's':
        print('Scegli un utente tra quelli registrati\n')
        try:
            user = scegli_utente(utenti_registrati)
            print(user)
        except ValueError as e:
            print(e)

    elif inp.lower() == 'c':
        try:
            new_utente = crea_utente(utenti_registrati)
            print(f'Creato nuovo utente: {new_utente}')
            utenti_registrati.append(new_utente)
        except ValueError as e:
            print(e)

    elif inp.lower() == 'q':
        break
    else:
        print("\n\n\nInserisci un'operazione valida\n\n\n")
