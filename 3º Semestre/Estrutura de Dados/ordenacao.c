#include <stdio.h>

void shellSort(int v[], int n){
	int i, j, aux,gap;
	for(gap = n/2; gap>0; gap = gap/2){
		printf("%i",gap);
		for(i=gap;i<n;i++){
			aux = v[i];
			for(j=i;v[j-gap]>aux && j>0; j=j-gap){
				v[j] = v[j-gap];
			}
			v[j] = aux;
			printf("\n");
		}
		printf("\n");
	}
	
	for(i=0;i<n;i++){
		printf("\n%i",v[i]);
	}
}

int main(){
	int n = 5;
	int v[] = {9,7,4,16,3};
	shellSort(v,n);
	return 0;
}
