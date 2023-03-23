#include <stdlib.h>
#include <stdio.h>

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int particiona(int *v, int inicio, int fim){
    int aux = inicio-1, cont = 0;
    int pivo = v[fim];
    for(int i = inicio; i <= fim; i++){
        if(v[i] <= pivo){
            aux++;
            troca(&v[i], &v[aux]);
            cont++;
        }
    }
    printf("Total de trocas: %d\n", cont);
    return aux;
}

void quick(int *v, int inicio, int fim)
{
    if(inicio < fim){
        int p = particiona(v, inicio, fim);
        quick(v, inicio, p-1);
        quick(v,p+1, fim);
    }
    
}

int main()
{
    int v[5] = {1, 7, 3, 50, 40};
    quick(v, 0, 4);
    for(int i = 0; i < 5; i++) printf("%d\t", v[i]);
}