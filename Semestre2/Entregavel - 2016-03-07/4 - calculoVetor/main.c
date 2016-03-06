#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"

main()
{
    int *numeros;
    numeros = (int *)malloc(15 * sizeof(int));
    numeros = capturaNNumeros("Digite 15 números: ",15);
    impVetorInt(numeros, 15);
    impMaiorNumeroVetorInt(numeros,15);
    impMenorNumeroVetorInt(numeros,15);
}
