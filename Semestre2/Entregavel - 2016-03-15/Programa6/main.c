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
