#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"

char prova[3][10],*gabarito;
int matricula[3];
int nota[3] = {0,0,0};

lerProvas(){
    int i,j;
    for(i=0;i<3;i++){
        printf("Digite a matricula do aluno: ");
        scanf("%i",&matricula[i]);
        getchar();
        for(j=0;j<10;j++){
            printf("Digite a resposta da questao %i: ",j+1);
            scanf("%c",&prova[i][j]);
            getchar();
            if(prova[i][j]==gabarito[j]){
                nota[i] = nota[i]+1;
            }
        }
    }
}

info(){
    int i;
    printf("\n ------------INFO------------- \n");
    printf("Gabarito \n");
    for(i=0;i<10;i++){
        printf("\nQuestao %i: %c",i+1,gabarito[i]);
    }
}

imprimeTotal(){
    int i,j;
    printf("\n --------------Conclusao------------\n");
    for(i=0;i<3;i++){
        printf("Aluno de matricula: %i \n",matricula[i]);
        printf("Respostas: \n");
        for(j=0;j<10;j++){
            printf("Questao %i: %c \n",j+1,prova[i][j]);
        }
        printf("Nota: %i \n",nota[i]);
        if(nota[i]<7){
            printf("Aluno Reprovado \n");
        }else{
            printf("Aluno Aprovado \n");
        }
    }
    system("pause");
}

main()
{
    gabarito = capturaVetorPalavras("Digite o gabarito: ",10);
    lerProvas();
    imprimeTotal();
}
