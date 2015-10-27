#Função que pega String e converte em um dicionario
def converteStringDicionario(string,separadorLinha,separadorIndice,separadorConteudo):
    resultado = {}
    linha = string.rstrip().split(separadorLinha)
    for conteudo in linha:
        conteudoVariavel = conteudo[conteudo.index(separadorIndice)+1:].split(separadorConteudo)
        if(len(conteudoVariavel)==1):
            resultado[conteudo[:conteudo.index(separadorIndice)]] = conteudoVariavel[0]
        else:
            conteudoTotal = []
            for conteudoTrabalhar in conteudoVariavel:
                conteudoTotal.append(conteudoTrabalhar)
            resultado[conteudo[:conteudo.index(separadorIndice)]] = conteudoTotal
    return resultado


#Adquirindo dados do arquivo
arquivo = open('dados.txt')
linhas = arquivo.read()
arquivo.close()

#Criando dicionário de dados
alunoString = linhas.rstrip().split("#")
print(converteStringDicionario(alunoString[0],"\n",":",","))




