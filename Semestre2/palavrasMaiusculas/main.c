#include <stdio.h>
#include <stdlib.h>

char nomes[5][30];

void capturaNomes(){
    int i;
    printf("Digite os 5 nomes: \n");
    for(i=0;i<5;i++){
        fflush(stdin);
        gets(nomes[i]);
    }
}

void maiuscula(){
    int i,j;
    char nomesMaiusculo[5][30];

    for(i=0;i<5;i++){
        for(j=0;j<strlen(nomes[i]);j++){
            nomesMaiusculo[i][j] = toupper(nomes[i][j]);
        }
    }

    printf("\n");

    for(i=0;i<5;i++){
        puts(nomesMaiusculo[i]);
    }
    system("pause");
}

void main()
{
    capturaNomes();
    maiuscula();
}
