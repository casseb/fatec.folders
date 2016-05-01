#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"


void main()
{
    int dia = capturaInt("Digite o dia: ");
    int mes = capturaInt("Digite o mes: ");
    int ano = capturaInt("Digite o ano: ");
    char* diaDaSemana = impDiaDaSemana(dia,mes,ano);
    puts(diaDaSemana);
}

int inteiro;
float decimal;
int vInt[10], vInt2[] = {2,4};
char c = 'a';
char string[10];
