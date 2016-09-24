#include <stdio.h>
#include <stdlib.h>

void main()
{

    char *dia_semana(int n) { /* Aqui foi usado um ponteiro de chars */
        char *d[] = { /* Aqui também */
            "erro",
            "domingo",
            "segunda-feira",
            "terça-feira",
            "quarta-feira",
            "quinta-feira",
            "sexta-feira",
            "sábado"
        };
        return d[1<=n && n<=7 ? n : 0];/*Será retornado uma string baseado no número informado
        como parâmetro, dentro do return há uma operação ternária retornando ele mesmo caso seja de 1 a 7
        ou zero, que no caso é a posição que esta escrito "erro" caso não esteja neste rage*/
    }

    printf("%s",dia_semana(4));
}
