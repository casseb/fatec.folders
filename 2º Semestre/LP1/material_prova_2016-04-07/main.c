#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"

int main()
{
    struct ponto {
	int x;
	int y;
    }vponto;

    struct ponto ponto1,ponto[4];

    ponto1.x = 4;
    ponto1.y = 5;
    printf("%i\n",ponto1.x);
    printf("%i\n",ponto1.y);
}
