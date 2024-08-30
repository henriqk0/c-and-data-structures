/*
  MUDANÇAS
  1. LISTA DUPLAMENTE ENCADEADA.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipo_data {
  int dia;
  int mes;
  int ano;
  struct tipo_data *anterior;
  struct tipo_data *proximo;
} t_data;

t_data *cria_data(int d, int m, int a) {
  t_data *p = (t_data *)malloc(sizeof(t_data));
  p->dia = d;
  p->mes = m;
  p->ano = a;
  p->proximo = NULL;
  p->anterior = NULL;

  return p;
}

typedef struct {
  t_data *primeiro;
  t_data *ultimo;
  int tamanho;
} tlista;

int len(tlista l) { return l.tamanho; }

tlista append(tlista l, t_data *d) {
  if (l.tamanho == 0) {
    l.primeiro = d;
    l.ultimo = d;
  } else {
    l.ultimo->proximo = d;
    d->anterior = l.ultimo;
    l.ultimo = d;
  }
  l.tamanho++;
  return l;
}

tlista new_lista() {
  tlista l;
  l.primeiro = NULL;
  l.ultimo = NULL;
  l.tamanho = 0;
  return l;
}

int main() {
  t_data *dt;
  tlista lst = new_lista();

  for (int i = 0; i < 3; i++) {
    lst = append(lst, cria_data(16, 6, 2024));
  }
  return 0;
}