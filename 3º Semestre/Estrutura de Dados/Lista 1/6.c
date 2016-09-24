#include <stdio.h>


int main(){
	char p[50] = "teste";
	int i,j,k;
	for(i=0;p[i]!='\0';i++){
		for(j=i;p[j]!='\0';j++){
			for(k=i;k==j;k++){
				printf("%c",p[k]);
			}
			printf("\n");
		}
	}
	return 0;
}
