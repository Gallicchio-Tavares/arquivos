/*
Alguns algoritmos de compactaçao de
arquivos precisam saber a quantidade de
ocorrˆencia de cada byte no arquivo. Fazendo
a leitura byte a byte, elabore um programa que
conte a ocorrˆencia de cada caractere. Crie um
contador para cada byte, sabendo-se que este
tipo varia entre 0 e 255.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 256

int main(int argc, char **argv) {
  FILE *entrada;
  int freq[MAX] = {0};
  int c;
  if (argc != 2) {
    fprintf(stderr, "Erro na chamada do comando.\n");
    fprintf(stderr, "Uso: %s [ARQUIVO ORIGEM].\n", argv[0]);
    return 1;
  }

  entrada = fopen(argv[1], "rb");
  if (entrada == NULL) {
    fprintf(stderr, "Erro ao abrir o arquivo %s.\n", argv[1]);
    return 1;
  }
  while ((c = fgetc(entrada)) != EOF) {
    freq[c]++;
  }

  fclose(entrada);

  for (int i = 0; i < MAX; i++) {
    if (freq[i] > 0) {
      printf("O caractere '%c' aparece %d vezes\n", i, freq[i]);
    }
  }

  return 0;
}