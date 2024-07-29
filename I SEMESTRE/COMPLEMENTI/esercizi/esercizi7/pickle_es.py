import pickle

class Prova:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def metodo(self):
        print("a = " + str(self.a))

    def metodo2(self):
        print("b = " + str(self.b))

    def __getstate__(self):
        return {"a":self.a}

p = Prova(10, 20)
pickle.dump(p, open("prova.pickle", 'wb'))

