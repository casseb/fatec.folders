#include <stdio.h>

void quickSort(int v[], int i, int n){
	int meio;
	if(n!=0){
		meio = n/2;
		separa(v,n);
		quickSort(v,i,meio);
		quickSort(v,meio+1,n);
	}
}

void separa(int v[], int i, int n){
	int j=0, aux;
	for(i;i<n-1;i++){
		if(v[i]<v[n-1]){
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			j++;
		}
	}
	aux = v[n-1];
	v[n-1] = v[j];
	v[j] = aux;
}

int main(){
	int n = 5;
	int v[] = {90,23,67,21,70};
	quickSort(v,0,n);
	return 0;
}
