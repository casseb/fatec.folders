#########################Funções Genéricas#####################################

def stringArquivo(caminhoArquivo):
    arquivo = open(caminhoArquivo,encoding="UTF-8")
    stringArquivo = arquivo.read()
    arquivo.close()
    return stringArquivo

def ePar(palavra):
    return (len(palavra)%2 == 0)

def letraInicial(palavra):
    return (palavra[:1])

def letraFinal(palavra):
    return palavra[len(palavra)-1:]

def removeRepetidos(lista):
    for conteudo in lista:
        if(lista.count(conteudo) > 1):
            lista.remove(conteudo)

def listaCopia(lista):
    listaNova = []
    for conteudo in lista:
        listaNova.append(conteudo)
    return listaNova

def intPalavraMenor(palavra1,palavra2):
    if(len(palavra1)<=len(palavra2)):
        return len(palavra1)
    else:
        return len(palavra2)

def eOrdemCorreta(primeiraPalavra,segundaPalavra,regra):
    for posicao in range(0,intPalavraMenor(primeiraPalavra,segundaPalavra)):
        if(primeiraPalavra[posicao]!=segundaPalavra[posicao]):
            if(regra.index(primeiraPalavra[posicao])<=regra.index(segundaPalavra[posicao])):
                return True
            else:
                return False
    return (len(primeiraPalavra)<len(segundaPalavra))

def listaOrdenaLista(lista,regra):
    def privateOrdenaLista(lista,listaBase,regra):
        if(len(lista)==1):
            listaBase.append(lista[0])
            lista.remove(lista[0])
            return 0
        else:
            primeiroItem = letraFinal(regra)*999
            for conteudo in lista:
                if(eOrdemCorreta(conteudo,primeiroItem,regra)):
                    primeiroItem = conteudo
            listaBase.append(primeiroItem)
            lista.remove(primeiroItem)
            return privateOrdenaLista(lista,listaBase,regra)
    listaBase = listaCopia(lista)
    removeRepetidos(listaBase)
    lista = []
    privateOrdenaLista(listaBase,lista,regra)
    return lista

def stringPalavraParaBaseX(palavra,regra):
    numeroFinal = ""
    alfabeto = "ABCDEFGHIJLMNOPQRSTUVXZ"
    for letra in palavra:
        if(regra.index(letra)<10):
            numeroFinal = numeroFinal + "%i"%(regra.index(letra))
        else:
            numeroFinal = numeroFinal + "%s"%(alfabeto[regra.index(letra)-10])
    return numeroFinal

def stringInvertido(palavra):
    return palavra[::-1]

def intConverteBaseNPara10(numero, base):
    numero = stringInvertido(numero)
    numeroFinal = 0
    posicao = 0
    alfabeto = "ABCDEFGHIJLMNOPQRSTUVXZ"
    for algarismo in numero:
        algarismoCalculo = 0
        if(algarismo.isdigit()):
            algarismoCalculo = int(algarismo)
            numeroFinal = numeroFinal+(algarismoCalculo*(base**posicao))
        else:
            algarismoCalculo = alfabeto.index(algarismo)+10
            numeroFinal = numeroFinal+(algarismoCalculo*(base**posicao))
        posicao = posicao+1
    return numeroFinal

def eSomaPar(numero):
    soma = 0
    numeroStr = str(numero)
    for algarismo in numeroStr:
        soma = soma + int(algarismo)
    return (soma%2==0)

def eTemNumeroRepetido(numero):
    numeroStr = str(numero)
    for algarismo in numeroStr:
        if(numeroStr.count(algarismo)>1):
            return True
    return False

def escreveArquivo(texto,nomeArquivo):
    arquivo = open(nomeArquivo,'w')
    arquivo.write(texto)
    arquivo.close()


##########################Regras de Negócio###################################

def eFatecsjc(letra):
    return (letra in "ftsjc")

def ePreposicao(palavra):
    return (ePar(palavra) and not eFatecsjc(letraFinal(palavra)) and not "x" in palavra)

def eVerbo(palavra):
    return (len(palavra)==5 and not eFatecsjc(letraInicial(palavra)))

def eVerbo1Pessoa(palavra):
    return (eVerbo(palavra) and eFatecsjc(letraFinal(palavra)))

def eNumeroBonito(palavra):
    regra = "tshjmpnzwlrcbxkqvdgf"
    palavraInt = intConverteBaseNPara10(stringInvertido(stringPalavraParaBaseX(palavra,regra)),20)
    return (eSomaPar(palavraInt) and not eTemNumeroRepetido(palavraInt))

def intQuantPreposicoes(listaPalavra):
    count = 0
    for palavra in listaPalavra:
        if(ePreposicao(palavra)):
            count = count+1
    return count

def intQuantVerbos(listaPalavra):
    count = 0
    for palavra in listaPalavra:
        if(eVerbo(palavra)):
            count = count+1
    return count

def intQuantVerbos1Pessoa(listaPalavra):
    count = 0
    for palavra in listaPalavra:
        if(eVerbo1Pessoa(palavra)):
            count = count+1
    return count

def intQuantNumerosBonitos(listaPalavra):
    count = 0
    for palavra in listaPalavra:
        if(eNumeroBonito(palavra)):
            count = count+1
    return count


########################Lendo arquivos Texto##############################################

listaOriginal = stringArquivo("txtB.txt").split()

#######################Preparando dados para o arquivo###################################

textoFinal = ("A;%i\nB;%i\nC;%i\nD;%s\nE;%i")%(intQuantPreposicoes(listaOriginal),intQuantVerbos(listaOriginal),intQuantVerbos1Pessoa(listaOriginal)," ".join(listaOrdenaLista(listaOriginal,"tshjmpnzwlrcbxkqvdgf")),intQuantNumerosBonitos(listaOriginal))

#####################Gravando arquivo#######################################################

escreveArquivo(textoFinal,"resultado.txt")
