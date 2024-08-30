// PRIVADO: NÃO PODE SER ALTERADO
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

Lista new_lista();
int lenLista(Lista l);
Lista appendLista(Lista l, t_dado d);
t_dado get_elem(Lista l, int pos);
void print_lista(Lista l);
Lista insereLista(Lista l, t_dado dado, int pos);
Lista removeLista(Lista l, int pos);
