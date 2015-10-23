print('Bem vindo ao "Subtraindo letras"')

palavra = input('Digite a palavra: ')
subtracao = input('Digite as letras que deseja subtrair: ')
resultado = ''

for x in palavra:
    if(x not in subtracao):
        resultado = resultado+x

print(str(resultado))

