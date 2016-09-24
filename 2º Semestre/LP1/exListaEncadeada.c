#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int conteudo;
  struct no *prox;
}*LISTA;

LISTA lista = NULL;

void inserirItem(LISTA *lista, int conteudo){
  LISTA novo = (LISTA) malloc(sizeof(struct no));
  novo->conteudo = conteudo;
  novo->prox = *lista;
  *lista = novo;
}

void imprimeListaCompleta(LISTA listaTemp){
  while (listaTemp!=NULL) {
    printf("%i\n",listaTemp->conteudo);
    listaTemp = listaTemp->prox;
  }
}

void imprimeListaOrdemDigitacao(LISTA listaTemp){
  LISTA listaTempOrdem = NULL;
  while (listaTemp!=NULL){
    inserirItem(&listaTempOrdem,listaTemp->conteudo);
    listaTemp = listaTemp->prox;
  }
  imprimeListaCompleta(listaTempOrdem);
}

int main() {
  inserirItem(&lista,3);
  inserirItem(&lista,5);
  inserirItem(&lista,9);
  imprimeListaCompleta(lista);
  printf("\n\n");
  imprimeListaOrdemDigitacao(lista);
  system("PAUSE");
  return 0;
}
