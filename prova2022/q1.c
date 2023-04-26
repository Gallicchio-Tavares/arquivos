#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Nos arquivos texto no sistemas operacionais tipo UNIX, a quebra de linha e 
representada pelo caractere \n. Ja nos sistemas originados a partir do DOS,
a quebra de linha  ́e representada pelos caracteres \r e \n (nessa ordem e
um seguido do outro). Faça um programa que, dado um arquivo texto com 
quebra de linhas no formato UNIX converta-o para o formato DOS.
*/

int main(int argc, char**argv){
    FILE *f; // arquivo onde eu vou trocar os negocios
    char n = '\n';
    
    if(argc != 2)
	{
		fprintf(stderr, "USO: %s [arquivo]", argv[0]);
		return 1;
	}

    f = fopen(argv[1], "rb");

    int c;

    while ((c = fgetc(f)) != EOF) {
        if (c == n) {
            fputc('\r', f);
            printf("Trocado com sucesso!\n");
        }
    }
}