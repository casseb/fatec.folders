#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"
#define CONSUMO 10

float gasolina = 0;

void regraAndar(){
    float distancia;
    distancia = capturaFloat("Quantos kms você percorreu? ");
    if(distancia>(gasolina*CONSUMO)){
        printf("Você tentou mas sua gasolina acabou =-( \n");
        gasolina = 0;
    }
    else{
        printf("Voce andou %.2f km \n",distancia);
        gasolina = gasolina - (distancia/CONSUMO);
    }
    system("pause");
}

void regraObterGasolina(){
    float obterGasolina(){
        return gasolina;
    }
    printf("Voce tem atualmente %.2f litros de gasolina \n",obterGasolina());
    system("pause");
}

void regraAdicionarGasolina(){
    void adicionarGasolina(float litros){
        gasolina = gasolina+litros;
    }
    float litros;
    litros = capturaFloat("Quantos litros deseja abastecer: ");
    adicionarGasolina(litros);
    system("pause");
}

void main(){
    espMenu3Opcoes("Andar",regraAndar,"Consultar Gasolina",regraObterGasolina,"Abastecer",regraAdicionarGasolina);
}

