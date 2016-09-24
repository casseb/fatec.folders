#Função que recebe uma string qualquer e retorna a propria string se for texto, int se for numeros e float se for numeros com ponto
def convertStringDecimal(palavra):
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
                resultado[conteudo[:conteudo.index(separadorIndice)]] = convertStringDecimal(conteudoVariavel[0])
        else:
            conteudoTotal = []
            for conteudoTrabalhar in conteudoVariavel:
                    conteudoTotal.append(convertStringDecimal(conteudoTrabalhar))
            resultado[conteudo[:conteudo.index(separadorIndice)]] = conteudoTotal
    return resultado


#Adquirindo dados do arquivo
arquivo = open('dados.txt',encoding="UTF-8")
linhas = arquivo.read()
arquivo.close()

#Criando dicionário de dados
alunoString = linhas.rstrip().split("#")

print(converteStringDicionario(alunoString[0],"\n",":",","))




