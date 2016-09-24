#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"


main()
{
    float numero;
    numero = capturaFloat("Digite um número: ");
    impSeparaFracao(numero);
    system("pause");
}
