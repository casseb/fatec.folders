#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Biblioteca ByCasseb Versão 0.4 */

/*Legenda:
imp = Retorna impressão na tela
captura = Preenche variavel com conteúdo do usuário
esp = Casos especiais
regra = Regra de negócio, usado somente em 1 programa


/* Imprimindo valores na tela */


void impVariavelFloat(float variavel){
    printf("\n%Variavel Float: %.2f\n",variavel);
    system("pause");
}

void impVetorInt(int *numeros, int quantNumeros){
    int i;
    for(i=0;i<quantNumeros;i++){
        printf("%i = %i\n",i,numeros[i]);
    }
    system("pause");
}

void impSeparaFracao(float numero)
{
    setlocale(LC_ALL, "Portuguese");
    printf("\nParte inteira: %1.f ",floor(numero));
    printf("Parte decimal: %0.2f \n",numero-floor(numero));
    system("pause");
}

void impFloatMaisPorcentagem(char enunciado[50], float numero, float porcentagem){
    setlocale(LC_ALL, "Portuguese");
    printf(enunciado);
    printf("%.2f\n",numero*(porcentagem/100));
    system("pause");
}

void impFloatMaisValor(char enunciado[50], float numero, float valor){
    setlocale(LC_ALL, "Portuguese");
    printf(enunciado);
    printf("%.2f\n",numero+valor);
    system("pause");
}

void impMaiorNumeroVetorInt(int *numeros, int quantNumeros){
    setlocale(LC_ALL, "Portuguese");
    int maiorNumero = 0;
    int maiorPosicao = 0;
    int i;
    for(i=0;i<quantNumeros;i++){
        if(maiorNumero<numeros[i]){
            maiorNumero = numeros[i];
            maiorPosicao = i;
        }
    }
    printf("Maior numero da lista é: %i presente na posicao: %i \n",maiorNumero,maiorPosicao);
}

void impMenorNumeroVetorInt(int *numeros, int quantNumeros){
    int menorNumero = 99999999;
    int menorPosicao = 0;
    int i;
    for(i=0;i<quantNumeros;i++){
        if(menorNumero>numeros[i]){
            menorNumero = numeros[i];
            menorPosicao = i;
        }
    }
    printf("Menor numero da lista é: %i presente na posicao: %i \n",menorNumero,menorPosicao);
}


/* Capturando variáveis do usuário */

float capturaFloat(char enunciado[50]){
    setlocale(LC_ALL, "Portuguese");
    printf(enunciado);
    float numero;
    scanf("%f",&numero);
    getchar();
    return numero;
}

int* capturaNNumeros(char enunciado[50],int quantNumeros){
    setlocale(LC_ALL, "Portuguese");
    printf(enunciado);
    int i;
    int *numeros;
    numeros = (int *)malloc(quantNumeros * sizeof(int));
    for(i=0;i<quantNumeros;i++){
        scanf("%i",&numeros[i]);
    }
    return numeros;
}

/* Especiais */

typedef void (*Opcoes)();

void espMenu3Opcoes(char opcao1[50],Opcoes funcOpcao1,char opcao2[50],Opcoes funcOpcao2,char opcao3[50],Opcoes funcOpcao3){
    setlocale(LC_ALL, "Portuguese");
    char opcao;
    do{
        system("cls");
        printf("Menu de opcoes \n------------------- \n \n");
        printf("(a)-%s , (b)-%s, (c)-%s, (d)-Sair\n",opcao1,opcao2,opcao3);
        scanf("%c",&opcao);
        getchar();
        switch(opcao){
            case('a'):
                funcOpcao1();
                break;
            case('b'):
                funcOpcao2();
                break;
            case('c'):
                funcOpcao3();
                break;
            case('d'):
                break;
            default:
                printf("Opcao inválida \n");
                system("pause");
                break;
        }
    }while(opcao!='d');
}

/* Regras de negócio */

void regraImposto()
{
    float salario;
    salario = capturaFloat("Digite o salário: ");
    if(salario<500){
        impFloatMaisPorcentagem("Imposto a ser pago: R$",salario,5);
    }else{
        if(salario>=500 && salario<=850){
            impFloatMaisPorcentagem("Imposto a ser pago: R$",salario,10);
        }else{
            impFloatMaisPorcentagem("Imposto a ser pago: R$",salario,15);
        }
    }
}

void regraAumentoSalario()
{
    float salario;
    salario = capturaFloat("Digite o salário: ");
    if(salario<450){
        impFloatMaisValor("Novo Salário: R$",salario,100);
    }
    else{
        if(salario>=450 && salario<=750){
            impFloatMaisValor("Novo Salário: R$",salario,75);
        }
        else{
            if(salario>750 && salario<=1500){
                impFloatMaisValor("Novo Salário: R$",salario,50);
            }
            else{
                impFloatMaisValor("Novo Salário: R$",salario,25);
            }
        }
    }
}

void regraClassificacao()
{
    float salario;
    salario = capturaFloat("Digite o salário: ");
    if(salario<=700){
        printf("Mal remunerado \n");
    }else{
        printf("Bem remunerado \n");
    }
    system("pause");
}
