#########Funções Genéricas##########################

#Função que recebe uma string qualquer e retorna a propria string se for texto, int se for numeros e float se for numeros com ponto
def convertStringParaNumero(palavra):
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

#Converte string em lista
def listaIntDeString(texto):
    listaFinal = []
    for letra in texto:
        listaFinal.append(convertStringParaNumero(letra))
    return listaFinal
#Recebe a soma das multiplicações e retorna o digito
def calculaResto(numero):
    resto = numero%11
    if(resto == 10):
        return 0
    else:
        return resto

#Função que recebe lista de inteiros e retorna uma string
def converteListaIntparaString(lista):
    listaFinal = []
    for item in lista:
        listaFinal.append(str(item))
    return "".join(listaFinal)

#########Regras de negócio##############################################

#Função que recebe uma string com cpf e retorna o cpf completo e a soma
def calculaDigFaltantes(stringCPF):
    lista = listaIntDeString(stringCPF)
    listaParcial = []
    listaFinal = []
    base = 1
    for numero in lista:
        listaParcial.append(numero*base)
        base = base+1
    soma1digito = sum(listaParcial)
    lista.append(calculaResto(soma1digito))
    base = 0
    for numero in lista:
        listaFinal.append(numero*base)
        base = base+1
    soma2digito = sum(listaFinal)
    lista.append(calculaResto(soma2digito))
    return converteListaIntparaString(lista),soma1digito,soma2digito

#Recebe uma string de cpf e retorna true se é valido e false senão
def cpfValido(cpf):
    cpfCompleto,soma1,soma2 = calculaDigFaltantes(cpf[:9])
    if(cpf == cpfCompleto):
        return True
    else:
        return False

#########Captura dos dados e entrega####################################
separador = "-----------------------------"
print("Bem vindo ao validados de CPF!")
print("Digite 1 para Calcular os dígitos de controle do CPF")
print("Digite 2 para Verificar a validade de um CPF")
print("Digite qualquer outra coisa para sair")
print(separador)
escolha = input("Digite o que deseja: ")

if(escolha=="1"):
    cpf = input("Digite os nove números que deseja calcular: ")
    cpfCompleto,soma1digito,soma2digito = calculaDigFaltantes(cpf)
    print(separador)
    print("Você digitou %s números sendo necessário completar com %s"
          " dígitos"%(cpf,cpfCompleto[9:]))
elif(escolha=="2"):
    cpf = input("Digite o CPF que deseja validar: ")
    cpfCompleto,soma1digito,soma2digito = calculaDigFaltantes(cpf)
    eValido = cpfValido(cpf)
    print(separador)
    if(eValido):
        print("CPF Válido")
    else:
        print("CPF Inválido")
if(escolha == "1" or escolha == "2"):
    print(separador)
    print("Soma para 1º digito: %i"%(soma1digito))
    print("Soma para 2º digito: %i"%(soma2digito))
else:
    print(separador)
    print("Programa finalizado")
