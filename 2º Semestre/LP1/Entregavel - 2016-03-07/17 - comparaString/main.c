#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"

char s1[20],s2[20],s1Cat[20],s1Inv[20],c1,c2;
int c1Count;

void inverteFrase(char palavra[20]){
    int i;
    int j=0;
    for(i=strlen(palavra)-1;i>-1;i--){
        s1Inv[j] = s1Inv[j]+palavra[i];
        j = j+1;
    }
    s1Inv[strlen(palavra)] = palavra[strlen(palavra)];
}

void contaCaracteres(){
    int i;
    c1Count = 0;
    for(i=0;i<strlen(s1);i++){
        if(s1[i]==c1){
            c1Count = c1Count+1;
        }
    }
}

void trocaCaracteres(){
    int i;
    c1Count = 0;
    for(i=0;i<strlen(s1);i++){
        if(s1[i]==c1){
            s1[i] = c2;
        }
    }
}


main()
{
    printf("Digite S1: ");
    fflush(stdin);
    gets(s1);
    printf("\nTamanho da S1: %i caracteres\n",strlen(s1));
    printf("Digite S2: ");
    fflush(stdin);
    gets(s2);
    printf("\nRetorno da comparacao das strings: %i\n",strcmp(s1,s2));
    strcpy(s1Cat,s1);
    printf("Retorno da concatenacao das strings: %s\n",strcat(s1Cat,s2));
    inverteFrase(s1);
    printf("Retorno da string S1 ao contrario: %s\n",s1Inv);
    printf("Digite o caracter que deseja contar:\n");
    scanf("%c",&c1);
    getchar();
    contaCaracteres();
    printf("Retorno da quantidade de %c em %s: %i vezes\n",c1,s1,c1Count);
    printf("Digite o caracter que deseja que fique no lugar:\n");
    scanf("%c",&c2);
    getchar();
    trocaCaracteres();
    printf("\nResultado da troca dos caracteres: %s\n",s1);
    system("pause");
}
