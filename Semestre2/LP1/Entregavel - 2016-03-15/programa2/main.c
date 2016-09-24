#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"

int valor,valorRestante;
int countNotas[5] = {100,50,10,5,1},quantNotas[5];

int calcCountNotas(int indiceNota){
    int count = floor(valorRestante/countNotas[indiceNota]);
    valorRestante = valorRestante-(countNotas[indiceNota]*count);
    return count;
}

void main()
{
    valor = capturaInt("Digite o valor: R$");
    valorRestante = valor;
    int i;
    for(i=0;i<5;i++){
        quantNotas[i] = calcCountNotas(i);
        printf("%i notas de R$%i \n",quantNotas[i],countNotas[i]);
    }
    system("pause");
}
