import pickle

matrice = [[1, 2, 3],
           [4, 5, 6]]

with open('matrice.txt', 'w') as fd:
    for row in matrice:
        for elem in row:
            fd.write(str(elem)+' ')
        fd.write('\n')

matrice2 = []
with open('matrice.txt', 'r') as fd:
    for line in fd:
        matrice2.append(list(map(int, line.split())))

with open('matrice.bin', 'wb') as fd:
    fd.write(bytes([len(matrice2), len(matrice2[0]), *[x2 for x in matrice2 for x2 in x]]))

matrice3 = []
with open('matrice.bin', 'rb') as fd:
    b = fd.read()
    row = b[0]
    col = b[1]
    for i in range(row):
        r = []
        for k in range(col):
            r.append(b[2+(i*col+k)])
        matrice3.append(r)

pickle.dump(matrice, open("matrice.pickle", "wb"))