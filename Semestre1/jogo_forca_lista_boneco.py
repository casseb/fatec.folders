palavra = input("Digite a palavra secreta:").lower().strip()
for x in range(100):
    print()
digitadas = []
acertos = []
erros = 0
while True:
    senha=""
    for letra in palavra:
        senha +=letra if letra in acertos else "."
    print(senha)
    if senha == palavra:
        print("Você acertou")
        break
    tentativa = input("\nDigite uma letra:").lower().strip()
    if tentativa in digitadas:
        print("Você já tentou esta letra!")
        continue
    else:
        digitadas += tentativa
        if tentativa in palavra:
            acertos += tentativa
        else:
            erros += 1
            print('Você errou!')

    linha1 = list("X===:==")
    linha2 = list("X---:--")
    linha3 = list("X------")
    linha4 = list("X------")
    linha5 = list("X------")
    linha6 = list("X------")
    linha7 = list("==========")

    forca = [linha1,linha2,linha3,linha4,linha5,linha6,linha7]

    if(erros >= 1):
        linha3[4]="0"
    if(erros >= 2):
        linha4[4]="|"
    if(erros >=3):
        linha4[3]="/"
    if(erros >=4):
        linha4[5]="\-"
    if(erros >=5):
        linha5[3]="/"
    if(erros >=6):
        linha5[5]="\-"


    for x in range(7):
        print("".join(forca[x]))

    if erros ==6:
        print("Enforcado!")
        print("A palavra correta era %s"%(palavra))
        break

