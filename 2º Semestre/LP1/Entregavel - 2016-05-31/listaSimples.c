#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"

typedef struct no{
  int conteudo;
  struct no *prox;
}*LISTA;

LISTA lista = NULL;

void inserir(LISTA *lista,int conteudo) {
  LISTA novo = (LISTA) malloc(sizeof(struct no));
  novo->conteudo = conteudo;
  novo->prox = *lista;
  *lista = novo;
}

void imprimir(LISTA listaTemp){
  while(listaTemp!=NULL){
    printf("%i\n",listaTemp->conteudo);
    listaTemp = listaTemp->prox;
  }
}

void imprimirOrdemDigitacao(LISTA listaTemp){
  LISTA listaOrdenada = NULL;
  while(listaTemp!=NULL){
    inserir(&listaOrdenada,listaTemp->conteudo);
    listaTemp = listaTemp->prox;
  }
  imprimir(listaOrdenada);
}

int main(){
  inserir(&lista,3);
  inserir(&lista,4);
  inserir(&lista,5);
  imprimir(lista);
  system("PAUSE");
  imprimirOrdemDigitacao(lista);
  system("PAUSE");
	return 0;
}
