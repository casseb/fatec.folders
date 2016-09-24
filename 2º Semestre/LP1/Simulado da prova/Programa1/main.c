#include <stdio.h>
#include <stdlib.h>

void aleatorios()
{
    int n,i,j,k,g;
    int sort[10];
    for(i=0;i<10;i++) sort[i]=10;
    k=0;
    for(i=0;i<10;i++)
    {
        g=0;
        while (g==0)
        {
            n =(rand()%10);
            for(j=0;j<10;j++)
            {
                if (sort[j]==n)k=1;
            }
            if (k==0)
            {
                sort[i]=n;
                printf("%d",n);
                printf("\n");
                g=1;
            }
            else k=0;
        }
    }
}


main()
{
    srand ((unsigned) time(NULL));
    char resposta = 'n';
    do{
        aleatorios();
        system("pause");
        printf("Deseja executar novamente? (s)sim ou (n)nao: ");
        scanf("%c",&resposta);
        getchar();
    }
    while(resposta=='s');

}

