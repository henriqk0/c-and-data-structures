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

Lista insereOrdenado(Lista l, char *s) {
  if (lenLista(l) == 0) {
    appendLista(l, s);
    return l;
  } else {
    char *aux;
    for (int i = 0; i < lenLista(l); i++) {
      aux = (char *)elemLista(l, i);
      if ((strcmp(aux, s) > 1) || (strcmp(aux, s) == 0)) {
        insereLista(l, s, i);
        return l;
      }
    }
    appendLista(l, s);
  }
  return l;
}

Lista loadListaOrdenado(char *filename) {
  Lista l = new_lista();
  FILE *arq = fopen(filename, "rt");
  char linha[64];
  char *dadolst;

  while (!feof(arq)) {
    (void)fgets(linha, 64, arq);
    dadolst = (char *)malloc(64 * sizeof(char));
    strcpy(dadolst, linha);
    strip(dadolst);
    insereOrdenado(l, dadolst);
  }
  return l;
}

void print_lista(Lista lst) {
  for (int i = 0; i < lenLista(lst) - 1; i++) {
    printf("%s, ", (char *)elemLista(lst, i));
  }
  printf("%s", (char *)elemLista(lst, lenLista(lst) - 1));
}

Lista substituiLista(Lista l, char *s, char *sub) {
  char *aux;
  for (int i = 0; i < lenLista(l); i++) {
    aux = (char *)elemLista(l, i);
    if (strcmp(s, aux) == 0) {
      removeLista(l, i);
      insereLista(l, sub, i);
    }
  }

  return l;
}

int main() {
  Lista lst = new_lista();
  lst = loadListaOrdenado("dados2clonagem.txt");
  print_lista(lst);
  printf("\n");

  substituiLista(lst, "JABUTICABA", "PERA");
  print_lista(lst);
  printf("\n");

  return 0;
}