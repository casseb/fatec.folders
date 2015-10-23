#Função que retorna número aleatório entre um número e outro

def sorteioN(nInicio,nFim):

    import random

    numeros = []
    while(nInicio<=nFim):
        numeros.append(nInicio)
        nInicio = nInicio+1

    return random.choice(numeros)




#Função que retorna um array de numeros aleatorios

def listaNumeros(quantNumeros,nInicio,nFim):
    numeros = []
    cont = 0
    while(cont<quantNumeros):
        numero = sorteioN(nInicio,nFim)
        if(numero not in numeros):
            numeros.append(numero)
        cont = cont+1
    numeros.sort()
    return numeros



#Função que compara duas listas retornando quantos tem em comum

def comparaNumeros(lista1,lista2):
    cont = 0
    quant = 0
    while(cont<len(lista1)):
        if(lista1[cont] in lista2):
            quant = quant+1
        cont = cont+1
    return quant


listaA = listaNumeros(100,1,100)
listaB = listaNumeros(5,0,20)
emComum = comparaNumeros(listaA,listaB)

print(listaA)
print(listaB)
print(str(emComum))











