'''
Adapted from https://github.com/PranayT17/Finding-FIRST-and-FOLLOW-of-given-grammar
by M. Leoncini, for teaching purposes only
Date: November 4, 2022

Format of the grammar file:
1) One single production per line (i.e. no alternatives on a line)
2) Terminal symbols (tokens) included in single quotes
3) Empty string denoted by 'EPS'
4) Starting symbol assumed to be the head of last production listed
Examples:

Eprime : '+' T Eprime
Eprime : 'EPS'
F : 'number' 
E : T Eprime
'''

import sys
sys.setrecursionlimit(60)

global BASE_VARIABLES, BASE_TOKENS, EPS
BASE_VARIABLES = 256
BASE_TOKENS = -1
EPS = 0

global terminals, non_terminals, productions_dict,\
    starting_symbol,tokens, variables, FIRST, FOLLOW

def symb(v):
    for name,value in {**tokens,**variables,**{'EPS': EPS}}.items():
        if value == v:
            return name
    return str(v)

def first(symb,stack=[]):
    ''' symb può essere un numero o una lista di numeri.
        Un numero ovviamente può essere la codifica di un terminale
        o di un non terminale
    '''
    global terminals,non_terminals,productions_dict,starting_symbol,EPS
    if symb in terminals:
        return {symb}
    elif symb==EPS:
        return {EPS}
    else:
        stack.append(symb)
        first_ = set()
        alternatives = productions_dict[symb]
        for alternative in alternatives:
            addeps = True
            for symb_ in alternative:
                if symb_ in stack:
                    break
                else:
                    first_2 = first(symb_,stack)
                    if EPS not in first_2:
                        first_ = first_ | first_2
                        addeps = False
                        break
                    first_ = first_ | (first_2 - {EPS})
            if addeps:
                first_ = first_ | {EPS}
        stack.pop()
        return first_

def follow(nT, EOF):
    global productions_dict, terminals, EPS
    follow_ = set()
    prods = productions_dict.items()
    if nT==starting_symbol:
        follow_ = follow_ | {EOF}
    for nt,rhs in prods:
        for alt in rhs:
            for j,symb in enumerate(alt):
                if symb == EPS:
                    break
                if symb==nT:
                    restofprod = alt[j+1:]
                    if not restofprod:
                        if nt==nT:
                            continue
                        else:
                            follow_ = follow_ | follow(nt, EOF)
                    else:
                        follow_2 = set()
                        nullify = True
                        for symb_ in restofprod:
                            first_2 = first(symb_)
                            if EPS not in first_2:
                               follow_2 = follow_2 | first_2
                               nullify = False
                               break
                            follow_2 = follow_2 | (first_2-{EPS})   
                        if nullify:
                            follow_ = follow_ | follow_2-{EOF}
                            follow_ = follow_ | follow(nt,EOF)
                        else:
                            follow_ = follow_ | follow_2
    return follow_

def read_grammar(fn):
    global rules, variables, tokens, productions, BASE_VARIABLES, BASE_TOKENS, EPS
    rules = []
    for line in open(fn,'r'):
        rules.append(line.strip())

    tokens = {}
    variables = {}
    productions = {}
    nv = BASE_VARIABLES
    nt = BASE_TOKENS
    
    tokens['tok_eof'] = nt
    nt -= 1
    for rule in rules:
        toks = rule.split(':')
        head = toks[0].strip()
        tail = toks[1].strip().split()
        prod = []
        for t in tail:
            t = t.strip()
            if t=='EPS':
                prod=[EPS]
                break
            if "'" in t:
                token = t[1:len(t)-1]
                if len(token)==1:
                    prod.append(ord(token))
                    tokens[token]=ord(token)
                else:
                    tname = 'tok_'+{"<=": "lte", ">=": "gte"}.get(token,token)
                    #tname = 'tok_'+token
                    if not tokens.get(tname,False):
                        tokens[tname] = nt
                        nt -= 1
                    prod.append(tokens[tname])
            else:
                if not variables.get(t,False):
                    variables[t] = nv
                    nv += 1
                prod.append(variables[t])
        if not variables.get(head,False):
            variables[head] = nv
            nv += 1
        productions[variables[head]] = \
            productions.get(variables[head],[])
        productions[variables[head]].append(prod)
    
    axiom = variables[rules[-1].split(':')[0].strip()]
    return tokens,variables,productions,axiom

def prettyprint():
    global FIRST, FOLLOW
    LVARS = ['Non Terminals']
    LFIRST = ['First']
    LFOLLOW = ['Follow']
    lvars = len(LVARS[0])
    lfirst = len(LFIRST[0])
    lfollow = len(LFOLLOW[0])
    for non_terminal in non_terminals:
        LVARS.append(symb(non_terminal))
        lvars = lvars if lvars>=len(LVARS[-1]) else len(LVARS[-1])
        LFIRST.append('{'+", ".join([symb(e) for e in FIRST[non_terminal]])+'}')
        lfirst = lfirst if lfirst>=len(LFIRST[-1]) else len(LFIRST[-1])
        LFOLLOW.append('{'+", ".join([symb(e) for e in FOLLOW[non_terminal]])+'}')
        lfollow = lfollow if lfollow>=len(LFOLLOW[-1]) else len(LFOLLOW[-1])
    print(f"{'Non Terminals':>{lvars+1}}{'First':>{lfirst+2}}{'Follow':>{lfollow+2}}")
    print(' ',end='')
    for _ in range(lvars+lfirst+lfollow+4):
        print('-',end='')
    print()
    for i in range(1,len(LVARS)):
        print(f"{LVARS[i]:>{lvars+1}}{LFIRST[i]:>{lfirst+2}}{LFOLLOW[i]:>{lfollow+2}}")
    
def main(grammar):
    global rules,terminals, non_terminals, productions_dict,\
        starting_symbol, tokens, variables, FIRST, FOLLOW
    
    tokens,variables,productions_dict,starting_symbol = \
        read_grammar(grammar)
    
    # Prepare for calling original procedures
    terminals = list(tokens.values())
    non_terminals = list(variables.values())
    
    FIRST = {}
    FOLLOW = {}
    
    for non_terminal in non_terminals:
        FIRST[non_terminal] = set()
    
    for non_terminal in non_terminals:
        FOLLOW[non_terminal] = set()

    for non_terminal in non_terminals:
        FIRST[non_terminal] = FIRST[non_terminal] | \
            first(non_terminal)
    
    FOLLOW[starting_symbol] = \
        FOLLOW[starting_symbol] | {tokens['tok_eof']}
    for non_terminal in non_terminals:
        FOLLOW[non_terminal] = FOLLOW[non_terminal] | \
            follow(non_terminal,tokens['tok_eof'])
    
def help():
    print("Uso: python first_and_follow.py [OPZIONI] grammar")
    print("     dove <grammar> è un file con estensione .ll1 ")
    print("Opzioni:")
    print("\t-p, stampa su stdout gli insiemi first e follow")
    print("\t-o filename, esporta tutti i dati della grammatica in un file <filename>.pickle")
    print("\t   nome default <grammar>.pickle")
    print("\t-h, stampa questo help e termina")
    
if __name__=='__main__':
    n = len(sys.argv)
    if n==1:
        print("Errore: manca l'indicazione del file con la grammatica")
        sys.exit(1)
    grammarfile = sys.argv[-1]    
    if grammarfile == "-h":
        help()
        sys.exit(0) 
    extension = grammarfile[grammarfile.rfind('.'):]
    if extension != '.ll1':
        print("Il file con la grammatica deve avere estensione .ll1")
        sys.exit(1)
    grammar = grammarfile[:grammarfile.rfind('.')]
    i = 1
    pp = False  # Per default, i simboli in first e in follow non vengono stampati
    dumpfile = grammar+'.pickle'
    while i<n-1:
        if sys.argv[i]=='-p':
            pp = True
            i+=1
        elif sys.argv[i]=='-o':
            dumpfile = sys.argv[i+1]+'.pickle'
            i+=2
        elif sys.argv[i]=='-h':
            help()
            sys.exit(0)
        else:
            print(f"Errore: opzione sconosciuta {sys.argv[i]}")
            help()
            sys.exit(1)
    main(grammarfile)   
    if pp:
        prettyprint()
    if dumpfile:
        from pickle import dump
        Object = {'rewriting_rules': rules,\
                  'variables': variables,\
                  'tokens': tokens,\
                  'productions': productions_dict,\
                  'first': FIRST,\
                  'follow': FOLLOW,
                  'base': BASE_VARIABLES,
                  'axiom': starting_symbol}
        with open(dumpfile,'wb') as f:
            dump(Object,f)
