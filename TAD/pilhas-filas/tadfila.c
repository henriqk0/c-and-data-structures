#include "tadfila.h"

// Usando o início da lista como inicio da fila (Queue)
// FIFO(first in - first out))

Fila new_fila() { return new_lista(); }

// Desenfila
t_dado dequeue(Fila f) {
  t_dado d = removeLista(f, 0);
  return d;
}

// Enfileira
Fila enqueue(Fila f, t_dado d) { return appendLista(f, d); }

// Destoi fila (libera memória)