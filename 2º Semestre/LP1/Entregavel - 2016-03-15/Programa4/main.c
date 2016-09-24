#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "bycasseb.h"

void main()
{
    setlocale(LC_ALL, "Portuguese");

    /*Teste função strupr*/
    char up[] = "teste";
    strupr(up);
    printf("Teste função strupr: ");
    puts(up);

    /*Teste função strcat*/
    char* cat3;
    char* cat1 = "teste1";
    char* cat2 = "teste2";
    cat3 = strcat(cat1,cat2);
    printf("Teste função strcat: ");
    puts(cat3);

    /*Teste função strpos*/
    int pos;
    pos = strpos("teste",'e');
    printf("Teste função strpos: ");
    printf("%i\n",pos);

    /*Teste função strdel*/
    char* del;
    del = strdel("teste",3);
    printf("Teste função strdel: ");
    puts(del);

    /*Teste função strins*/
    char* ins;
    ins = strins('x',"teste",3);
    puts(ins);
}
