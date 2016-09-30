#include <stdio.h>

int *Distancias (int **A, int n, int o) {
	int *d, x, y;
	int *f, s, t;
	d = malloc (n * sizeof (int));
	for (x = 0; x < n; x++) d[x] = -1;
		d[o] = 0;
		f = malloc (n * sizeof (int));
		s = 0; t = 1; f[s] = o; /* o entra na fila */
	while (s < t) {
		x = f[s++]; /* x sai da fila */
		for (y = 0; y < n; y++)
			if (A[x][y] == 1 && d[y] == -1) {
				d[y] = d[x] + 1;
				f[t++] = y; /* y entra na fila */
			}
	}
	free (f);
	return d;
}



int main(){
	
	int n = 4;
	int A[n][n];
	int *Matriz;
	Matriz = &A;
	int i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			A[i][j] = 0;
		}
	}
	
	
	A[0][1] = 1;
	A[1][2] = 1;
	A[2][4] = 1;
	A[3][2] = 1;
	A[3][4] = 1;
	A[4][0] = 1;
	A[5][1] = 1;
	
	printf("%i",A[0][0]);
	
	//int *resultado = malloc(n*sizeof(int));
	//resultado = Distancias(&Matriz,n,3);
	
	//for(i=0;i<=5;i++) printf("\n %i",resultado[i]);
	
	return 0;
}
