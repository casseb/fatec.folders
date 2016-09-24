#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"

int **matrizOriginal1;
int **matrizOriginal2;
int **somaMatriz;
int **diferencaMatriz;

opcaoA(){
    somaMatrizes(matrizOriginal1,matrizOriginal2,4,4);
}

opcaoB(){
    subtraiMatrizes(matrizOriginal1,matrizOriginal2,4,4);
}

main()
{
    matrizOriginal1 = capturaMatriz("Digitando a primeira matriz: ",4,4);
    matrizOriginal2 = capturaMatriz("Digitando a segunda matriz: ",4,4);
    impMatrizInt(matrizOriginal1,4,4);
    impMatrizInt(matrizOriginal2,4,4);
    espMenu2Opcoes("Adição",opcaoA,"Subtração",opcaoB);

}

