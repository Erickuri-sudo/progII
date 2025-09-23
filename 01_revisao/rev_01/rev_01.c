#include <stdio.h>

int main(int argc, char const *argv[])
{
    float cx,cy,r1;
    float dx,dy,r2;
    
    scanf("%f %f %f", &cx,&cy,&r1);
    scanf("%f %f %f", &dx,&dy,&r2);

    float somaDosRaios = r1+r2;

    float quadradoDasDistancias = (dx - cx)*(dx - cx) + (dy - cy)*(dy - cy);

    somaDosRaios = somaDosRaios*somaDosRaios;

    if(somaDosRaios < quadradoDasDistancias){
        printf("ERROU\n");
    }
    else
    printf("ACERTOU\n");

    return 0;
}
