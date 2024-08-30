/*
    MUDANÇAS
    1. CONSTRUÇÃO DO insereLista(...)
    2. CONSTRUÇÃO DO removeLista(...)
*/

// passar para o replit para a aula de segunda e terminar funcao removerPython
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void *t_dado;

typedef struct tipo_no {
  t_dado dado;
  struct tipo_no *anterior;
  struct tipo_no *proximo;
} * t_no;

typedef struct tipo_lista {
  t_no primeiro;
  t_no ultimo;
  int tamanho;
} * Lista;

Lista new_lista() {
  Lista l = (Lista)malloc(sizeof(struct tipo_lista));
  l->primeiro = NULL;
  l->ultimo = NULL;
  l->tamanho = 0;
  return l;
}

t_dado get_elem(Lista l, int pos) {
  t_no aux;
  int cont = 0;

  if ((pos >= 0) && (pos < l->tamanho) && (l->tamanho > 0)) {
    aux = l->primeiro;
    while (cont < pos) {
      aux = aux->proximo;
      cont++;
    }
    return aux->dado;
  } else {
    return NULL;
  }
}

Lista appendLista(Lista l, t_dado d) {
  t_no no = (t_no)malloc(sizeof(struct tipo_no));
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

int len(Lista l) { return l->tamanho; }

Lista inserePython(Lista, int, t_dado);
t_dado removerPython(Lista, int); // como o pop em python - remove no item

typedef char string10[10];

int main() {
  Lista lst = new_lista();

  char *s;
  string10 teclado[4] = {"morango", "tomate", "pimentao", "pimenta"};

  for (int i = 0; i < 3; i++) {
    s = (char *)malloc(sizeof(string10));
    strcpy(s, teclado[i]);
    appendLista(lst, s);
  }
  inserePython(lst, 1, teclado[3]); // morango pimenta tomate pimentao
  removerPython(lst, 1);            // morango tomate pimentao
  for (int i = 0; i < 3; i++) {     // len(l)
    printf("%s\n", (char *)get_elem(lst, i));
  }
  inserePython(lst, 0, "Carambola"); // Carambola morango tomate pimentao
  return 0;
}

Lista inserePython(Lista l, int pos, t_dado d) {
  // em python: índices negativos e acima o tamanho da lista existem p/ inserir
  if (pos < 0) {
    pos = l->tamanho + pos;
    if (pos < l->tamanho)
      pos = 0;
  }
  if (l->tamanho == 0 || pos >= l->tamanho) {
    appendLista(l, d);
  } else {
    t_no no = (t_no)malloc(sizeof(t_no));
    no->dado = d;
    no->anterior = NULL;
    no->proximo = NULL;

    t_no aux = (t_no)malloc(sizeof(t_no));
    int cont = 0;

    aux = l->primeiro;
    l->tamanho++;
    if (pos == 0) {
      l->primeiro = no;
      no->proximo = aux;
      aux->anterior = no;
    } else {
      while (cont < pos) {
        aux = aux->proximo;
        cont++;
      }
      no->anterior = aux->anterior;
      no->proximo = aux;
      aux->anterior->proximo = no;
      aux->anterior = no;
    }
  }

  return l;
}

t_dado removerPython(Lista l, int pos) { // similar ao pop em listas
  if (l->tamanho == 0)
    return NULL; // lista vazia

  else {
    if (pos < 0 || pos >= l->tamanho) {
      pos = l->tamanho + pos;
      if (pos < 0 || pos >= l->tamanho)
        return NULL; // index out of range

      else {
        t_no no = (t_no)malloc(sizeof(t_no));
        t_dado bkp_dado = (t_dado)malloc(sizeof(t_dado));
        if (l->tamanho == 1) {
          no = l->primeiro;
          l->primeiro = NULL;
          l->ultimo = NULL;
        }

        else if (pos == l->tamanho - 1) {
          no = l->ultimo;
          l->ultimo = no->anterior;
          l->ultimo->proximo = NULL;
        }

        else if (pos == 0) {
          no = l->primeiro;
          l->primeiro = no->proximo;
          l->primeiro->anterior = NULL;
        }

        else {
          for (int i = 0; i < pos; i++) {
            no = no->proximo;
          }
          no->anterior->proximo = no->proximo;
          no->proximo->anterior = no->anterior;
        }

        bkp_dado = no->dado;
        l->tamanho--;
        // limpa o heap
        free(no);
        no = NULL;
        return bkp_dado;
      }
    }
  }
  return NULL;
}
