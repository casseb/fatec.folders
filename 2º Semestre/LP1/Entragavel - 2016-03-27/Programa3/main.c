#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"

typedef struct p{
    char nome[30];
    int rg;
    int anoNascimento;
} PESSOA;

PESSOA pessoa[10];
int genPessoa = 0;

void cadastrarPessoa(){
    printf("Digite o nome da Pessoa: ");
    fflush(stdin);
    gets(pessoa[genPessoa].nome);
    pessoa[genPessoa].rg = capturaInt("Digite o rg: ");
    pessoa[genPessoa].anoNascimento = capturaInt("Digite o ano de nascimento: ");
    genPessoa++;
}

void calcularData(){
    char escolhido[30];
    printf("Qual o nome da pessoa que deseja calcular idade?: ");
    fflush(stdin);
    gets(escolhido);
    int i;
    system("pause");
    for(i=0;i<genPessoa;i++){
        if(strcmp (pessoa[i].nome,escolhido) == 0){
            printf("Encontrado pessoa %s \n Sua idade e de %i\n",pessoa[i].nome,(2016-pessoa[i].anoNascimento));
            system("pause");
        }
    }
}

void listaNascimentoDepois(){
    int anoEscolhido;
    anoEscolhido = capturaInt("Digite o ano de referência: ");
    int i;
    for(i=0;i<genPessoa;i++){
        if(pessoa[i].anoNascimento>=anoEscolhido){
            printf("%s\n",pessoa[i].nome);
            system("pause");
        }
    }
}

void listaNascimentoAntes(){
    int anoEscolhido;
    anoEscolhido = capturaInt("Digite o ano de referência: ");
    int i;
    for(i=0;i<genPessoa;i++){
        if(pessoa[i].anoNascimento<anoEscolhido){
            printf("%s\n",pessoa[i].nome);
            system("pause");
        }
    }
}

void pesquisaPorRG(){
    int escolhido;
    escolhido = capturaInt("Digite o rg: ");
    int i;
    for(i=0;i<genPessoa;i++){
        if(pessoa[i].rg==escolhido){
            printf("%s\n",pessoa[i].nome);
            system("pause");
        }
    }
}

void main()
{
    espMenu5Opcoes("Cadastrar Pessoa",cadastrarPessoa,"Calcular Idade",calcularData,"Listar nascimentos depois de: ",listaNascimentoDepois,"Listar nascimento antes de: ",listaNascimentoAntes,"Pesquisar por RG",pesquisaPorRG);
}
