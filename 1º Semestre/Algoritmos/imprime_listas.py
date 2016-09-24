def imprimeListas(lista):
    nivel = 0
    def imprimeListasRec(lista,nivel):
        espaco = ""
        i = 0
        for x in lista:
            if(type(x)!= list):
                while(i<nivel):
                    espaco = espaco+"   "
                    i = i+1
                print(espaco+str(x))
            else:
                imprimeListasRec(x,nivel+1)

    return imprimeListasRec(lista,nivel)

imprimeListas(["abc","edf",12,["qwe",[1,2,[5.0,12]]],12.0])


