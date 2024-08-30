#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void *t_dado;

typedef struct tipo_no {
  t_dado dado;
  struct tipo_no *anterior;
  struct tipo_no *proximo;
} t_no;

typedef struct {
  t_no *primeiro;
  t_no *ultimo;
  int tamanho;
} t_lista;

t_dado get_elem(t_lista l, int pos) {
  t_dado aux;
  int cont = 0;
  if ((pos >= 0) && (pos < l.tamanho) && (l.tamanho > 0)) {
    aux = l.primeiro;
    while (cont <= pos) {
      aux = aux->proximo;
      cont++;
    }
  } else
    return NULL;
  return aux;
}

t_lista new_lista() {
  t_lista l;
  l.primeiro = NULL;
  l.ultimo = NULL;
  l.tamanho = 0;
  return l;
}

t_lista append(t_lista l, t_dado d) {
  t_no *no = (t_no *)malloc(sizeof(t_no));
  no->dado = d;
  no->anterior = NULL;
  no->proximo = NULL;

  if (l.tamanho == 0) {
    l.primeiro = no;
    l.ultimo = no;
  } else {
    l.ultimo->proximo = no;
    no->anterior = l.ultimo;
    l.ultimo = no;
  }
  l.tamanho++;
  return l;
}

int len(t_lista l) { return l.tamanho; }

int main() {
  t_lista lst = new_lista();

  int *p = (int *)malloc(sizeof(int));
  *p = 10;

  lst = append(lst, p);

  p = (int *)malloc(sizeof(int));
  *p = 20;
  lst = append(lst, p);

  return 0;
}