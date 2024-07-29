import pickle
from pickle_es import Prova

p = pickle.load(open('prova.pickle', 'rb'))

p.metodo()
p.metodo2()