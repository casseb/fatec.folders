#include <stdio.h>

void heapSort(int v[], int n){
	int i, j, aux;
	
	for(i=n; i>0; i--){
		for(j=i; j>0; j--){
			if(v[j]<v[j/2]){
				aux = v[j];
				v[j] = v[j/2];
				v[j/2] = aux;
			}
		}
	}
	
	
	for(i=0;i<n;i++){
		printf("\n%i",v[i]);
	}
}

int main(){
	int n = 5;
	int v[] = {90,23,67,21,70};
	heapSort(v,n);
	return 0;
}
