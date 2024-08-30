//=======================================================
// APLICAÇÃO NÃO ALTERA OS CONTEÚDOS ACIMA, SÓ USA
// OS NOMES DOS TIPOS E INVOCA AS FUNÇÕES
#include "../ESBR/tadlista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string16[16];

void print_lista(Lista lst) {
  char *s;
  for (int i = 0; i < lenLista(lst); i++) {
    s = (char *)elemLista(lst, i);
    printf("%s\n", s);
  }
}

int main() {
  Lista lst = new_lista();
  string16 teclado[4] = {"goiaba", "banana", "melancia", "jaca"};
  char *s;

  for (int i = 0; i < 4; i++) {
    s = (char *)malloc(sizeof(string16));
    strcpy(s, teclado[i]);
    appendLista(lst, (t_dado)s);
  }

  printf("Lista original!\n");
  print_lista(lst);

  printf("\nTentando remover um elemento de uma posição que não existe!!\n");
  removeLista(lst, 200);
  print_lista(lst);

  printf("\nRemovendo elemento 2, entre o primeiro e o último de uma lista com "
         "mais de 1\n");
  removeLista(lst, 2);
  print_lista(lst);

  printf("\nRemovendo primeiro de uma lista com mais de 1!\n");
  removeLista(lst, 0);
  print_lista(lst);

  printf("\nRemovendo o último de uma lista com mais de 1!\n");
  removeLista(lst, lenLista(lst) - 1);
  print_lista(lst);

  printf("\nRemovendo o único elemento da lista!\n");
  removeLista(lst, 0);
  print_lista(lst);
  puts("Lista vazia!!");

  printf("\nTentativa de remover um elemento de uma lista vazia!\n");
  removeLista(lst, 0);
  print_lista(lst);
  puts("Lista vazia!!");

  return 0;
}