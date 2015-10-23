print('Bem vindo ao "Letras em Comum"')
palavraA = input('Digite a primeira palavra: ')
palavraB = input('Digite a segunda palavra: ')
resultado = ''

i = 0
while(i<len(palavraA)):
    if(palavraA[i] in palavraB):
        resultado = resultado+palavraA[i]
    i = i+1

print(str(resultado))
