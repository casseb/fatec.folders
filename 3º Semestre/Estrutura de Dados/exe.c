#include <stdio.h>

typedef struct cel{
	char *cont;
	struct cel *seg;
}Celula;

void add(Celula** aux, char *i){
	Celula *novo = malloc(sizeof(Celula));
	novo->cont = malloc(strlen(i)+1);
	strncpy(novo->cont, i, strlen(i)+1);
	novo->seg = *aux;
	*aux = novo;
}

void imprimir(Celula *aux){
	while(aux!=NULL){
		printf("\n%s",aux->cont);
		aux = aux->seg;
	}
}

int main(){
	Celula* lst = NULL;
	add(&lst,"Alfafa");
	add(&lst,"Teste");
	add(&lst,"Sei la");
	imprimir(lst);
	return 0;
}
