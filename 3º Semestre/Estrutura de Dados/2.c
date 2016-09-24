#include <stdio.h>

typedef struct cel{
	int cont;
	struct cel *seg;
}Celula;

void imprimir(Celula *LST){
	while(LST!=NULL){
		printf("%i",LST->cont);
		LST= LST->seg;
	}
}

int main(){
	int *A;
	Celula *LST;
	LST = (Celula*) malloc(sizeof(Celula));
	LST->cont = 10;
	LST->seg = NULL;
	imprimir(LST);	
	imprimir(LST);
	return 0;
}
