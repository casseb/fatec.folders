#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"

char tipoCombustivel = 'g';
float valorLitro = 10;
float quantidadeCombustivel = 10;


abastecerPorValor(float valor){
    float litros;
    litros = valor/valorLitro;
    quantidadeCombustivel = quantidadeCombustivel-litros;
    printf("Foram abastecidos %.2f litros com R$%.2f \n",litros,valor);
    system("pause");
}

abastecerPorLitro(float litros){
    float valor;
    valor = litros*valorLitro;
    quantidadeCombustivel = quantidadeCombustivel-litros;
    printf("Foram abastecidos %.2f litros com R$%.2f \n",litros,valor);
    system("pause");
}

alterarValor(float valor){
    printf("Foi alterado o valor de R$%.2f para R$%.2f \n",valorLitro,valor);
    valorLitro = valor;
    system("pause");
}

alterarCombustivel(char c){
    printf("Foi alterado o tipo do combustivel de %c para %c \n",tipoCombustivel,c);
    tipoCombustivel = c;
    system("pause");
}

alterarQuantidadeCombustivel(float litros){
    printf("Foi alterado a quantidade de combustivel de %.2f para %.2f \n",quantidadeCombustivel,litros);
    quantidadeCombustivel = litros;
    system("pause");
}

info(){
    printf("Tipo Combustível: %c \nValor do litro: R$%.2f \nQuantidade de Combustível: %.2f \n",tipoCombustivel,valorLitro,quantidadeCombustivel);
    system("pause");
}

opcaoA(){
    char opcao;
    float litros,valor;
    printf("Deseja abastecer por (v)valor ou (l)litro? (c) para cancelar\n");
    scanf("%c",&opcao);
    getchar();
        switch(opcao){
            case('v'):
                printf("Digite quanto deseja abastecer: R$ ");
                scanf("%f",&valor);
                getchar();
                abastecerPorValor(valor);
                break;
            case('l'):
                printf("Digite quantos litros deseja abastecer: ");
                scanf("%f",&litros);
                getchar();
                abastecerPorLitro(litros);
                break;
        }
    info();
}

opcaoB(){
    float valor;
    printf("Digite o novo valor R$ ");
    scanf("%f",&valor);
    getchar();
    alterarValor(valor);
    info();
}

opcaoC(){
    char tipoCombustivel;
    printf("Digite o novo tipo: ");
    scanf("%c",&tipoCombustivel);
    getchar();
    alterarCombustivel(tipoCombustivel);
    info();
}

opcaoD(){
    float litros;
    printf("Digite a nova quantidade: ");
    scanf("%f",&litros);
    getchar();
    alterarQuantidadeCombustivel(litros);
    info();
}


main()
{
    espMenu4Opcoes("Abastecer",opcaoA,"Alterar Valor",opcaoB,"Alterar Combustível",opcaoC,"Alterar quantidade do conbustível",opcaoD);
}
