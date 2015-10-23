palavra = input("Digite a palavra: ")
procura = input("Digite os caracteres que deseja substituir: ")
substituto = input("Digite os caracteres que deseja que fiquem no lugar de %s (obs. deve ter o mesmo tamanho do informado anterior: "%(procura))

if(len(procura)==len(substituto)):
    for x in palavra:
        if(x in procura):
            palavra = palavra.replace(x,substituto[procura.index(x)])
    print(palavra)
else:
    print("A palavra que é localizada devem ter o mesmuo tamanho da palavra que será substit")
