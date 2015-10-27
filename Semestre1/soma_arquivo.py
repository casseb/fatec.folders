#Funções de Soma de par, soma de impar e média aritmética
def somaPar(numeros):
    resultado = 0
    for numero in numeros:
        if(numero%2==0):
            resultado = resultado+numero
    return resultado

def somaImpar(numeros):
    resultado = 0
    for numero in numeros:
        if(numero%2!=0):
            resultado = resultado+numero
    return resultado

def media(numeros):
    return sum(numeros)/len(numeros)



#adquirindo conteudo do arquivo
entrada = open('entrada.in')
linhas = entrada.readlines()
entrada.close()

#criando e preenchendo dicionário numeros
numeros = {}
for linha in linhas:
    listaString = linha[2:].rstrip().split(';')
    listaInt = []
    for numeroTemp in listaString:
        listaInt.append(int(numeroTemp))
    numeros[linha[0]] = listaInt


#printando lista
for chave in numeros.keys():
    print('%s-SP=%i-SI=%i-MA=%i'%(chave,somaPar(numeros[chave]),somaImpar(numeros[chave]),media(numeros[chave])))



