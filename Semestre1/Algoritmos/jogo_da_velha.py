def preencher(linha,jogada,usarX):

    if(jogada==7 or jogada == 4 or jogada == 1):
        posicao = 1
    elif(jogada == 8 or jogada == 5 or jogada == 2):
        posicao = 5
    elif(jogada == 9 or jogada == 6 or jogada == 3):
        posicao = 9

    if(linha[posicao]==" "):
        if(usarX):
            linha[posicao] = 'X'
            return False
        else:
            linha[posicao] = '0'
            return True
    else:
        return usarX

def combinacoes(linha1,linha2,linha3):
    if(linha1.count('X')==3 or linha2.count('X') ==3 or linha3.count('X') ==3):
        return "X"
    elif(linha1.count('0')==3 or linha2.count('0') ==3 or linha3.count('0') ==3):
        return "0"
    elif((linha1[1] == 'X' and linha2[1] == 'X' and linha3[1]== 'X')or(linha1[5] == 'X' and linha2[5]== 'X' and linha3[5]== 'X')or(linha1[9] == 'X' and linha2[9]== 'X' and linha3[9]== 'X')):
        return "X"
    elif((linha1[1] == '0' and linha2[1] == '0'and linha3[1]== '0')or(linha1[5] == '0' and linha2[5]== '0' and linha3[5]== '0')or(linha1[9] == '0' and linha2[9] == '0'and linha3[9]== '0')):
        return "0"
    elif((linha1[1] == 'X'and linha2[5] == 'X'and linha3[9]== 'X')or(linha1[9]== 'X' and linha2[5]== 'X' and linha3[1]== 'X')):
        return "X"
    elif((linha1[1] == '0'and linha2[5] == '0'and linha3[9]== '0')or(linha1[9]== '0' and linha2[5]== '0' and linha3[1]== '0')):
        return "0"
    elif(linha1.count('X')+linha2.count('X')+linha3.count('X')==5):
        return "velha"

print('Bem vindo ao jogo da velha! ')
linha1 = list('   |   |   ')
linha2 = linha1.copy()
linha3 = linha1.copy()
separador = list('-----------')
layout = [linha1,separador,linha2,separador,linha3]
usarX = True


while(True):

    jogada = int(input("Digite sua jogada: "))

    if(jogada>=1 and jogada<=3):
        usarX = preencher(linha3,jogada,usarX)
    elif(jogada>=4 and jogada<=6):
        usarX = preencher(linha2,jogada,usarX)
    elif(jogada>=7 and jogada <=9):
        usarX = preencher(linha1,jogada,usarX)

    for x in range(5):
        print("".join(layout[x]))

    if(combinacoes(linha1,linha2,linha3)=='X'):
        print("Parabéns jogador X, você venceu!!")
        break
    elif(combinacoes(linha1,linha2,linha3)=='0'):
        print("Parabéns jogador 0, Você venceu!")
        break
    elif(combinacoes(linha1,linha2,linha3)=='velha'):
        print('Ixi, deu velha!!!')
        break