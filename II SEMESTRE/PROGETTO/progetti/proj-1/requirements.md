# 24 marzo - raccolta requisiti

incontro con il cliente

recupera tutto il contesto

- lingue per localizzazione: italiano e inglese
- uso di credenziali gia in uso fornite dalla regione (api?)
- accesso agli archivi
- fase di load dei dati preesistenti &rarr; da file excel a db
- check sugli inserimenti nuovi se il dato non e valido, solo warning per quelli preesistenti (errore loro preesistente noi non possiamo farci nulla)
- 10.000 budget, dai finanziamenti , bando europeo al quale possiamo partecipare anche noi
- web app e app mobile
- sistema di backup attuale: drive, ogni dipendente ha il suo file excel che dovrebbe essere backuppato ogni giorno (ma non sempre) &rarr; problemi di consistenza al momento &rarr; vogliamo per questo un'interfaccia comune ma senza dare la possibilita di scaricare i file
- rettangolo o quadrato &rarr; destinazione d'uso, lati, storico dei proprietari (i dati presenti)
- utenti:
    - proprietario terriero: persona fisica, societa, ente eccetera (quindi CF o P.IVA) &rarr; dati dei suoi terreni, puo modificare il nome del terreno, modificare il contatto per ciascun terreno (se non e presente riferimento, fanno testo i dati del proprietario, che **non sono modificabili**); richiesta di cambio destinazione uso (non puo modificare direttamente, ma puo richiederla); richiesta verifica dimensione &rarr; finora si faceva telefonicamente, vogliamo alleggerire
    - dipendenti del comune: possono cambiare tutto, tranne il proprietario del terreno
    - superuser del comune (noi?): tutto (anche il cambio proprietario, che è un'operazione complessa che richiede involving anche altri enti statali o regionali eccetera)
- software pensato per uso interno al comune: le procedure legali per il momento verranno gestite a manina, una volta ricevuta ad es la richiesta di cambio destinazione uso &rarr; **magari in futuro automatizzeremo anche questo**, ma per ora essendo questa un'app a uso amministrativo regionale e non da tutto il ministero, no
- formazione utenti: necessaria ai dipendenti del comune naturalmente, ma la parte utente *normale* dovra ovviamente essere piu semplice possibile in quanto non possiamo chiedere a questi utenti di fare formazione per usare il sw
    - eventualmente possibile far fare formazione ad un'altra azienda specializzata, se necessario (di solito funziona cosi)
- sicurezza: rec
- interfacce: **web app sicuramente**, in quanto non possibile installare roba su tutte le macchine della regione &rarr; se la mobile app non costa molto, tipo 1k entro luglio, benissimo &rarr; vogliamo diventare la regione più digitalizzata d'italia, quindi poter proporre al ministero qualcosa di bello (e far bella figura), e poi comunque sareste voi a vendere a tutto il resto dell'italia
- backup: giornaliero automatico, sui server del comune
- struttura di un singolo file excel: codice appezzamento, destinazione uso, dimensione (lati), creazione appezzamento, valore (dinamico calcolato in base a codice destinazione e dimensione e lat long e creazione)
- nessun linguaggio di programmazione preesistente, nessuna piattaforma
- good practice: mai chiedere al cliente che tecnologie usare e su cosa implementare il sw (non deve deciderlo lui) - nel caso in cui un cliente imponga un vincolo, deve risultare scritto nero su bianco, altrimenti poi sono cazzi tuoi
- funzionalità: modifica appezzamenti, **richiesta** di inserimento (da parte del proprietario) - deve passare attraverso di noi che poi gestiamo le comunicazioni con agenzia entrate; eliminazione non possibile
- fusione appezzamenti di terreno: ? il cliente non ci aveva pensato &rarr; bisogna ragionare e prevedere uno stato **archiviato** o simile (ci pensiamo piu avanti)
- morte proprietario: segnalato da agenzia delle entrate
- ricorda: noi calcoliamo solo le tasse e basta, non gestiamo le altre questioni (e il sistema serve a questo alla fine) es pagamenti (non li gestiremo noi in ogni caso)
- sala server della regione
- utenti esteri (fuori italia): caso particolare, non si applica per societa o aziende (devi avere per forza partita iva in italia) ma ci sono casi sporadici in cui qualche persona singola ha un campo in italia - al momento non viene gestita se non a mano, vedete voi come credete si possa gestire (es. creare istanze di account spid senza codice fiscale, ma bisogna vedere con agenzia entrate)
- gestione login: login come utente regionale (login regionale) oppure spid? oppure fare un form unico di login (form == "maschera" secondo il cliente) 
- niente aftermarket: considera soltanto fase di devel testing e debug considerate, dopo se vogliono altre funzionalita si fara un altro documento
- proprieta intellettuale di questo software: nostra? il nostro interesse e la rivendita, quello del cliente invece di tenerselo e non darlo alle altre regioni
- &rarr; bisogna cercare di capire bene la questione e gestirla
    - se vuole il codice in esclusiva sono soldi aggiuntivi (non succede quasi mai)
- va fatto il design dei test sicuramente
- user acceptance test
- anagrafica esterna , e intestazione non sono modificabili neppure da superuser (sono quelle cose gestite da enti esterni)
- il cliente ha parlato di machine learning, non sa cosa significa, ci chiede cosa potremmo proporgli, ad es per un sistema di statistiche (ovviamente fuori budget)
- numero utenti (utenti dipendenti, e superuser) circa 20 persone; utenti proprietari ordine delle migliaia
- numero terreni 
- obbligatorio tenere traccia di tutte le modifiche fatte al db
- modifica proprietario o qualsiasi modifica che impone dei documenti: ci occupiamo solamente dell'inizio della procedura, e in ogni caso solo a mano - poi passiamo i documenti direttamente agli enti esterni (non ce ne occupiamo noi)
