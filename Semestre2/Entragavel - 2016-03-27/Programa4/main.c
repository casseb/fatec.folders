#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"

typedef struct c{
    int raio;
    int centro;
} CIRCULO;

CIRCULO c1;

void perimetro(){
    int perimetro = 0;
    perimetro = 2*3.14*c1.raio;
    printf("\nO perimetro do circulo é de %i",perimetro);
}

void area(){
    int area = 0;
    area = 3.14*pow(c1.raio,2);
    printf("\nA área do circulo é de %i\n",area);
}

void imprimirCirculo(){
    int i,j,esq = c1.raio,dir = c1.raio;
    for(i=0;i<c1.raio+1;i++){
        for(j=0;j<((c1.raio)*2)+1;j++){
            if(j==(c1.raio)&&i==0){
                printf("-");

            }else if((j==esq||j==dir)){
                printf("-");
            }else{
                printf(" ");
            }
        }
        esq--;
        dir++;
        printf("\n");
    }
    esq++;
    dir--;
    for(i=0;i<c1.raio;i++){
        esq++;
        dir--;
        for(j=0;j<((c1.raio)*2)+1;j++){
            if(j==(c1.raio)&&i==c1.raio-1){
                printf("-");

            }else if(j==esq||j==dir){
                printf("-");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

void main()
{
    int raio,centro;
    raio = capturaInt("Digite a medida do raio da circuferência: ");
    centro = capturaInt("Digite a localização do centro da circuferência: ");

    c1.raio = raio;
    c1.centro = centro;

    perimetro();
    area();
    imprimirCirculo();
}
