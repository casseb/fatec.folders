#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"

void imprimirnumeros(int numeros[],int quantNumeros){
    int i;
    printf("[");
    for(i=0;i<quantNumeros;i++){
        if(i==quantNumeros-1){
            printf("%i",numeros[i]);
        }else{
        printf("%i,",numeros[i]);
        }
    }
    printf("]\n");
}

void selection(){
    int quantNumeros;
    quantNumeros = capturaInt("Digite quantos números deseja ordenar: ");
    int i,j,temp,menor;
    int numeros[quantNumeros];

    for(i=0;i<quantNumeros;i++){
        printf("Digite o numero %i: ",i+1);
        scanf("%i",&numeros[i]);
        getchar();
    }

    printf("numeros antes da ordenacao: ");
    imprimirnumeros(numeros,quantNumeros);

    for(i=0;i<quantNumeros-1;i++){
        printf("\nIndice %i",i);
        imprimirnumeros(numeros,quantNumeros);
        menor = i;
        for(j=i+1;j<quantNumeros;j++){
            if(numeros[j]<numeros[menor]){
                menor = j;
            }
        }
        if(i != menor){
            temp = numeros[i];
            numeros[i] = numeros[menor];
            numeros[menor] = temp;
        }
    }

    printf("\n\nnumeros depois da ordenacao: ");
    imprimirnumeros(numeros,quantNumeros);
}

void insercion(){

    int quantNumeros;
    quantNumeros = capturaInt("Digite quantos números deseja ordenar: ");
    int i,j,temp,menor;
    int numeros[quantNumeros];

    for(i=0;i<quantNumeros;i++){
        printf("Digite o numero %i: ",i+1);
        scanf("%i",&numeros[i]);
        getchar();
    }

    printf("numeros antes da ordenacao: ");
    imprimirnumeros(numeros,quantNumeros);
    printf("\n");
    for(i=1; i<quantNumeros; i++){
        printf("Indice %i",i);
        imprimirnumeros(numeros,quantNumeros);
        j=i;
        while((j != 0) && (numeros[j] < numeros[j-1])) {
            temp = numeros[j];
            numeros[j] = numeros[j-1];
            numeros[j-1] = temp;
            j--;
        }
    }

    printf("\n\nnumeros depois da ordenacao: ");
    imprimirnumeros(numeros,quantNumeros);
}

void bubble(){
    int quantNumeros;
    quantNumeros = capturaInt("Digite quantos números deseja ordenar: ");
    int i,j,h,temp,menor;
    int numeros[quantNumeros];

    for(i=0;i<quantNumeros;i++){
        printf("Digite o numero %i: ",i+1);
        scanf("%i",&numeros[i]);
        getchar();
    }

    printf("numeros antes da ordenacao: ");
    imprimirnumeros(numeros,quantNumeros);

    for(j=quantNumeros-1; j>=1; j--){
        printf("\nIndice %i",i);
        imprimirnumeros(numeros,quantNumeros);
        for(i=0; i<j; i++){
            if(numeros[i] > numeros[i+1]){
                temp=numeros[i];
                numeros[i]=numeros[i+1];
                numeros[i+1]=temp;
            }
        }
    }

    printf("\n\nnumeros depois da ordenacao: ");
    imprimirnumeros(numeros,quantNumeros);
}

void comb(){

    int quantNumeros;
    quantNumeros = capturaInt("Digite quantos números deseja ordenar: ");
    float fator = 1.247330950103979;
    int i,j,h,temp,menor,verificador = 1,distancia;
    int numeros[quantNumeros];

    for(i=0;i<quantNumeros;i++){
        printf("Digite o numero %i: ",i+1);
        scanf("%i",&numeros[i]);
        getchar();
    }

    printf("numeros antes da ordenacao: ");
    imprimirnumeros(numeros,quantNumeros);
    distancia = quantNumeros;

    while ((distancia>1) || verificador) {
        if (distancia>1)
           distancia=distancia/fator;
           verificador = 0;
           i = 0;
        while((distancia+i)<quantNumeros) {
            printf("\nIndice %i",i);
            imprimirnumeros(numeros,quantNumeros);
            if(numeros[i]-numeros[i+distancia]>0){
                temp = numeros[i];
                numeros[i] = numeros[i+distancia];
                numeros[i+distancia] = temp;
                verificador = 1;
            }
            ++i;
        }
    }

    printf("\n\nnumeros depois da ordenacao: ");
    imprimirnumeros(numeros,quantNumeros);
}

void shell(){

    int quantNumeros;
    quantNumeros = capturaInt("Digite quantos números deseja ordenar: ");
    int i,j,h,temp,verificador = 1,distancia;
    int numeros[quantNumeros];

    for(i=0;i<quantNumeros;i++){
        printf("Digite o numero %i: ",i+1);
        scanf("%i",&numeros[i]);
        getchar();
    }

    printf("numeros antes da ordenacao: ");
    imprimirnumeros(numeros,quantNumeros);
    distancia = quantNumeros;

    while(distancia<quantNumeros) {
        distancia = 3*distancia+1;
    }
    while (distancia>1) {
        distancia/= 3;
        for(i=distancia;i<quantNumeros;i++) {
            printf("\nIndice %i",i);
            imprimirnumeros(numeros,quantNumeros);
            temp = numeros[i];
            j = i-distancia;
            while (j>=0 && temp<numeros[j]) {
                numeros [j + distancia] = numeros[j];
                j -= distancia;
            }
            numeros[j+distancia] = temp;
        }
    }

    printf("\n\nnumeros depois da ordenacao: ");
    imprimirnumeros(numeros,quantNumeros);
}

int main()
{
    espMenu5Opcoes("Selection Sort",selection,"Insertion Sort",insercion,"Bubble Sort",bubble,"Comb Sort",comb,"Shell Sort",shell);
    return 0;
}
