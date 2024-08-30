#include "../tadlista.h"
#include <stdio.h>
#include <stdlib.h>

typedef Lista Fila;

Fila new_fila();
t_dado dequeue(Fila f);
Fila enqueue(Fila f, t_dado d);
