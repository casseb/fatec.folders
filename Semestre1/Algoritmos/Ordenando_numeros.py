numeros = []

n = int(input('Digite a opção desejada: 1-Ordem Crescente, 2-Ordem decrescente, 3-maior no meio: '))
numeros.append(int(input('Digite o primeiro número: ')))
numeros.append(int(input('Digite o segundo número: ')))
numeros.append(int(input('Digite o terceiro número: ')))

if(n==1):
 numeros.sort()
elif(n==2):
    numeros.sort()
    numeros.reverse()
elif(n==3):
    numeros.insert(1,numeros.pop(numeros.index(max(numeros))))

print(numeros)
