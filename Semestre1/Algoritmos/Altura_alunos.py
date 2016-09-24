print('Digite as alturas e idades dos respectivos alunos e digite zero na altura para encerrar')

alturas = []
idades = []
quantidade = 0

while(True):
    altura = float(input('Digite a Altura: '))

    if(altura == 0 ):
        break
    alturas.append(altura)
    idades.append(float(input('Digite a idade: ')))

media = sum(alturas)/len(alturas)

for i in range(len(alturas)):
    if(idades[i]>13 and alturas[i]<=media):
        quantidade = quantidade+1

print('Quantidade %i'%(quantidade))

