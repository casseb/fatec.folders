import random
erros = 0
acertos = 0
while(acertos<3 or erros<3):
    n=random.randint(1,10)
    x=int(input("Escolha um númeo entre 1 e 10: "))
    if(x==n):
        print("Você acertou!")
        acertos = acertos+1
    else:
        print("Você errou.")
        erros = erros+1
