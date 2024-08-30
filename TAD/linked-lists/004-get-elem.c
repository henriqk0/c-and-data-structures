/*
  MUDANÇAS
  1. IMPLEMENTAÇÃO DA BUSCA DE ELEMENTO
  2. CABEÇALHO DINÂMICO
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void *t_dado;

typedef struct tipo_no {
  t_dado dado;
  struct tipo_no *anterior;
  struct tipo_no *proximo;
} t_no;

typedef struct tipo_lista{
  t_no *primeiro;
  t_no *ultimo;
  int tamanho;
} * t_lista;

t_dado get_elem(t_lista l, int pos) {
  t_no *aux;
  int cont = 0;

  if ((pos >= 0) && (pos < l->tamanho) && (l->tamanho > 0)) {
    aux = l->primeiro;
    while (cont < pos) {
      aux = aux->proximo;
      cont++;
    }
    return aux->dado;
  } else
    return NULL;
}

t_lista new_lista() {
  t_lista l = (t_lista)malloc(sizeof(struct tipo_lista));
  l->primeiro = NULL;
  l->ultimo = NULL;
  l->tamanho = 0;
  return l;
}

t_lista append(t_lista l, t_dado d) {
  t_no *no = (t_no *)malloc(sizeof(t_no));
  no->dado = d;
  no->anterior = NULL;
  no->proximo = NULL;

  if (l->tamanho == 0) {
    l->primeiro = no;
    l->ultimo = no;
  } else {
    l->ultimo->proximo = no;
    no->anterior = l->ultimo;
    l->ultimo = no;
  }
  l->tamanho++;
  return l;
}

int len(t_lista l) { return l->tamanho; }

typedef char string10[10];

int main() {
  t_lista lst = new_lista();
  float *f;

  char *s;
  string10 teclado[3] = {"goiaba", "limao", "laranja"};

  for (int i = 0; i < 3; i++) {
    // f = (float *)malloc(sizeof(float));
    //*f = (i + 1) * 3.76;
    // lst = append(lst, f);
    s = (char *)malloc(sizeof(string10));
    strcpy(s, teclado[i]);
    append(lst, s);
  }
  for (int i = 0; i < len(lst); i++) {
    // printf("%.2f\n", *(float *)get_elem(lst, i));
    printf("%s\n", (char *)get_elem(lst, i));
  }

  return 0;
}