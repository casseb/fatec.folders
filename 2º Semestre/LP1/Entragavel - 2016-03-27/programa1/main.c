#include <stdio.h>

typedef struct{

char nome[31];

int idade} PESSOA;

main()

{

PESSOA *p;

PESSOA x = {"Silvio", 32};

p = &x;
printf("\n%s,%d\n", (*p).nome, (*p).idade );/* Na declaração a idade o p estava sem seu *, desta forma ele estava
pegando o caminho da memória e procurando idade nela, mas o correto é pegar o valor de pessoa e a partir
dele a idade*/

printf("\n%s\n",p->nome);/* Sim, esta chamada esta correta, sendo uma outra forma de pegar um membro da estrutura de um ponteiro*/

system("pause");
}
