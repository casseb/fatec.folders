#include <stdio.h>
#include <stdlib.h>

void main()
{
    int *p, x=5;/* Criando ponteiro de inteiro com o *p e uma varável inteira x com conteúdo 5*/
    *p *= 2**p;/* ponteiro de p (*p) esta recebendo ele mesmo vezes 2 vezes ele mesmo, ou seja, (ponteiro de p) = (ponteiro de p) vezes (2 vezes ponteiro de p) */
    printf("%d", x);/*Ao final ele imprime x, que foi iniciado como 5 e permaneceu como 5 */
}
