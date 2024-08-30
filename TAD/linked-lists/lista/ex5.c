#include "tadlista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strip(char *s) {
  int ultimo = strlen(s) - 1;
  if (s[ultimo] == '\n')
    s[ultimo] = '\0';
  return s;
}

void print_lista(Lista lst) {
  int *num;
  for (int i = 0; i < lenLista(lst) - 1; i++) {
    num = elemLista(lst, i);
    printf("%d, ", *num);
  }
  num = elemLista(lst, lenLista(lst) - 1);
  printf("%d\n", *num);
}

Lista loadListaNums(char *filename) {
  Lista l = new_lista();
  FILE *arq = fopen(filename, "rt");
  char linha[64];
  char *dadolst;

  while (!feof(arq)) {
    (void)fgets(linha, 64, arq);
    dadolst = (char *)malloc(64 * sizeof(char));
    strcpy(dadolst, linha);
    strip(dadolst);

    int *ptr_num = (int *)malloc(sizeof(int));
    int num = atoi(dadolst);
    *ptr_num = num;

    // *num = *num - 48;    // somente em números de 1 dígito

    appendLista(l, ptr_num);
  }
  return l;
}

int somaElems(Lista lst) {
  int *num;
  int soma_elems = 0;
  int *aux = &soma_elems;

  for (int i = 0; i < lenLista(lst); i++) {
    num = elemLista(lst, i);
    soma_elems = soma_elems + *num;
  }

  return *aux;
}

int main() {
  Lista lst = new_lista();

  lst = loadListaNums("numeros.txt");

  print_lista(lst);
  printf("%d\n", somaElems(lst));

  return 0;
}