#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Capturando vari�veis do usu�rio */

float capturaFloat(char enunciado[50]){
    setlocale(LC_ALL, "Portuguese");
    printf(enunciado);
    float numero;
    scanf("%f",&numero);
    getchar();
    return numero;
}

int capturaInt(char enunciado[50]){
    setlocale(LC_ALL, "Portuguese");
    printf(enunciado);
    int numero;
    scanf("%i",&numero);
    getchar();
    return numero;
}

/* Especiais */

typedef void (*Opcoes)();

void espMenu2Opcoes(char opcao1[50],Opcoes funcOpcao1,char opcao2[50],Opcoes funcOpcao2){
    setlocale(LC_ALL, "Portuguese");
    char opcao;
    do{
        system("cls");
        printf("Menu de opcoes \n------------------- \n \n");
        printf("(a)-%s , (b)-%s, (c)-Sair\n",opcao1,opcao2);
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
                break;
            default:
                printf("Opcao inv�lida \n");
                system("pause");
                break;
        }
    }while(opcao!='c');
}

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
                printf("Opcao inv�lida \n");
                system("pause");
                break;
        }
    }while(opcao!='d');
}

void espMenu4Opcoes(char opcao1[50],Opcoes funcOpcao1,char opcao2[50],Opcoes funcOpcao2,char opcao3[50],Opcoes funcOpcao3,char opcao4[50],Opcoes funcOpcao4){
    setlocale(LC_ALL, "Portuguese");
    char opcao;
    do{
        system("cls");
        printf("Menu de opcoes \n------------------- \n \n");
        printf("(a)-%s , (b)-%s, (c)-%s, (d)-%s, (e)-Sair\n",opcao1,opcao2,opcao3,opcao4);
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
                funcOpcao4();
                break;
            case('e'):
                break;
            default:
                printf("Opcao inv�lida \n");
                system("pause");
                break;
        }
    }while(opcao!='e');
}

void espMenu5Opcoes(char opcao1[50],Opcoes funcOpcao1,char opcao2[50],Opcoes funcOpcao2,char opcao3[50],Opcoes funcOpcao3,char opcao4[50],Opcoes funcOpcao4,char opcao5[50],Opcoes funcOpcao5){
    setlocale(LC_ALL, "Portuguese");
    char opcao;
    do{
        system("cls");
        printf("Menu de opcoes \n------------------- \n \n");
        printf("(a)-%s , (b)-%s, (c)-%s, (d)-%s, (e)-%s, (f)-Sair\n",opcao1,opcao2,opcao3,opcao4,opcao5);
        scanf("%c",&opcao);
        getchar();
        switch(opcao){
            case('a'):
                funcOpcao1();
                system("pause");
                break;
            case('b'):
                funcOpcao2();
                system("pause");
                break;
            case('c'):
                funcOpcao3();
                system("pause");
                break;
            case('d'):
                funcOpcao4();
                system("pause");
                break;
            case('e'):
                funcOpcao5();
                system("pause");
                break;
            case('f'):
                break;
            default:
                printf("Opcao inv�lida \n");
                system("pause");
                break;
        }
    }while(opcao!='f');
}
