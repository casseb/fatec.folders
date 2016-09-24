#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Biblioteca ByCasseb Versão 0.12 */

/*Legenda:
imp = Retorna impressão na tela
captura = Preenche variavel com conteúdo do usuário
calc = Calcula e retorna o resultado do cálculo
str = Manipulação de strings
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

void impMatrizInt(int **numeros, int quantLinhas, int quantColunas){
    int i,j;
    for(i=0;i<quantLinhas;i++){
        printf("\n");
        printf("Linha %i = ",i);
        for(j=0;j<quantColunas;j++){
            printf("%i | ",numeros[i][j]);
        }
    }
    printf("\n");
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



char* impDiaDaSemana(int dia, int mes, int ano){
    int converteData(int dia, int mes, int ano){
        int regData,regAno, regMes, i, quantBissesto;
        quantBissesto = floor((ano-1917)/4);
        regAno = (ano-1917)*365+quantBissesto;

        regMes = 0;
        int quantDiasMes[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        for(i=1;i<mes;i++){
            regMes = regMes+quantDiasMes[i];
            if(i==2 && (ano-1916)%4==0){
                regMes = regMes+1;
            }
        }

        regData = dia+regMes+regAno;
        return regData+1;
    }

    int calculaFatorSemana(int regNumerico){
        int inicioSemana = 0;
        int fator;
        int i = 0;
        while(i<regNumerico){
            inicioSemana = i;
            i = i+7;
        }
        fator = regNumerico-inicioSemana;
        return fator;
    }

    int regNumerico,fator;
    regNumerico = converteData(dia,mes,ano);
    fator = calculaFatorSemana(regNumerico);
    char *d[] = {
        "erro",
        "domingo",
        "segunda-feira",
        "terça-feira",
        "quarta-feira",
        "quinta-feira",
        "sexta-feira",
        "sábado"
    };
    return d[1<=fator && fator<=7 ? fator : 0];
}

void impListaPalavras(char** nomes,int quantNomes){
    int i;
    printf("\n");
    for(i=0;i<quantNomes;i++){
        puts(nomes[i]);
    }
    printf("\n");
    system("pause");
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

int capturaInt(char enunciado[50]){
    setlocale(LC_ALL, "Portuguese");
    printf(enunciado);
    int numero;
    scanf("%i",&numero);
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

int** capturaMatriz(char enunciado[50],int quantLinhas,int quantColunas){
    setlocale(LC_ALL, "Portuguese");
    int i,j;
    int **numeros = (int *)malloc(quantLinhas * sizeof(int));
    for (i=0;i<quantLinhas;i++ ){
        *(numeros + i) = (char*)malloc(quantLinhas*sizeof(char));
    }
    for(i=0;i<quantLinhas;i++){
        printf(enunciado);
        printf("%i\n",i+1);
        for(j=0;j<quantColunas;j++){
            scanf("%i",&numeros[i][j]);
            getchar();
        }
    }
    return numeros;
}

char* capturaPalavra(char enunciado[50]){
    setlocale(LC_ALL, "Portuguese");
    printf(enunciado);
    char *palavra;
    fflush(stdin);
    gets(palavra);
    return palavra;
}

char** capturaVetorPalavras(char enunciado[50],int quantPalavras){
    setlocale(LC_ALL, "Portuguese");
    printf(enunciado);
    char** nomes = (char **)malloc(quantPalavras * sizeof(int));
    int i;
    for (i=0;i<quantPalavras;i++ ){
        *(nomes + i) = (char*)malloc(50*sizeof(char));
    }
    for(i=0;i<quantPalavras;i++){
        fflush(stdin);
        gets(nomes[i]);
    }
    return nomes;
}


/* Calculos */

int distanciaUniDimencional(int pontoA, int pontoB){
    if(pontoA>pontoB){
        return pontoA-pontoB;
    }else{
        return pontoB-pontoA;
    }
}

int distanciaBiDirecional(int pontoA[2], int pontoB[2]){
    int resultado = 0;
    int i;
    for(i=0;i<2;i++){
        if(pontoA[i]>pontoB[i]){
        resultado = resultado + pontoA[i]-pontoB[i];
        }else{
            resultado = resultado + pontoB[i]-pontoA[i];
        }
    }
    return resultado;
}

int distanciaTriDirecional(int pontoA[3], int pontoB[3]){
    int resultado = 0;
    int i;
    for(i=0;i<3;i++){
        if(pontoA[i]>pontoB[i]){
        resultado = resultado + pontoA[i]-pontoB[i];
        }else{
            resultado = resultado + pontoB[i]-pontoA[i];
        }
    }
    return resultado;
}

void adicao(){
    int n1,n2;
    n1 = 0;
    n2 = 0;
    n1 = capturaInt("Digite o primeiro número: ");
    n2 = capturaInt("Digite o segundo número: ");
    printf("O resultado de %i + %i = %i\n",n1,n2,n1+n2);
    system("pause");
}

void subtracao(){
    int n1,n2;
    n1 = 0;
    n2 = 0;
    n1 = capturaInt("Digite o primeiro número: ");
    n2 = capturaInt("Digite o segundo número: ");
    printf("O resultado de %i - %i = %i\n",n1,n2,n1-n2);
    system("pause");
}

void multiplicacao(){
    int n1,n2;
    n1 = 0;
    n2 = 0;
    n1 = capturaInt("Digite o primeiro número: ");
    n2 = capturaInt("Digite o segundo número: ");
    printf("O resultado de %i * %i = %i\n",n1,n2,n1*n2);
    system("pause");
}

void somaMatrizes(int** matrizOriginal1,int** matrizOriginal2,int quantLinhas,int quantColunas){
    int i,j;
    int** somaMatriz;
    somaMatriz = (int *)malloc(quantLinhas * sizeof(int));
    for (i=0;i<quantLinhas;i++ ){
        *(somaMatriz + i) = (char*)malloc(quantLinhas*sizeof(char));
    }
    for(i=0;i<quantLinhas;i++){
        for(j=0;j<quantColunas;j++){
            somaMatriz[i][j] = matrizOriginal1[i][j]+matrizOriginal2[i][j];
        }
    }
    impMatrizInt(somaMatriz,quantLinhas,quantColunas);
}

void subtraiMatrizes(int** matrizOriginal1,int** matrizOriginal2,int quantLinhas,int quantColunas){
    int i,j;
    int** diferencaMatriz;
    diferencaMatriz = (int *)malloc(quantLinhas * sizeof(int));
    for (i=0;i<quantLinhas;i++ ){
        *(diferencaMatriz + i) = (char*)malloc(quantLinhas*sizeof(char));
    }
    for(i=0;i<quantLinhas;i++){
        for(j=0;j<quantColunas;j++){
            diferencaMatriz[i][j] = matrizOriginal1[i][j]-matrizOriginal2[i][j];
        }
    }
    impMatrizInt(diferencaMatriz,quantLinhas,quantColunas);
}

/* Manipulação de strings */

char** ordemAlfabetica(char** nomes,int quantNomes){
    int i,j;
    char aux[30];
    for(i=0;i<quantNomes;i++){
        for(j=0;j<quantNomes;j++){
            if(strcmp(nomes[i],nomes[j])==-1){
                strcpy(aux,nomes[j]);
                strcpy(nomes[j],nomes[i]);
                strcpy(nomes[i],aux);
            }
        }
    }
    return nomes;
}

char** maiuscula(char** nomes,int quantNomes){
    int i,j;
    char **nomesMaiusculo = (char **)malloc(quantNomes * sizeof(char));
    for (i=0;i<quantNomes;i++ ){
        *(nomesMaiusculo + i) = (char*)malloc(30*sizeof(char));
    }
    for(i=0;i<quantNomes;i++){
        for(j=0;j<=strlen(nomes[i]);j++){
            nomesMaiusculo[i][j] = toupper(nomes[i][j]);
        }
    }
    return nomesMaiusculo;
}

char eVogal(char letra){
    int i;
    char vogais[5] = "aeiou";
    for(i=0;i<5;i++){
        if(letra==vogais[i]){
            return 'V';
        }
    }
    return 'F';
}

void strupr(char *palavra){
    while(*palavra != '\0')
    {
        *palavra = toupper(*palavra);
        palavra++;
    }
}

char* strcat(char *palavra,char *palavra2){
    int quantPalavra = strlen(palavra);
    int quantPalavra2 = strlen(palavra2);
    char *temp;
    temp = (char*)malloc((quantPalavra+quantPalavra2+1)*sizeof(char));

    int i = 0,posicao = 0;
    while(i<quantPalavra){
        *temp = *palavra;
        palavra++;
        temp++;
        i++;
        posicao++;
    }
    i = 0;
    while(i<=quantPalavra2){
        *temp = *palavra2;
        palavra2++;
        temp++;
        i++;
        posicao++;
    }
    while(posicao>0){
        temp--;
        posicao--;
    }
    return temp;
}

int strpos(char* palavra, char letra){
    int i=0;
    while(*palavra != '\0'){
        if(*palavra==letra){
            return i;
        }
        i++;
        palavra++;
    }
    return -1;
}

char* strdel(char* palavra, int indice){
    if(indice<strlen(palavra)){
        char *temp;
        temp = (char*)malloc((strlen(palavra)+1)*sizeof(char));
        int i=0,posicao=0;
        while(*palavra != '\0'){
            if(i!=indice){
                *temp = *palavra;
            }else{
                palavra++;
                *temp = *palavra;
            }
            palavra++;
            i++;
            posicao++;
            temp++;
        }
        while(posicao>0){
            temp--;
            posicao--;
        }
        return temp;
    }else{
        return palavra;
    }

}

char* strins(char letra,char* palavra, int indice){
        char *temp;
        int tamPalavra = strlen(palavra);
        temp = (char*)malloc((tamPalavra+1)*sizeof(char));
        int i=0,posicao=0;
        while(*palavra != '\0'){
            if(i!=indice){
                *temp = *palavra;
            }else{
                *temp = letra;
                temp++;
                *temp = *palavra;
            }
            palavra++;
            i++;
            posicao++;
            temp++;
        }
        if(indice>tamPalavra){
            printf("estou aqui\n");
            printf("%i\n",strlen(palavra));
            *temp = letra;
            temp++;
            *temp = *palavra;
        }
        while(posicao>-1){
            temp--;
            posicao--;
        }
        return temp;
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
                printf("Opcao inválida \n");
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
                printf("Opcao inválida \n");
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
                printf("Opcao inválida \n");
                system("pause");
                break;
        }
    }while(opcao!='e');
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

void regraOrdenaNaves(int *planeta,int **nave){
    int distancias[5][2],i,j,aux[2];
    int maior = -1;
    for(i=0;i<5;i++){
        distancias[i][0] = distanciaTriDirecional(planeta,nave[i]);
        distancias[i][1] = i;
    }
    for(i=0;i<5;i++){
        maior = -1;
        for (j=i;j<5;j++){
            if(maior<distancias[j][0]){
                maior = distancias[j][0];
                aux[0] = distancias[i][0];
                aux[1] = distancias[i][1];
                distancias[i][0] = distancias[j][0];
                distancias[i][1] = distancias[j][1];
                distancias[j][0] = aux[0];
                distancias[j][1] = aux[1];
            }
        }
    }
    printf("Sequencia das naves: ");
    for(i=0;i<5;i++){
        printf("%i,",distancias[i][1]);
    }
    system("pause");
}

