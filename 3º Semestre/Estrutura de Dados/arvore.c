#include <stdio.h>

typedef struct cel{
	int valor;
	struct cel* dir;
	struct cel* esq;
}no;

void insere(no* raiz,int i){
	no *novo = malloc(sizeof(no));
	novo->valor = i;
	novo->dir = NULL;
	novo->esq = NULL;

	for(;;){
		
		if(raiz->valor > i){
			if(raiz->esq==NULL){
				raiz->esq = novo;
				break;
			}
			raiz = raiz->esq;
		}else{
			if(raiz->dir==NULL){
				raiz->dir = novo;
				break;
			}
			raiz = raiz->dir;
		}
	}
}

/*
no* pai(no* raiz,int n){
	while(raiz->esq->valor!=n || raiz->esq->valor!=n){
		if(raiz==NULL) return NULL;
		if(raiz->valor > n){
			raiz = raiz->esq;
		}else{
			raiz = raiz->dir;
		}
	}
	return raiz;
}
*/

void imprimir(no* raiz){
	if(raiz!=NULL){
		imprimir(raiz->esq);
		printf("%i\n",raiz->valor);
		imprimir(raiz->dir);
	}
}

int main(){
	no *raiz = malloc(sizeof(no));
	raiz->valor = 10;
	raiz->dir = NULL;
	raiz->esq = NULL;
	insere(raiz,7);
	insere(raiz,12);
	insere(raiz,0);
	insere(raiz,15);
	imprimir(raiz);
	
	return 0;
}
