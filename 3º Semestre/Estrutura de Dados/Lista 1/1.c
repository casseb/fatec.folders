#include <stdio.h>

int somaVetores(int v[], int n){
	if(n==0){
		return 0;
	}
	else{
		return v[n-1]+somaVetores(v,n-1);
	}
}

int main(){
	
	int v[3] = {3,2,1};
	int resultado = 0;
	resultado = somaVetores(v,3);
	printf("%i",resultado);
	return 0;
	
}
