#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"

typedef struct no{
  int conteudo;
  struct no *prox;
}*LISTA;

LISTA lista = NULL;

void inserir(LISTA *lista,int conteudo){
  LISTA novo = (LISTA) malloc(sizeof(LISTA));
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

int main(){
  int conteudo,i;
  for(i=0;i<3;i++){
    scanf("%i",&conteudo);
    getchar();
    inserir(&lista,conteudo);
  }
  printf("\n");
  imprimir(lista);
  printf("\n");
  imprimir(lista);
  system("PAUSE");
	return 0;
}
