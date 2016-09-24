#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "bycasseb.h"

char** nomes;



void buscaNome(){
    int indice;
    indice = capturaInt("Digite a posição que quer pesquisar: ");
    printf("Nome: ");
    puts(nomes[indice]);
    system("pause");
}

void opcaoA(){
    ordemAlfabetica(nomes,5);
    impListaPalavras(nomes,5);
}

void opcaoB(){
    char **nomesMaiusculo = (char **)malloc(5 * sizeof(char));
    int i;
    for (i=0;i<5;i++ ){
        *(nomesMaiusculo + i) = (char*)malloc(30*sizeof(char));
    }
    nomesMaiusculo = maiuscula(nomes,5);
    impListaPalavras(nomesMaiusculo,5);
}

void opcaoC(){
    buscaNome();
}

void main()
{
    char opcao;
    nomes = capturaVetorPalavras("Digite o nome ",5);
    espMenu3Opcoes("Imprimir em ordem alfabética",opcaoA,"Maiusculas",opcaoB,"Pesquisar",opcaoC);
}
