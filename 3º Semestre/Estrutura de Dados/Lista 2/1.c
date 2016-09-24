#include <stdio.h>

int maior(int v[],int n){
	int m = 0;
	if(n==0){
		v[n];
	}else{
		if(v[n]>maior(v,n-1)){
			printf("Foi");
		}
	}
}

int main(){
	int v[5] = {2,7,1,2,1};
	int m = 0;
	m = maior(v,5);
	printf("%i",m);
	return 0;
}
