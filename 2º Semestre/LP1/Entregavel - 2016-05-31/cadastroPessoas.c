#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"

typedef struct {
	char nome[100];
	int rg;
	int anoNascimento;
}PESSOA;

typedef struct NO {
	PESSOA info;
	struct NO *prox;
}*LISTA;

LISTA listal = NULL;

void inserirInicio (LISTA *lista, PESSOA pessoa){
	LISTA novo = (LISTA) malloc(sizeof(struct NO));
	novo->info = pessoa;
	novo->prox = *lista;
	*lista = novo;
}

void cadastroPessoa(){
	PESSOA pessoa;
	printf("Digite o nome da pessoa: ");
	fflush(stdin);
	gets(pessoa.nome);
	pessoa.rg = capturaInt("Digite o rg: ");
	pessoa.anoNascimento = capturaInt("Digite o ano de nascimento: ");
	inserirInicio(&listal,pessoa);
}

void cauculaIdade(){
	int busca,i = 0;
	busca = capturaInt("\nDigite a posição da pessoa que deseja calcular a idade: ");
	LISTA listaTemp = listal;
	while(listaTemp!=NULL){
		if (busca == i) {
				printf("A pessoa tem %i anos",2016-listaTemp->info.anoNascimento);
		}
		listaTemp = listaTemp->prox;
		i++;
	}

}

void anoMenor(){
	int anoBase;
	anoBase = capturaInt("Digite o ano que deseja pesquisar a partir: ");
	LISTA listaTemp = listal;
	while(listaTemp!=NULL){
		if (listaTemp->info.anoNascimento > anoBase) {
			printf("%s\n",listaTemp->info.nome);
		}
		listaTemp = listaTemp->prox;
	}
}

void anoMaior(){
	int anoBase;
	anoBase = capturaInt("Digite o ano que deseja pesquisar anterior: ");
	LISTA listaTemp = listal;
	while(listaTemp!=NULL){
		if (listaTemp->info.anoNascimento < anoBase) {
			printf("%s\n",listaTemp->info.nome);
		}
		listaTemp = listaTemp->prox;
	}
}

void pesquisarRG(){
	int busca;
	busca = capturaInt("Digite o numero de rg que deseja pesquisar: ");
	LISTA listaTemp = listal;
	while(listaTemp!=NULL){
		if (listaTemp->info.rg == busca) {
			printf("%s\n",listaTemp->info.nome);
		}
		listaTemp = listaTemp->prox;
	}
}

int main(){
	espMenu5Opcoes("Cadastrar uma pessoa",cadastroPessoa,"Calcular Idade",cauculaIdade,"Listar pessoa com nascimento a partir de",anoMaior,"Listar pessoas com nascimento menor que",anoMenor,"Busca por RG",pesquisarRG);
}
