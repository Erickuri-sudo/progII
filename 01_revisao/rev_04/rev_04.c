#include <stdio.h>

int main(int argc, char const *argv[])
{
    int numeroDecimal = 0;
    int i = 1;
    int aux;
    int numeroOctal = 0;

    scanf("%d", &numeroDecimal);

    while(numeroDecimal!=0){

        aux = numeroDecimal%8;

        numeroDecimal = numeroDecimal/8;

        numeroOctal += aux*i;

        i = i*10;

    }

    printf("%d", numeroOctal);

    return 0;
}
