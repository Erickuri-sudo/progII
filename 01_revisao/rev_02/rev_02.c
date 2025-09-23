#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    int numero = 1;
    scanf("%d", &n);

    for(int i = 0; i<n;i++)
    {
        for(int j = 0;j<=i;j++)
        {
            printf("%d ",numero);
            numero++;
        }
        printf("\n");
    }
    return 0;
}
