#include <stdio.h>
#include <stdlib.h>

char palavraNova[60];

void inverteFrase(char palavra[60]){
    int i;
    int j=0;
    for(i=strlen(palavra)-1;i>-1;i--){
        palavraNova[j] = palavraNova[j]+palavra[i];
        j = j+1;
    }
    palavraNova[strlen(palavra)] = palavra[strlen(palavra)];
}

void main()
{
    char palavra[60];
    printf("Digite a palavra: ");
    fflush(stdin);
    gets(palavra);
    inverteFrase(palavra);
    if(strcmp(palavra,palavraNova)==0){
        printf("\n e palindromo");
    }else{
        printf("\n nao e palindromo");
    }
}
