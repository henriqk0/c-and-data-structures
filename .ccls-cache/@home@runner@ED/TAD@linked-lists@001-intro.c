/* //MPT-ES estágios
Conceitos primordiais para aprender listas

-- EXECUTAR NO C TUTOR
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tipo_data {
  int dia;
  int mes;
  int ano;
  struct tipo_data *proximo;
} t_data;

typedef struct {
  t_data *primeiro;
  t_data *ultimo;
  int tamanho;
} t_lista;

t_data *cria_data(int d, int m, int a) {
  t_data *p = (t_data *)malloc(sizeof(t_data));
  p->dia = d;
  p->mes = m;
  p->ano = a;
  p->proximo = NULL;

  return p;
}

int len(t_lista l) {
  // int tam = 0;
  // t_data *aux;
  // if (l.tamanho == 0) {
  //   return tam;
  // }
  // aux = l.primeiro;
  // while (aux->proximo != NULL) {
  //   tam++;
  // }
  return l.tamanho;
}

t_lista append(t_lista l, t_data *d) {
  t_data *aux;
  if (l.tamanho == 0) {
    l.primeiro = d;
    l.ultimo = d;
  } else {
    // aux = l.primeiro;
    // while (aux->proximo != NULL) {
    //   aux = aux->proximo;
    // }
    // aux->proximo = d;

    l.ultimo->proximo = d;
    l.ultimo = d;
  }
  l.tamanho++;
  return l;
}

t_lista new_lista() {
  t_lista l;
  l.primeiro = NULL;
  l.ultimo = NULL;
  l.tamanho = 0;
  return l;
}

int main() {
  // t_data *pA = (t_data *)malloc(sizeof(t_data)); // pA é a lista
  // t_data *aux = pA;

  t_data *dt;
  t_lista lst = new_lista();

  // dt = cria_data(26, 6, 2024);
  // lst = append(lst, dt);
  // dt = cria_data(17, 3, 1989);
  // lst = append(lst, dt);

  for (int i = 0; i < 1000; i++) {
    lst = append(lst, cria_data(16, 6, 2024));
    lst.tamanho++;
  }

  // lst = (t_data *)malloc(sizeof(t_data));
  // lst->dia = 26;
  // lst->mes = 06;
  // lst->ano = 2024;
  // lst->proximo = NULL;

  return 0;
}