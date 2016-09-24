#include <stdio.h>
#include <math.h>

void elevar(int* n){
	*n = pow(*n,2);
}

int main (int argc, char** argv)
{
    int a = 5;
    elevar(&a);
    printf("%i",a);
    return 0;
}
