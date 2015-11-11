###########################Funções diversas########################

#Função que recebe uma string qualquer e retorna a propria string se for texto, int se for numeros e float se for numeros com ponto
def convertStringParaNumero(palavra):
    if(palavra.count('.')==1):
        parte1 = palavra[:palavra.find('.')]
        parte2 = palavra[palavra.find('.')+1:]
        if(parte1.isdigit() and parte2.isdigit()):
            return float(parte1+'.'+parte2)
        else:
            return palavra
    elif(palavra.count('.')==0):
        if(palavra.isdigit()):
            return int(palavra)
        else:
            return palavra
    else:
        return palavra

#Função que pega String e converte em um dicionario
def converteStringDicionario(string,separadorLinha,separadorIndice,separadorConteudo):
    resultado = {}
    linha = string.rstrip().split(separadorLinha)
    for conteudo in linha:
        conteudoVariavel = conteudo[conteudo.index(separadorIndice)+1:].split(separadorConteudo)
        if(len(conteudoVariavel)==1):
                resultado[conteudo[:conteudo.index(separadorIndice)]] = convertStringParaNumero(conteudoVariavel[0])
        else:
            conteudoTotal = []
            for conteudoTrabalhar in conteudoVariavel:
                    conteudoTotal.append(convertStringParaNumero(conteudoTrabalhar))
            resultado[conteudo[:conteudo.index(separadorIndice)]] = conteudoTotal
    return resultado

#Preenchendo Posições das coordenadas
def preenchendoPosicoes(coordenada,tamanho):
    letra = coordenada[:1]
    inicio = int(coordenada[1:])
    fim = int(inicio)+tamanho
    listaResultado = []
    for quadrado in range(inicio,fim):
        listaResultado.append(letra+str(quadrado))
    return listaResultado

#Converte uma matriz em uma lista
def convertMatrizEmLista(matriz):
    listaCompleta = []
    for lista in matriz:
        for itens in lista:
            listaCompleta.append(itens)
    return listaCompleta

##Validando Igualdades
def validandoQuantidade(lista,quantidade):
    if(len(lista)==quantidade):
        return True
    else:
        return False

##Retorna True se tem repetido e False se não tem
def listaTemRepetido(lista):
    for itens in lista:
        if(lista.count(itens)!=1):
            return True
    return False

#Converte o conteúdo de um dicionário em uma única lista
def converteConteudoDicEmLista(dic):
    lista = []
    for index in dic:
        for conteudo in dic[index]:
            lista.append(conteudo)
    return lista

#Procura se o item tem no dicionário, se tiver retorna True se não False
def temNaDic(dic,item):
    tem = False
    for index in dic.keys():
        for conteudo in dic[index]:
            if(conteudo==item):
                return True
    return tem


######################################Regra de negócio###########################


#Criando Dicionário Completo de Posições
def criaDicionarioCompletoPosicoes(dicPosicoes,separarPorLista):
    dicPosicoesCompleto = {}
    for index in dicPosicoes.keys():
        dicPosicoesCompleto[index] = []
        tempCoordenadas = []
        if(index=='1'):
            for coordenada in dicPosicoes[index]:
                tempCoordenadas.append(preenchendoPosicoes(coordenada,4))
            if(separarPorLista):
                dicPosicoesCompleto[index] = tempCoordenadas
            else:
                dicPosicoesCompleto[index] = convertMatrizEmLista(tempCoordenadas)
        if(index=='2'):
            for coordenada in dicPosicoes[index]:
                tempCoordenadas.append(preenchendoPosicoes(coordenada,5))
            if(separarPorLista):
                dicPosicoesCompleto[index] = tempCoordenadas
            else:
                dicPosicoesCompleto[index] = convertMatrizEmLista(tempCoordenadas)
        if(index=='3'):
            for coordenada in dicPosicoes[index]:
                tempCoordenadas.append(preenchendoPosicoes(coordenada,1))
            if(separarPorLista):
                dicPosicoesCompleto[index] = tempCoordenadas
            else:
                dicPosicoesCompleto[index] = convertMatrizEmLista(tempCoordenadas)
        if(index=='4'):
            for coordenada in dicPosicoes[index]:
                tempCoordenadas.append(preenchendoPosicoes(coordenada,2))
            if(separarPorLista):
                dicPosicoesCompleto[index] = tempCoordenadas
            else:
                dicPosicoesCompleto[index] = convertMatrizEmLista(tempCoordenadas)
    return dicPosicoesCompleto

#Validando quantidade de peças e torpedos

def regraValidandoQuantidade(dicPosicoesTotal):
    valido = True
    for pecas in dicPosicoesTotal.keys():
        if(pecas=='1' and not validandoQuantidade(dicPosicoesTotal[pecas],2)):
            valido=False
        elif(pecas=='2' and not validandoQuantidade(dicPosicoesTotal[pecas],2)):
            valido=False
        elif(pecas=='3' and not validandoQuantidade(dicPosicoesTotal[pecas],5)):
            valido=False
        elif(pecas=='4' and not validandoQuantidade(dicPosicoesTotal[pecas],4)):
            valido=False
        elif(pecas=='T' and not validandoQuantidade(dicPosicoesTotal[pecas],20)):
            valido=False
    return valido

##Retorna false se tem peça sobrepondo e true se esta ok
def regraValidandoSobreposicaoP(dicPosicoes):
    return not listaTemRepetido(converteConteudoDicEmLista(criaDicionarioCompletoPosicoes(dicPosicoes,False)))

def regraValidandoSobreposicaoT(dicJogadas):
    return not listaTemRepetido(converteConteudoDicEmLista(dicJogadas))

#Validando se as peças estão dentro do tabuleiro
def regraValidandoPosicoes(dicPosicoesTotal, dicTabuleiro):
    valido = True
    for index in dicPosicoesTotal.keys():
        for conteudo in dicPosicoesTotal[index]:
            if not(temNaDic(dicTabuleiro,conteudo)):
                return False
    return valido

#####################################Criando Dicionários#################################

#Montando Tabuleiro

##Criando string com coordenadas do tabuleiro
stringTabuleiro = ""
for i in "ABCDEFGHIJLMNOP":
    stringTabuleiro = stringTabuleiro+i+":"
    for j in range(1,16):
        if(j==15):
            stringTabuleiro = stringTabuleiro+i+str(j)+"#"
        else:
            stringTabuleiro = stringTabuleiro+i+str(j)+","

##Criando dicionario para tabuleiro
dicTabuleiro = converteStringDicionario(stringTabuleiro[:len(stringTabuleiro)-1],"#",":",",")

#Lendo arquivos jogador1 e jogador2
arquivoJogador1 = open('jogador1.txt',encoding="UTF-8")
arquivoJogador2 = open('jogador2.txt',encoding="UTF-8")
stringJogador1 = arquivoJogador1.read()
stringJogador2 = arquivoJogador2.read()
arquivoJogador1.close()
arquivoJogador2.close()

#Criando dicionario com as posições
stringPosicoes1 = stringJogador1[:stringJogador1.index("# Jogada")].rstrip()
dicPosicoes1 = converteStringDicionario(stringPosicoes1,"\n",";","|")
stringPosicoes2 = stringJogador2[:stringJogador2.index("# Jogada")].rstrip()
dicPosicoes2 = converteStringDicionario(stringPosicoes2,"\n",";","|")

#Criando dicionario com as jogadas
stringJogadas1 = stringJogador1[stringJogador1.index("T"):].rstrip()
dicJogadas1 = converteStringDicionario(stringJogadas1,"\n",";","|")
stringJogadas2 = stringJogador2[stringJogador2.index("T"):].rstrip()
dicJogadas2 = converteStringDicionario(stringJogadas2,"\n",";","|")

######################################Validando Arquivos#####################################

mensagensErro = []
if not(regraValidandoQuantidade(dicPosicoes1)):
    mensagensErro.append('Jogador 1 tem peças com quantidade incorreta')
if not(regraValidandoQuantidade(dicPosicoes2)):
    mensagensErro.append('Jogador 2 tem peças com quantidade incorreta')
if not(regraValidandoQuantidade(dicJogadas1)):
    mensagensErro.append('Jogador 1 tem jogadas com quantidade incorreta')
if not(regraValidandoQuantidade(dicJogadas2)):
    mensagensErro.append('Jogador 2 tem jogadas com quantidade incorreta')

if not (regraValidandoPosicoes(criaDicionarioCompletoPosicoes(dicPosicoes1,False),dicTabuleiro)):
    mensagensErro.append('Jogador 1 tem peças Fora do Tabuleiro ou inválidas')
if not (regraValidandoPosicoes(criaDicionarioCompletoPosicoes(dicPosicoes2,False),dicTabuleiro)):
    mensagensErro.append('Jogador 2 tem peças Fora do Tabuleiro ou inválidas')
if not (regraValidandoPosicoes(dicJogadas1,dicTabuleiro)):
    mensagensErro.append('Jogador 1 tem torpedos Fora do Tabuleiro ou inválidas')
if not (regraValidandoPosicoes(dicJogadas2,dicTabuleiro)):
    mensagensErro.append('Jogador 2 tem torpedos Fora do Tabuleiro ou inválidas')

if not(regraValidandoSobreposicaoP(dicPosicoes1)):
    mensagensErro.append('Jogador 1 tem peças sobrepostas')
if not(regraValidandoSobreposicaoP(dicPosicoes2)):
    mensagensErro.append('Jogador 2 tem peças sobrepostas')
if not(regraValidandoSobreposicaoT(dicJogadas1)):
    mensagensErro.append('Jogador 1 tem Torpedos Repetidos')
if not(regraValidandoSobreposicaoT(dicJogadas2)):
    mensagensErro.append('Jogador 2 tem Torpedos Repetidos')


for mensagem in mensagensErro:
    print(mensagem)

################################Jogadas##########################






