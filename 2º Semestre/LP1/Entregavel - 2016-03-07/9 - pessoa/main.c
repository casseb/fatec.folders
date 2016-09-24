#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"

char* nome;
int idade = 0;
float peso,altura;

regraEnvelhecer(){
    int anos;
    anos = capturaInt("Quantos anos envelheceu? ");
    idade = idade+anos;
    if(idade<21){
        altura = altura + (anos+0,5);
    }
    info();
}

regraEngordar(){
    float kg;
    kg = capturaFloat("Quantos quilos engordou? ");
    peso = peso+kg;
    info();
}

regraEmagrecer(){
    float kg;
    kg = capturaFloat("Quantos quilos emagreceu? ");
    peso = peso-kg;
    info();
}

regraCrescer(){
    float cm;
    cm = capturaFloat("Quantos centímetros cresceu? ");
    altura = altura+cm;
    info();
}

info(){
    printf("\nNome: %s \n Idade: %i \n Peso: %.2f \n Altura: %.2f \n",nome,idade,peso,altura);
    system("pause");
}

main()
{
    nome = capturaPalavra("Digite seu nome: ");
    espMenu4Opcoes("Envelhecer",regraEnvelhecer,"Engordar",regraEngordar,"Emagrecer",regraEmagrecer,"Crescer",regraCrescer);
}
