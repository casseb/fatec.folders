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


#Montando Tabuleiro

##Criando string com coordenadas do tabuleiro
stringTabuleiro = ""
for i in "ABCDEFGHIJLMNOP":
    stringTabuleiro = stringTabuleiro+i+":"
    for j in range(1,16):
        if(j==15):
            stringTabuleiro = stringTabuleiro+str(j)+"#"
        else:
            stringTabuleiro = stringTabuleiro+str(j)+","

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

#Funções de Validação

##Validando Quantidade de peças e de jogadas
def validandoPecas(listaPecas,quantidade):
    if(len(listaPecas)==quantidade):
        return True
    else:
        return False

def regraValidandoPecas(dicPosicoes):
    valido = True
    for pecas in dicPosicoes.keys():
        if(pecas=='1' and not validandoPecas(dicPosicoes[pecas],2)):
            valido=False
        elif(pecas=='2' and not validandoPecas(dicPosicoes[pecas],2)):
            valido=False
        elif(pecas=='3' and not validandoPecas(dicPosicoes[pecas],5)):
            valido=False
        elif(pecas=='4' and not validandoPecas(dicPosicoes[pecas],4)):
            valido=False
        elif(pecas=='T' and not validandoPecas(dicPosicoes[pecas],20)):
            valido=False
    return valido

##Validando sobreposição de pecas
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

##Retorna True se tem repetido e False se não tem
def listaTemRepetido(listaCompleta):
    for itens in listaCompleta:
        if(listaCompleta.count(itens)!=1):
            return True
    return False

##Retorna false se tem peça sobrepondo e true se esta ok
def regraValidandoSobreposicao(dicPosicoes):
    return not listaTemRepetido(listaPosicoes(dicPosicoes))

def adicionaTamanhoCoordenadas(dicPosicoes):
    for index in dicPosicoes.keys():
        if(index=='1'):
            for coordenada in dicPosicoes[index]:
                listaPosicoes.append(preenchendoPosicoes(coordenada,4))
        if(index=='2'):
            for coordenada in dicPosicoes[index]:
                listaPosicoes.append(preenchendoPosicoes(coordenada,5))
        if(index=='3'):
            for coordenada in dicPosicoes[index]:
                listaPosicoes.append(preenchendoPosicoes(coordenada,1))
        if(index=='4'):
            for coordenada in dicPosicoes[index]:
                listaPosicoes.append(preenchendoPosicoes(coordenada,2))

def listaPosicoes(dicPosicoes):
    listaPosicoes = []
    for index in dicPosicoes.keys():
        if(index=='1'):
            for coordenada in dicPosicoes[index]:
                listaPosicoes.append(preenchendoPosicoes(coordenada,4))
        if(index=='2'):
            for coordenada in dicPosicoes[index]:
                listaPosicoes.append(preenchendoPosicoes(coordenada,5))
        if(index=='3'):
            for coordenada in dicPosicoes[index]:
                listaPosicoes.append(preenchendoPosicoes(coordenada,1))
        if(index=='4'):
            for coordenada in dicPosicoes[index]:
                listaPosicoes.append(preenchendoPosicoes(coordenada,2))
    return (convertMatrizEmLista(listaPosicoes))

#Validando arquivos

mensagensErro = []
if not(regraValidandoPecas(dicPosicoes1)):
    mensagensErro.append('Jogador 1 tem peças inválidas')
if not(regraValidandoPecas(dicPosicoes2)):
    mensagensErro.append('Jogador 2 tem peças inválidas')
if not(regraValidandoPecas(dicJogadas1)):
    mensagensErro.append('Jogador 1 tem jogadas inválidas')
if not(regraValidandoPecas(dicJogadas2)):
    mensagensErro.append('Jogador 2 tem jogadas inválidas')
if not(regraValidandoSobreposicao(dicPosicoes1)):
    mensagensErro.append('Jogador 1 tem peças sobrepostas')
if not(regraValidandoSobreposicao(dicPosicoes2)):
    mensagensErro.append('Jogador 2 tem peças sobrepostas')

for mensagem in mensagensErro:
    print(mensagem)


#Inicio do processamento das jogadas
if(len(mensagensErro)==0):
    pontos = 0
    #função que recebe um dicionario e retorna com as coordenadas completas












