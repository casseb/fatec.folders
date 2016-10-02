#include <stdio.h>

typedef struct cel{
	int cont;
	struct cel *seg;
}Celula;

void add(Celula *aux, int i){
	Celula *novo = malloc(sizeof(Celula));
	novo->cont = i;
	novo->seg = aux->seg;
	aux->seg = novo;
}


void intercala(Celula **L3,Celula *L1, Celula *L2){
	*L3 = L1;
	L1 = L1->seg;
	L2 = L2->seg;
	while(L1!=NULL){
		Celula* provL1 = L1->seg;
		Celula* provL2 = L2->seg;
		L1->seg = L2;
		L2->seg = provL1;
		L1 = provL1;
		L2 = provL2;
	}
}


void imprimir(Celula *aux){
	aux= aux->seg;
	while(aux!=NULL){
		printf("%i",aux->cont);
		aux = aux->seg;
	}
}

int main(){
	Celula* L1 = malloc(sizeof(Celula));
	L1->seg = NULL;
	Celula* L2 = malloc(sizeof(Celula));
	L2->seg = NULL;
	Celula* L3 = malloc(sizeof(Celula));
	L3->seg = NULL;
	
	add(L1,5);
	add(L1,3);
	add(L1,1);
	
	add(L2,6);
	add(L2,4);
	add(L2,2);
	
	intercala(&L3,L1,L2);

	imprimir(L3);
	
	return 0;
}
