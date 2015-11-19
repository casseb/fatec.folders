################Funções Genéricas#########################

#função que copia uma lista
def listaCopia(lista):
    listaFinal = []
    for conteudo in lista:
        listaFinal.append(conteudo)
    return listaFinal

#Função que adiciona um conteúdo no final da lista
def ordenaFinalLista(lista,alvo):
    lista.remove(alvo)
    lista.append(alvo)

#Função que retorna a posição do próximo alvo da lista
def indexProximoAlvo(lista,alvo):
    primeiro = lista.index(alvo)
    segundo = lista[primeiro+1:].index(alvo)
    return segundo

#Função que adiciona um conteúdo no final da lista
def ordenaInicioLista(lista,alvo):
    if(lista.count(alvo)>1):
         print(indexProximoAlvo(lista,alvo))
    else:
        lista.remove(alvo)
        lista.insert(0,alvo)

#função que retorna o tamanho da menor palavra entre duas
def tamanhoPalavraMenor(palavra1,palavra2):
    if(len(palavra1)<=len(palavra2)):
        return len(palavra1)
    else:
        return len(palavra2)

#função que compara duas palavras e retorna true se a primeira vem primeiro e false se for a segunda
def ePrimeiraPalavra(palavra1,palavra2,regra):
    tamanhoMenor = tamanhoPalavraMenor(palavra1,palavra2)
    for posicao in range(0,tamanhoMenor):
        if(palavra1[posicao]!=palavra2[posicao]):
            if(regra.find(palavra1[posicao])<regra.find(palavra2[posicao])):
                return True
                break
            else:
                return False
            break
    if(len(palavra1)<len(palavra2)):
        return True
    else:
        return False

#Função recursiva que ordena lista de strings
def ordenaListaString(listaOriginal,listaBase,regra):
    palavraFinal = regra[0]
    if(len(listaBase)==0):
        return None
    else:
        for palavra in listaBase:
            if (ePrimeiraPalavra(palavraFinal,palavra,regra)):
                palavraFinal = palavra
        ordenaInicioLista(listaOriginal,palavraFinal)
        listaBase.remove(palavraFinal)
        return ordenaListaString(listaOriginal,listaBase,regra)

################Testando#################################

lista = ["aaaa","aaaa","aaaa","aaab","abb"]
listaBase = listaCopia(lista)
ordenaListaString(lista,listaBase,"abcdefghijlmnopqrstuvxz")
print(lista.index("aaaa"))


