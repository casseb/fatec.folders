#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"

typedef struct {
  int numeroVoo;
  char ciaAerea [20];
  char modeloAeronave [20];
  char origem [20];
  char destino [20];
  int qtdeTotalAssentos;
  int qtdeAssentosOcupados;
}VOO;

typedef struct NO {
	VOO info;
	struct NO *prox;
}*LISTA;

LISTA listal = NULL;

void inserirInicio (LISTA * lista, VOO VOO){
	LISTA novo = (LISTA) malloc(sizeof(struct NO));
	novo->info = VOO;
	novo->prox = *lista;
	*lista = novo;
}

void incluirVoo(){
  VOO voo;
  voo.numeroVoo = capturaInt("Digite o número do Voo: ");
  fflush(stdin);
  printf("Digite a cia Aerea: ");
  gets(voo.ciaAerea);
  fflush(stdin);
  printf("Digite o modelo da aeronave: ");
  gets(voo.modeloAeronave);
  fflush(stdin);
  printf("Digite a origem: ");
  gets(voo.origem);
  fflush(stdin);
  printf("Digite o destino: ");
  gets(voo.destino);
  voo.qtdeTotalAssentos = capturaInt("Digite a quantidade total de acentos: ");
  voo.qtdeAssentosOcupados = capturaInt("Digite a quantidade acentos ocupados: ");
  inserirInicio(&listal,voo);
}

void listarVoo(){
  	LISTA listaTemp = listal;
    while(listaTemp!=NULL){
      printf("Voo número: %i\n",listaTemp->info.numeroVoo);
      listaTemp = listaTemp->prox;
    }
}

void reservarAcento(){
  int busca,quantidadeReserva;
  busca = capturaInt("Digite o número do voo: ");
  LISTA listaTemp = listal;
  while(listaTemp!=NULL){
    if(listaTemp->info.numeroVoo == busca){
      quantidadeReserva = capturaInt("Digite quantos lugares deseja reservar: ");
      listaTemp->info.qtdeAssentosOcupados = listaTemp->info.qtdeAssentosOcupados+quantidadeReserva;
    }
    listaTemp = listaTemp->prox;
  }
}

void cancelarVoo(){
  int busca;
  busca = capturaInt("Digite o voo que pretende cancelar: ");
  while(listal!=NULL){
    if(listal->info.numeroVoo==busca){
      LISTA n=listal;
      if(n==NULL) return;
      listal=n->prox;
      free(n);
    }
    listal = listal->prox;
  }

}

void cancelarPassagem(){
  int busca,quantidadeReserva;
  busca = capturaInt("Digite o número do voo: ");
  LISTA listaTemp = listal;
  while(listaTemp!=NULL){
    if(listaTemp->info.numeroVoo == busca){
      quantidadeReserva = capturaInt("Digite quantos lugares deseja cancelar: ");
      listaTemp->info.qtdeAssentosOcupados = listaTemp->info.qtdeAssentosOcupados-quantidadeReserva;
    }
    listaTemp = listaTemp->prox;
  }
}

int main(){
  espMenu5Opcoes("Incluir Voo",incluirVoo,"listar Voo",listarVoo,"Reservar Acento",reservarAcento,"Cancelar Voo",cancelarVoo,"Cancelar Passagem",cancelarPassagem);
	system("PAUSE");
}
