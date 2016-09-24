#include <stdio.h>
#include "bycasseb.h"

typedef struct{
char nome[30];
int idade} PESSOA;

main()
{

PESSOA *p;
p = malloc (10 * sizeof (PESSOA));

PESSOA x[10];

int i;
for(i=0;i<10;i++){
    printf("Digite o nome: ");
    fflush(stdin);
    gets(x[i].nome);
    printf("Digite a idade: ");
    scanf("%i",&x[i].idade);
    getchar();
}


p = x;

for(i=0;i<10;i++){
    printf("\n%s,%d\n", (p+i)->nome, (p+i)->idade );
}

system("pause");}
