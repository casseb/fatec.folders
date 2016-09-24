#include <stdio.h>
#include <stdlib.h>
#include "bycasseb.h"

char palavra[60],palavraNova[60];

preenchePalavraNova(){
    int i;
    int j=0;
    for(i=strlen(palavra)-1;i>-1;i--){
        if(palavra[i]=='a' || palavra[i]=='A'){
            palavraNova[j] = palavraNova[j]+'*';
        }else{
            palavraNova[j] = palavraNova[j]+palavra[i];
        }
        j = j+1;
    }
    palavraNova[strlen(palavra)] = palavra[strlen(palavra)];
}

int main()
{
    printf("Digite a palavra: ");
    fflush(stdin);
    gets(palavra);
    preenchePalavraNova();
    printf("Palavra nova: ");
    puts(palavraNova);
}
