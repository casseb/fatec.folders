/*
Programa sobre WiFi
1 - ler atributos
2 - calcular �rea de abrang�ncia
3 - verificar se dipositivo capta sinal*/
//inclus�o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <locale.h>
// defini��o de estrutura que virou tipo WF
typedef struct wifi
{
    float xo;
    float yo;
    float raio;
}WF;
//vari�vel eq do tipo WF
WF eq;
WF tabW[3];

// fun��o para leitura
void ler_equi()
{
    printf("\nDigite o raio de equipamento:\n");
    scanf("%f",&eq.raio);
    printf("\nDigite a posicao no eixo x:\n");
    scanf("%f",&eq.xo);
    printf("\nDigite a posicao no eixo y:\n");
    scanf("%f",&eq.yo);
}

void ler_varios()
{
    int i;
	for(i=0;i<3;i++)
	{
		printf("\nDigite o raio de equipamento:\n");
    	scanf("%f",&tabW[i].raio);
    	printf("\nDigite a posicao no eixo x:\n");
    	scanf("%f",&tabW[i].xo);
    	printf("\nDigite a posicao no eixo y:\n");
    	scanf("%f",&tabW[i].yo);
	}

}
// fun��o que calcula a �rea de abrang�ncia
float calcular_area_Wifi()
{
   return(3.14*eq.raio*eq.raio);
}
//fun��o para captar sinal
int capta_sinal(float x1, float y1)
{
    float b,c,a;
    b=eq.xo-x1;
    c=eq.yo-y1;
    a=sqrt((b*b)+(c*c));
    printf("\na=%.2f,b=%.2f,c=%.2f",a,b,c);
    if (a<=eq.raio)return 1;
    else return 0;
}

int capta_sinal3(float x1, float y1)
{
    float b[3],c[3],a[3];
    int i;
    for(i=0;i<3;i++){
        b[i]=tabW[i].xo-x1;
        c[i]=tabW[i].yo-y1;
        a[i]=sqrt((b[i]*b[i])+(c[i]*c[i]));

        if (a[i]<=tabW[i].raio)return 1;
    }
    return 0;
}
// fun��o principal com menu
int main()
{
    char op;
    float h,v;
  //  setlocale(LC_ALL,"Portuguese");
    do
    {
      printf("\n1-ler atributos\n2-area\n3-capta?\n4-sair\n5-ler tres roteadores\n6-ler tre roteadores e conferir se tem cobertura");
      op=getche();
      switch(op)
      {
          case '1':ler_equi();
                   break;
          case '2':printf("\nArea: %.2f",calcular_area_Wifi());
                   break;
          case '3':printf("\nDigite a posicao do dispositivo(x,y)\n");
                   scanf("%f,%f",&h,&v);
                   if(capta_sinal(h,v)==1) printf("\nDentro da area\n");
                   else                    printf("\nFora da area\n");
                   break;
          case '4':printf("Saindo");
                   break;
          case '5':ler_varios();
                    break;
          case '6':printf("\nDigite a posicao do dispositivo(x,y)\n");
                   scanf("%f,%f",&h,&v);
                   ler_varios();
                   if(capta_sinal3(h,v)==1) printf("\nDentro da area\n");
                   else                    printf("\nFora da area\n");
                   break;

          default: printf("\nOp invalida\n");
      }
    }while(op!='4');


    return 0;
}
