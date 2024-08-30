/*
   MUDANÇAS
   1. CONSTRUÇÃO DO insereLista(..)
   2. CONSTRUÇÃO DO removeLista(..)
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef void *t_dado;

typedef struct tipo_no { 
  t_dado dado;
  struct tipo_no *anterior;
  struct tipo_no *proximo;
} *t_no;

typedef struct tipo_lista {
  t_no primeiro;
  t_no ultimo;
  int tamanho;  
} *Lista;

int len(Lista l){
  return l->tamanho; 
}

Lista appendLista(Lista l,t_dado d){
  t_no no = (t_no)malloc(sizeof(struct tipo_no));
  no->dado = d;
  no->anterior = NULL;
  no->proximo = NULL;

  if(l->tamanho == 0){
    l->primeiro = no;
    l->ultimo = no;
  }    
  else {    
    l->ultimo->proximo = no; 
    no->anterior = l->ultimo;
    l->ultimo = no;
  }  
  l->tamanho++;

  return l;
}

t_dado get_elem(Lista l, int pos){
  t_no aux;
  int cont = 0;

  if((pos >= 0) && (pos < l->tamanho) && (l->tamanho > 0)){
    aux = l->primeiro;
    for(cont=0; cont < pos; cont++){
      aux = aux->proximo;
    }    
    return aux->dado;    
  }
  else
    return NULL;  
}

Lista insereLista(Lista l, t_dado dado, int pos){
  if((pos >= 0) && (pos <= l->tamanho)){
    if((l->tamanho == 0) || (pos == l->tamanho))
      appendLista(l, dado);
    else { // lista não é vazia
      t_no novo_noh = (t_no)malloc(sizeof(struct tipo_no));
      novo_noh->anterior = NULL;
      novo_noh->proximo = NULL;
      novo_noh-> dado = dado;

      l->tamanho++;
      
      if(pos == 0){ // insere na primeira posição
        novo_noh->proximo = l->primeiro;
        l->primeiro->anterior = novo_noh;
        l->primeiro = novo_noh;        
      }
      else { // insere entre a 2a posição e a última inclusive
        t_no aux;
        int cont = 0;
        
        aux = l->primeiro;
        for(cont=0; cont < pos; cont++){
          aux = aux->proximo;
        } 

        novo_noh->anterior = aux->anterior;
        novo_noh->proximo = aux;
        aux->anterior->proximo = novo_noh;
        aux->anterior = novo_noh;       
      }      
    }    
  } 
  return l;
}  // fim insereLista

Lista new_lista(){
  Lista l = (Lista)malloc(sizeof(struct tipo_lista));
  l->primeiro = NULL;
  l->ultimo = NULL;
  l->tamanho = 0;  
  return l;
}
//=======================================================
// APLICAÇÃO NÃO ALTERA OS CONTEÚDOS ACIMA, SÓ USA
// OS NOMES DOS TIPOS E CHAMA AS FUNÇÕES
typedef char string16[16];

int main() {
  Lista lst = new_lista();
  string16 teclado[3] = {"goiaba","banana","melancia"};
  char *s;

  // for(int i=0; i < 3; i++){
  //   s = (char *)malloc(sizeof(string16));
  //   strcpy(s, teclado[i]);
  //   appendLista(lst,(t_dado)s);
  // }

  insereLista(lst, "Carambola", 0);

  for(int i=0; i < len(lst); i++){
    s = (char *)get_elem(lst, i);
    printf("%s\n",s);
  }
    
  return 0;
}