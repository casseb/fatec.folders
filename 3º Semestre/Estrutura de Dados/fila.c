#include <stdio.h>

void add(int v[], int n, int *i,int *f, int x){
	if(*f == *i-1 || (*i==0 && *f==n-1)){
		printf("Não foi possivel adicionar, fila cheia");
	}
	else
		v[(*f)++] = x;
}

int remover(int v[], int *i, int *f, int n){
	if(*i==*f)
		printf("Não foi possivel remover, lista já vazia");
	else
		return v[(*i)++];
}

void imprimir(int v[], int *i, int *f){
	int c;
	for(c = *i; c<*f; c++){
		printf("\n%i",v[c]);
	}
	printf("\n\n");
}

int main(){
	int v[7];
	int i = 0,f = 0,n = 7;
	add(v,n,&i,&f,10);
	imprimir(v,&i,&f);
	remover(v,&i,&f,n);
	return 0;
}
