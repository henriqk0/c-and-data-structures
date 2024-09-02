#include "tadarvore.h"
#include "../pilhas-filas/tadpilha.h"

/*
void inord_print(Pilha x) {
  if (lenLista(x) == 0) {
    x = new_pilha();
  } else {
    while ()
  }
}
*/

void print_inord_rec(PONT raiz) {
  if (raiz != NULL) {
    print_inord_rec(raiz->esq);
    printf("%ld\t", (long int)raiz->chave);
    print_inord_rec(raiz->dir);
  }
}

void seetree(PONT raiz) {
  if (raiz != NULL) {
    printf("%ld", (long int)raiz->chave);
    printf("(");
    seetree(raiz->esq);
    seetree(raiz->dir);
    printf(")");
  }
}

PONT createNewnNo(t_dado ch) {
  PONT newno = (PONT)malloc((sizeof(NO)));
  newno->esq = NULL;
  newno->dir = NULL;
  newno->chave = ch;
  return newno;
}

PONT addno(PONT raiz, PONT no) {
  if (raiz == NULL)
    return (no);
  if (no->chave < raiz->chave) {
    raiz->esq = addno(raiz->esq, no);
  } else {
    raiz->dir = addno(raiz->dir, no);
  } // rem. == keys
  return (raiz);
}

PONT contem(t_dado ch, PONT raiz) {
  if (raiz == NULL)
    return NULL;
  if (raiz->chave == ch)
    return raiz;
  if (raiz->chave > ch)
    return contem(ch, raiz->esq);
  return (contem(ch, raiz->dir));
}

int numNo(PONT raiz) {
  if (!raiz)
    return 0;
  return (numNo(raiz->esq) + 1 + numNo(raiz->dir));
}

PONT initialz() { return NULL; }

int main() {
  PONT r = initialz();
  addno(r, createNewnNo((t_dado)23));

  addno(r, createNewnNo((t_dado)15));
  addno(r, createNewnNo((t_dado)12));
  addno(r, createNewnNo((t_dado)25));
  addno(r, createNewnNo((t_dado)24));
  addno(r, createNewnNo((t_dado)26));
  return 0;
}
