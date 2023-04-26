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

  entrada = fopen(argv[1], "r");
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