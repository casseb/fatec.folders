#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"

typedef struct no{
  int conteudo;
  struct no *proximo;
  struct no *anterior;
}*LISTA;

LISTA lista = NULL;

void inserir(LISTA *lista,int conteudo){
  LISTA novo = (LISTA) malloc(sizeof(struct no));
  novo->conteudo = conteudo;
  novo->proximo = *lista;
  if(novo->proximo != NULL){
    novo->proximo->anterior = novo;
  }
  *lista = novo;
}

void imprimir(LISTA listaTemp){
  while(listaTemp->proximo!=NULL){
    printf("%i\n",listaTemp->conteudo);
    if(listaTemp->proximo!=NULL){
      listaTemp = listaTemp->proximo;
    }
  }
  printf("\n");
  while(listaTemp!=NULL){
    printf("%i\n",listaTemp->conteudo);
    listaTemp = listaTemp->anterior;
  }
}

int main(){
  inserir(&lista,3);
  inserir(&lista,4);
  inserir(&lista,5);
  imprimir(lista);
  system("PAUSE");
	return 0;
}
