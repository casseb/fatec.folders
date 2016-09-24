#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void impSeparaFracao(float numero)
{
    setlocale(LC_ALL, "Portuguese");
    printf("\nParte inteira: %1.f ",floor(numero));
    printf("Parte decimal: %0.2f \n",numero-floor(numero));
}

float capturaFloat(char enunciado[50]){
    setlocale(LC_ALL, "Portuguese");
    printf(enunciado);
    float numero;
    scanf("%f",&numero);
    return numero;
}

void impVariavelFloat(float variavel){
    printf("\n%Variavel Float: %.2f\n",variavel);
}
