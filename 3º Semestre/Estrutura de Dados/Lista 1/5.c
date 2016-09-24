#include <stdio.h>


int main(){

	double vAltura[5] = {1.5,1.8,1.75,1.6,2.0};
	scanf("%d",&vAltura[0]);
	char vSexo[5] = {'M','M','F','F','M'};

	double somaAltura = 0;
	
	double somaAlturaHomens = 0;
	double somaAlturaMulheres = 0;
	double maiorAltura = 0;
	int quantMulheres = 0;
	int i;
	for(i=0;i<5;i++){
		if(vSexo[i] == 'M'){
			somaAlturaHomens = somaAlturaHomens + vAltura[i];
		}else{
			somaAlturaMulheres = somaAlturaMulheres + vAltura[i];
			quantMulheres = quantMulheres+1;
		}
		if(vAltura[i]>maiorAltura){
			maiorAltura = vAltura[i];
		}
		somaAltura = somaAltura + vAltura[i]; 
	}
	
	printf("Media de altura: %f\n",somaAltura/5);
	printf("Maior Altura: %f\n",maiorAltura);
	printf("Média dos Homens: %f\n",somaAlturaHomens/(5-quantMulheres));
	printf("Média das Mulheres: %f\n",somaAlturaMulheres/quantMulheres);
	printf("Quantidade de mulheres: %i\n",quantMulheres);
}
