#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"

void main()
{
    int *planeta = (int *)malloc(3 * sizeof(int));
    int **naves = (int **)malloc(5 * sizeof(int));
    planeta = capturaNNumeros("Digite as coordenadas do planeta: ",3);
    naves = capturaMatriz("Digite as coordenadas da nave ",5,3);
    regraOrdenaNaves(planeta,naves);
}
