tipo = input('Digite G para gasolina e A para álcool')
if(tipo!='G' and tipo!='A'):
    print('Comando Inválido')
else:
    pGasolina = 3.3
    pAlcool = 2.9
    litros = float(input('Digite a quantidade de litros'))

    if(litros<=20):
        pGasolina = pGasolina-pGasolina*0.03
        pAlcool = pAlcool-pAlcool*0.04
    else:
        pGasolina = pGasolina-pGasolina*0.04
        pAlcool = pAlcool-pAlcool*0.06

    preco = 0
    if(tipo=='A'):
        preco = pGasolina*litros
    else:
        preco = pAlcool*litros

    print('Valor Total: R$%.2f'%(pGasolina))