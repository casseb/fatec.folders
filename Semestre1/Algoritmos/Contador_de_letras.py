print('Bem vindo ao "Contador de Letras"')

palavra = input('Digite a palavra:')
letrasApresentadas = ''

for x in palavra:
    if(x not in letrasApresentadas):
        print('%s: X%i'%(x,palavra.count(x)))
        letrasApresentadas = letrasApresentadas+x
