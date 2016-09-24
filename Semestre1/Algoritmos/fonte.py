while (True):
    print('Deu certo')


# Variável Python
## Nome da Variável

variavel = 0
_variavel = 0
#12variavel = 0
#@variavel = 0

## Tipo Int

variavelInt1 = 1
variavelInt2 = 4
variavelInt3 = 13

## Tipo Float

variavelFloat1 = 1.0
variavelFloat2 = 3.5
variavelFloat3 = 12.994

## Tipo String

variavelString1 = "variavel"
variavelString2 = "1"
variavelString3 = 'By Casseb'

## Tipo Boolean

variavelBoolean1 = True
variavelBoolean2 = False

## Conversão

variavelIntConvert = int(variavelFloat1)
variavelFloatConvert = float(variavelInt2)
variavelStringConvert = str(variavelInt3)

# Operadores

## Aritméticos

soma = 3+4
subtracao = 2-1
multiplicacao = 3*2
divisao = 10/3
exponenciacao = 2**4
restoDivisao = 10%3
divisaoParteInteira = 10//3

print('Soma: '+str(soma))
print('Subtracao: '+str(subtracao))
print('Multiplicacão: '+str(multiplicacao))
print('Divisão: '+str(divisao))
print('Exponenciação: '+str(exponenciacao))
print('Resto da Divisão: '+str(restoDivisao))
print('Divisão com Parte Inteira: '+str(divisaoParteInteira))

## Atribuição

variavel = 5

## Relacionais

igual = 5==5
diferente = 5!=9
maior = 5>1
maiorIgual = 5>=5
menor = 1<5
menorIgual = 5<=5
negacao = not igual
e = 5>1 and 1<5
ou = 5==5 or 5>10

# Decisão

if(True): #Primeira condição
    print('Estrutura se verdadeiro')
elif(True):#Condição caso a primeira seja falsa
    print('Estrutura de falso')
else: #Caso ambos sejam falso
    print('Estrutura de Falso')


# Repetição

cont = 0 #iniciando contador
while (cont<=5): # Iniciando while para que ele repita a instrução
                # abaixo até que cont seja maior que 5
    print(str(cont)) # imprindo o cont
    cont = cont+1 # acrescentando mais 1 no contador para que o valor
              # some até chegar a maior ou igual a 5

#Listas

## Iniciando Variável

lista1 = []
lista2 = [1,54,'texto']

## Manipulando seus valores

lista2 = [1,54,'texto']
primeiroRegistro = lista1[0]
segundoRegistro = lista1[1]
terceiroRegistro = lista1[2]

lista1[1] = 30

