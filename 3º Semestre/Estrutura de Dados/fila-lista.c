#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
	int cont;
	struct cel *seg;
}Celula;

Celula* add(Celula *f,int x){
	Celula *novo = malloc(sizeof(Celula));
	novo->cont = x;
	novo->seg = NULL;
	f->seg = novo;
	return novo;
}

Celula* remover(Celula *i){
	Celula *proximo = i->seg;
	free(i);
	return proximo;
}

imprimir(Celula *i){
	i = i->seg;
	while(i!=NULL){
		printf("%i\n",i->cont);
		i = i->seg;
	}
	printf("\n");
}

int main(){
	Celula *i = malloc(sizeof(Celula));
	i->seg = NULL;
	Celula *f = i;
	f =add(f,4);
	f =add(f,5);
	f =add(f,6);
	imprimir(i);
	i = remover(i);
	imprimir(i);	
	return 0;
}
