/*
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

typedef t_data t_lista;

int main() {
  t_data *pA = (t_data *)malloc(sizeof(t_data)); // pA é a lista
  t_data *aux = pA;

  return 0;
}