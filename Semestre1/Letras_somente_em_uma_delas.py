print('Bem vindo ao "Letras somente em uma das palavras')

palavraA = input('Primeira Palavra: ')
palavraB = input('Segunda Palavra: ')
resultado = ''
x = 0

for x in palavraA:
    if(x not in palavraB):
        resultado = resultado+x

for x in palavraB:
    if(x not in palavraA):
        resultado = resultado+x

print(str(resultado))
