#include <stdio.h>

int somaVetores(int n, int v[]){
	if(n>0){
		return 0;
	}else{
		int soma = v[n];
		somaVetores(n-1,v);
		soma = soma + v[n];
		printf("%i ",soma);
	}
	
}

int main(){
	int v[3] = (5,3,2);
	printf("%i",somaVetores(2,v));
	return 0;
	
}
