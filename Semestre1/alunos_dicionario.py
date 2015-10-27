#Adquirindo dados do arquivo
arquivo = open('dados.txt')
linhas = arquivo.read()
arquivo.close()

print(linhas)

