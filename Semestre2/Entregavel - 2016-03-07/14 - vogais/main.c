#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"

char palavra[60],caracter,palavraNova[60];
int quantVogais = 0;

main()
{
    printf("Digite a palavra: \n");
    gets(palavra);

    printf("Digite a letra que deve ficar no lugar das vogais: ");
    scanf("%c",&caracter);
    getchar();

    int i;
    for(i=0;i<strlen(palavra);i++){
        if(eVogal(palavra[i])=='V'){
            quantVogais = quantVogais+1;
            palavraNova[i] = palavraNova[i]+caracter;
        }else{
            palavraNova[i] = palavraNova[i]+palavra[i];
        }
    }

    printf("Total de: %i vogais \n",quantVogais);
    printf("Palavra nova: ");
    puts(palavraNova);
}
