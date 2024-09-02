#include "../pilhas-filas/tadpilha.h"
#include "../tadlista.h"
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int TIPOCHAVE;

typedef struct aux {
  t_dado chave;
  struct aux *esq, *dir;

} NO;
typedef NO *PONT;

// search(), minimum(), maximum(), predecessor(), successor(), insert(),
// delete()

// void inord_print(Pilha x);
