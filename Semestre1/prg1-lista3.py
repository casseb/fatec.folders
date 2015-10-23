#!/bin/env python3
# coding: utf-8
# Lucas G. Nadalete <lucas.nadalete@fatec.sp.gov.br>
# Lista de exercícios 3

def crescimento_populacional(populacao1,populacao2,crescimento1,
crescimento2):
    ''' Calcule quantos anos levará para a 'população1' ultrapassar a 
    'população2', baseado em suas porcentagens de crescimento.'''
#    return anos


def quantidade_de_impares(valor_inicial,valor_final):
    ''' Determine a quantidade de números ímpares num intervalo'''
#    return impares

def soma_dos_inteiros(valor1,valor2):
    ''' Calcule a soma dos números inteiros no intervalo entre 'valor1'
    e o 'valor2' ou vice-versa, considerando que podem ser informado
    números negativos ou fora de ordem. 
    Ex: 1 e 5 ou 5 e 1, retorna 9'''
#    return soma

def potencia(base,expoente):
    ''' Calcule a 'base' elevada ao 'expoente' manualmente sem usar 
    'base**expoente'. Considere base e expoente como inteiros positivos.''' 
#    return pot

def Fibonacci(n):
    ''' Retorne o n-ésimo valor da série de Fibonacci
    Fibonacci = 1,1,2,3,5,8,13,...'''
#    return final_Fibonacci

def fatorial(numero):
    ''' Calcule e retorne o fatorial do 'numero' informado,
    O fatorial é o valor produtório dos valores menores ou iguais ao número
    ex: fatorial de 4 é 4*3*2*1 e retorna 24'''
#    return valor_fatorial

def primo(valor):
    ''' Verifique se o 'valor' informado é primo.
    Um número primo é aquele que é divisível apenas por ele mesmo e por 1
    1 não é primo.'''
 #       return True

def quantidade_de_primos(comeco,final):
    ''' Retorne a quantidade de primos entre os valores informados.
    Dica: use a função primo() recém desenvolvida para fazer a verificação.'''
#    return qt_primos

def media_saltos(salto1,salto2,salto3,salto4,salto5):
    ''' Calcule a media dos saltos de um atleta, sabendo que o melhor
    e o pior saltos são desconsiderados. '''
 #   return media

def serie1(fim):
    '''Dado n, calcule o valor de
    s = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n '''
#    return round(s,2)
    
def serie2(fim):
    '''Dado n, calcule o valor de
    s = 1/1 + 2/3 + 3/5 + 4/7 + 5/9 + ... + n/m'''
 #   return round(s,2)

def serie_pi(numero_vezes):
    ''' Calcule o valor de pi através da série
    4/1 - 4/3 + 4/5 - 4/7 + ... - 4/n, sendo n informado '''
#    return round(pia,6)

# Área de testes: só mexa aqui se souber o que está fazendo!
acertos = 0
total = 0 

def test(obtido, esperado):
    global acertos, total
    total += 1
    if obtido != esperado:
        prefixo = ' Falhou.'
    else:
        prefixo = ' Passou.'
        acertos += 1
    print ('%s Esperado: %s \tObtido: %s' % (prefixo,repr(esperado), 
        repr(obtido)))

def main():
    print('Aumento da população:')
    test(crescimento_populacional(80000,200000,3,1.5), 63)
    test(crescimento_populacional(1000,2000,1,1.1), 0)
    test(crescimento_populacional(2000,1000,1.1,1), 0)
    test(crescimento_populacional(2000,2020,1.1,1), 11)

    print('Quantidade de ímpares:')
    test(quantidade_de_impares(1,50), 24)
    test(quantidade_de_impares(1,10), 4)
    test(quantidade_de_impares(1,60), 29)
    test(quantidade_de_impares(40,80), 20)

    print('Soma de números inteiros:')
    test(soma_dos_inteiros(1,5), 9)
    test(soma_dos_inteiros(1,50), 1224)
    test(soma_dos_inteiros(50,1), 1224)
    test(soma_dos_inteiros(10,1), 44)
    test(soma_dos_inteiros(-10,1), -45)
    test(soma_dos_inteiros(10,-10), 0)

    print('Potência:')
    test(potencia(1,20000), 1)
    test(potencia(2,4), 16)
    test(potencia(10000,1), 10000)
    test(potencia(2,10), 1024)

    print('Fibonnaci:')
    test(Fibonacci(1), 1)
    test(Fibonacci(2), 1)
    test(Fibonacci(3), 2)
    test(Fibonacci(4), 3)
    test(Fibonacci(5), 5)

    print('Fatorial:')
    test(fatorial(0), 0)
    test(fatorial(1), 1)    
    test(fatorial(5), 120)
    test(fatorial(10), 3628800)

    print('Primo:')
    test(primo(0), False)
    test(primo(1), False)
    test(primo(2), True)
    test(primo(3), True)
    test(primo(4), False)
    test(primo(5), True)
    test(primo(7), True)
    test(primo(11), True)
    
    print('Quantidade de primos no intervalo:')
    test(quantidade_de_primos(5,10), 1)
    test(quantidade_de_primos(10,20), 4)
    test(quantidade_de_primos(0,21), 8)
    test(quantidade_de_primos(43,102), 12)

    print('Média dos saltos:')
    test(media_saltos(10,10,10,10,10), 10)
    test(media_saltos(9,9.1,8,7,6.9), 8)
    test(media_saltos(1,1,3,5,5), 3)
    test(media_saltos(10,10,9.9,10,10), 10)

    print('Série 1:')
    test(serie1(1), 1.00)
    test(serie1(15), 3.32)
    test(serie1(10), 2.93)
    test(serie1(5), 2.28)

    print('Série 2:')
    test(serie2(1), 1.00)
    test(serie2(2), 1.67)
    test(serie2(3), 2.27)
    test(serie2(4), 2.84)

    print('Série pi:')
    test(serie_pi(1), 4.000000)
    test(serie_pi(2), 2.666667)
    test(serie_pi(3), 3.466667)
    test(serie_pi(4), 2.895238)
    test(serie_pi(5), 3.339683)
    test(serie_pi(6), 2.976046)
    test(serie_pi(7), 3.283738)
    test(serie_pi(8), 3.017072)
    test(serie_pi(9), 3.252366)
    test(serie_pi(10), 3.041840)
    test(serie_pi(100), 3.131593)
    test(serie_pi(150), 3.134926)
    test(serie_pi(1000), 3.140593)
    test(serie_pi(5000), 3.141393)
    test(serie_pi(9000), 3.141482)

if __name__ == '__main__':
    main()
    print("\n%d Testes, %d Ok, %d Falhas: Nota %.1f" %(total, acertos,
     total-acertos, float(acertos*10)/total))
    if total == acertos:
        print("Parabéns, seu programa rodou sem falhas!")
