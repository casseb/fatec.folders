#include <stdio.h>

void imprimir(char p[50]){
	int i,j,k;
	for(i=0;p[i]!='\0';i++){
		for(j=i;p[j]!='\0';j++){
			for(k=i;k<=j;k++){
				printf("%c",p[k]);
				if(k==j){
					printf("\n");
				}
			}
		}
	}
}

int main(){
    char p[50];
    scanf("%s",&p);
	imprimir(p); 
	return 0;
}
