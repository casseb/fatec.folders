def pesquise(lista,valor):
    stringPesquisa = ""
    for x in lista:
        stringPesquisa = stringPesquisa+str(x)
    return stringPesquisa.find(str(valor))

L=[10,20,25,30]
print(pesquise(L,25))
print(pesquise(L,27))

