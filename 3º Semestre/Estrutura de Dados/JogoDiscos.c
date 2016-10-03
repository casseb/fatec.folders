#include <stdio.h>

typedef struct cel{
	int cont;
	struct cel *seg;
}Celula;

int empilha(Celula *t, int x){
	if(t->seg == NULL || t->seg>=x ){
		add(t,x);
		return 1;
	}else{
		return 0;
	}
}

void transfere(Celula *to, Celula *td){
	if(to->seg == NULL){
		printf("\nPilha origem vazia");
	}else if(td->seg == NULL){
		empilha(td,remover(to));
	}else{
		if(td->seg->cont>=to->seg->cont){
			empilha(td,remover(to));
		}else{
			printf("\nMovimento invalido");
		}
	}
}

void add(Celula *t, int x){
	Celula *novo = malloc(sizeof(Celula));
	novo->cont = x;
	novo->seg = t->seg;
	t->seg = novo;
}

int remover(Celula *t){
	Celula *lixo = t->seg;
	int x = lixo->cont;
	t->seg = lixo->seg;
	free(lixo);
	return x;
}

void imprimir(Celula *t){
	t = t->seg;
	while(t!=NULL){
		printf("\n%i",t->cont);
		t = t->seg;
	}
}

int main(){
	Celula *p1 = malloc(sizeof(Celula));
	p1->seg = NULL;
	
	Celula *p2 = malloc(sizeof(Celula));
	p2->seg = NULL;
	
	Celula *p3 = malloc(sizeof(Celula));
	p3->seg = NULL;
	
	empilha(p1,10);
	empilha(p1,8);
	empilha(p1,5);
	
	imprimir(p1);
	
	transfere(p1,p2);
	printf("\n");
	imprimir(p2);
	printf("\n");
	imprimir(p1);
	transfere(p1,p2);
	
	
	
	return 0;
}
