import random
import os

print(
    'Please save initial files and sure where you should use this program...')
input('press any keys....')


def List_Ogg_Deal(fpath=None):
    if fpath == None:
        fpath = os.getcwd()
    flist1 = [fname for fname in os.listdir(fpath)
              if os.path.isfile(fname)
              if not fname.endswith('.py')]
    flist2 = [fname for fname in flist1]
    random.shuffle(flist2)
    for i in range(len(flist1)):
        os.rename(flist1[i], '0' + flist2[i])
        print(flist1[i], 'rename as ', flist2[i])
    for i in range(len(flist2)):
        os.rename('0' + flist2[i], flist2[i])

List_Ogg_Deal()
input('press any keys....')
