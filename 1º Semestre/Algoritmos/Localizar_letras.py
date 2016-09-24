print('Bem vindo ao Localizar posição das letras')

original = input('Digite a palavra que deseja usar como alvo da busca: ')
pesquisa = input('Digite o que deseja buscas na palavra: ')

posicao = original.find(pesquisa)

if(posicao >=0):
    print('%s encontrado na posição %i de %s'%(pesquisa,posicao,original))
else:
    print('%s não localizado'%(pesquisa))
