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
  for (int i = 0; i < lenLista(lst) - 1; i++) {
    printf("%s, ", (char *)elemLista(lst, i));
  }
  printf("%s\n", (char *)elemLista(lst, lenLista(lst) - 1));
}

/*
  clonagem:
    rasa - shallow (mesmo dado) la = ['a'], lb = la (se alterar la, altera lb)
    profunda - deep (outro dado, mas de igual valor) la = ['a'], lb = la[:]
*/
Lista clonaLista(Lista lst) {
  Lista lst_copy = new_lista();

  char *s;
  for (int i = 0; i < lst->tamanho; i++) {
    s = (char *)elemLista(lst, i);
    appendLista(lst_copy, s);
  }

  return lst_copy;
}

Lista loadLista(char *filename) {
  Lista l = new_lista();
  FILE *arq = fopen(filename, "rt");
  char linha[64];
  char *dadolst;

  while (!feof(arq)) {
    (void)fgets(linha, 64, arq);
    dadolst = (char *)malloc(64 * sizeof(char));
    strcpy(dadolst, linha);
    strip(dadolst);
    appendLista(l, dadolst);
  }
  return l;
}


int main() {
  Lista lst = new_lista();

  lst = loadLista("dados2clonagem.txt");

  Lista lst2 = clonaLista(lst);

  print_lista(lst);
  print_lista(lst2);

  return 0;
}