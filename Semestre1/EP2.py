
###################Regra de negócio########################

#Recebe letra, se a letra for do tipo FatecSJC retorna true, senão retorna False
def eFatecSJC(letra):
    if(letra == "f" or letra=="t" or letra == "s" or letra == "j" or letra =="c"):
        return True
    else:
        return False

#Recebe palavra, se a quantidade de letras for par, retorna True, senão retorna False
def ePar(palavra):
    if(len(palavra)%2==0):
        return True
    else:
        return False

#Recebe palavra e retorna a última letra
def letraUltima(palavra):
    return palavra[len(palavra)-1:]

#Recebe letra e palavra e retorna true se tem esta letra na palavra e false se não tem
def temLetraEmPalavra(palavra,letra):
    if(letra in palavra):
        return True
    else:
        return False

######################Preparando dados#####################

#Lendo arquivos listaA, txtA e txtB
arquivoListaA = open('listaA.txt',encoding="UTF-8")
arquivoTxtA = open('txtA.txt',encoding="UTF-8")
arquivoTxtB = open('txtB.txt',encoding="UTF-8")
stringListaA = arquivoListaA.read()
stringTxtA = arquivoTxtA.read()
stringTxtB = arquivoTxtB.read()
arquivoListaA.close()
arquivoTxtA.close()
arquivoTxtB.close()

#Criando listas com os conteudos

listaListaA = stringListaA.split(" ")
listaTxtA = stringTxtA.split(" ")
listaTxtB = stringTxtB.split(" ")

###################Somando o que foi localizado##############

#Somando Preposições
quantPreposicoesTxtA = 0
for palavra in listaTxtA:
    if(ePar(palavra) and not temLetraEmPalavra(palavra,"x") and not eFatecSJC(letraUltima(palavra))):
        quantPreposicoesTxtA = quantPreposicoesTxtA+1


########################Testando######################
print(quantPreposicoesTxtA)


