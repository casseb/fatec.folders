#include <stdio.h>

int BuscaBinaria (int x, int n, int v[]) {
	int i, m;
	i = -1;
	while (i < n - 1) {
		m = (i + n)/2;
		if (v[m] < x) i = m;
		else n = m;
	}
	return n;
}

int main(){
	int n = 11;
	int v[n];
	int i;
	for(i=5;i<10;i++){
		v[i] = i;
	}
	
	printf("%i",BuscaBinaria(15,n,v));
	
	return 0;
}

