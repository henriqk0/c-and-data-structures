#include "tadpilha.h"

// Usando o fim da lista como topo da pilha (Stack)

Pilha new_pilha() { return new_lista(); }

// Desempilha
t_dado pop(Pilha p) {
  t_dado d = (t_dado)elemLista(p, lenLista(p) - 1);
  return d;
}

// Empilha
Pilha push(Pilha p, t_dado d) { return appendLista(p, d); }

// Destoi pilha (libera memória)