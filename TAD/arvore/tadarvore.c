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

void print_inord_rec_int(PONT raiz) { /* traveling in depth */
  if (raiz != NULL) {
    print_inord_rec_int(raiz->esq);
    printf("%d\t", *(int *)raiz->chave);
    print_inord_rec_int(raiz->dir);
  }
}

void seetree_int(PONT raiz) { /* traveling in width */
  if (raiz != NULL) {
    printf("%d", *(int *)raiz->chave);
    printf("(");
    seetree_int(raiz->esq);
    seetree_int(raiz->dir);
    printf(")");
  }
}

PONT createNewnNo(t_dado ch) {
  PONT newno = (PONT)malloc(sizeof(NO));
  newno->esq = NULL;
  newno->dir = NULL;
  newno->chave = ch;
  return newno;
}

PONT addno(PONT raiz, PONT no, int (*compar)(t_dado, t_dado)) {
  if (raiz == NULL)
    return no;

  if (compar(no->chave, raiz->chave) < 0) {
    raiz->esq = addno(raiz->esq, no, compar);
  } else {
    raiz->dir = addno(raiz->dir, no, compar);
  }
  return raiz;
}

PONT contem(t_dado ch, PONT raiz, int (*compar)(t_dado, t_dado)) {
  if (raiz == NULL)
    return NULL;

  if (compar(ch, raiz->chave) == 0)
    return raiz;
  else if (compar(ch, raiz->chave) < 0)
    return contem(ch, raiz->esq, compar);
  else
    return contem(ch, raiz->dir, compar);
}

int numNo(PONT raiz) {
  if (!raiz)
    return 0;
  return (numNo(raiz->esq) + 1 + numNo(raiz->dir));
}

int compar_int(t_dado a, t_dado b) {
  return (*(int*)a - *(int*)b);
}

PONT initialz() { return NULL; }

int main() {
  PONT r = initialz();

  int val1 = 23, val2 = 15, val3 = 12, val4 = 25, val5 = 24, val6 = 26;

  r = addno(r, createNewnNo(&val1), compar_int);
  r = addno(r, createNewnNo(&val2), compar_int);
  r = addno(r, createNewnNo(&val3), compar_int);
  r = addno(r, createNewnNo(&val4), compar_int);
  r = addno(r, createNewnNo(&val5), compar_int);
  r = addno(r, createNewnNo(&val6), compar_int);

  print_inord_rec_int(r);
  printf("\n");
  seetree_int(r);
  printf("\n");

  return 0;
}
