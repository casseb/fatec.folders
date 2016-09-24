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

void imprimir(Celula *aux){
	aux= aux->seg;
	while(aux!=NULL){
		printf("%i",aux->cont);
		aux = aux->seg;
	}	
}

int main(){
    Celula *lst = malloc(sizeof(Celula));
    lst->seg = NULL;
    add(lst,3);
    add(lst,2);
    add(lst,1);
    imprimir(lst);
	return 0;
}
