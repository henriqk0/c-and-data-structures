/*
Leia todo o nome e guarde cada linha em uma pos de um vetor depois pegue cada
linha e guarde num arq.txt para criar uma cópia

1. CONSTRUA UM PROGAMA C QUE LEIA O CONTEÚDO DO ARQUIVO nomes.txt E ARMAZENE O
CONTEÚDO EM UM ARRAY C. DEFINA UM TAMANHO DE ARRAY QUE SEJA CAPAZ DE COMPORTAR O
CONTEÚDO DO ARQUIVO. EM SEGUIDA, DESCARREGUE O CONTEÚDO DO ARRAY EM UM NOVO
ARQUIVO CHAMADO nomescopy1.txt
*/

// @ernanifo (perfil do professor no replit)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[32];

int main(void) {
  string vet[100]; // vetor de strings (são 100 nomes, \0 seria o "índice 100")
  FILE *arq = fopen("./txt/nomes.txt", "rt");
  int i = 0;

  fgets(vet[i], 32, arq);
  vet[i][strlen(vet[i]) - 1] = '\0';

  while (!feof(arq)) {
    fgets(vet[++i], 32, arq);
    if (vet[i][strlen(vet[i]) - 1] == '\n')
      vet[i][strlen(vet[i]) - 1] = '\0';
  }

  fclose(arq);

  printf("Qtd de nomes: %d\n", i + 1);
  FILE *wrt = fopen("./txt/nomescopy1.txt", "wt");
  for (int j = 0; j <= i; j++) {
    // puts(vet[j]);       // mostra os nomes armazenados
    // fputs(vet[j], wrt); // escreve os nomes em nomescopy1.txt
    if (j < 99)
      fputs(strcat(vet[j], "\n"), wrt);
    else
      fputs(vet[j], wrt);
    printf("%3d\t %s\n", j + 1, vet[j]);
  } // ou simplesmente fizesse um fprintf

  fclose(wrt);

  return 0;
}