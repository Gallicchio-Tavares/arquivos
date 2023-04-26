/*
Usando a mesma estrutura da quest ̃ao
3, escreva um programa que conte o n ́umero
de candidatos inscritos para o concurso para
cada curso da institui ̧c ̃ao. Caso na sua proposta
de algoritmo seja necess ́ario ordenar por um
crit ́erio diferente da ordena ̧c ̃ao original (CPF),
assuma que o arquivo cabe todo em mem ́oria.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _Registro Registro;

struct _Registro {
char cpf[15];
char curso[20];
char dataNacimento[11];
char sexo;
char email[40];
char opcaoQuadro;
};

int main(){
    
}