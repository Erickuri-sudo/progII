#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;

    scanf("%d", &n);
    int id;
    int contador = 0;

    int livros[n];

    for(int i = 0;i<n;i++){
        scanf("%d", &livros[i]);
    }

    for(int i=0;i<n;i++){

        id = livros[i];

        for(int j = 0;j<n;j++){
            if(id == livros[j]){
                contador++;
            }
        }

        if(contador == 1){
            printf("%d ", livros[i]);
        }
        contador = 0;
    }
    return 0;
}
