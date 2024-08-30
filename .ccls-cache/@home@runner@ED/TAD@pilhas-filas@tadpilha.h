#include "../tadlista.h"
#include <stdio.h>
#include <stdlib.h>

typedef Lista Pilha;

Pilha new_pilha();
t_dado pop(Pilha p);
Pilha push(Pilha p, t_dado d);
