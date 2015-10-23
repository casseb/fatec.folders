#adquirindo conteudo do arquivo
entrada = open('entrada.in')
linhas = entrada.readlines()
entrada.close()

#criando e preenchendo dicionário numeros
numeros = {}
for linha in linhas:
    numeros[linha[0]] = linha[2:].rstrip().split(';')

#mexendo na bagaça
for chave in numeros.keys():
    resultado = chave
    somaPar = 0
    somaImpar = 0
    media = 0
    for numero in numeros[chave]:
        if(int(numero)%2==0):
            somaPar = somaPar+int(numero)
        else:
            somaImpar = somaImpar+int(numero)
        media = media+int(numero)
    print('%i-SOMAPAR=%i-SOMAIMPAR=%i-MEDIA=%i'%(int(chave),somaPar,somaImpar,media/len(numeros[chave])))



