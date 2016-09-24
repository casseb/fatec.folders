#include <stdio.h>
#include <stdlib.h>

char palavra1[20],palavra2[20];

void anagrama(){
    if(strlen(palavra1)!=strlen(palavra2)){
        printf("Nao e anagrama");
    }else{
        int i,j;
        char aux[30];
        for(i=0;i<strlen(palavra1);i++){
            for(j=0;j<strlen(palavra1);j++){
                if(palavra1[i]>palavra1[j]){
                    aux[i] = palavra1[j];
                    palavra1[j] = palavra1[i];
                    palavra1[i] = aux[i];
                }
            }
        }
        for(i=0;i<strlen(palavra2);i++){
            for(j=0;j<strlen(palavra2);j++){
                if(palavra2[i]>palavra2[j]){
                    aux[i] = palavra2[j];
                    palavra2[j] = palavra2[i];
                    palavra2[i] = aux[i];
                }
            }
        }
        if(strcmp(palavra1,palavra2)==0){
            printf("Sao anagramas");
        }else{
            printf("Nao sao anagramas");
        }
   }

}

void main()
{
    printf("Digite a primeira palavra: ");
    fflush(stdin);
    gets(palavra1);
    printf("Digite a segunda palavra: ");
    fflush(stdin);
    gets(palavra2);
    anagrama();
}
