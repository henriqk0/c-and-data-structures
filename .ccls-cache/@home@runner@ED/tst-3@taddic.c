#include "taddic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FC 0.5 // fator de carga

long int hashFunc(char *k) {
  long int sum = 0, prim = 499;
  for (int i = 0; i < strlen(k); i++) {
    sum = sum + k[i] % prim;
  }
  return sum;
}

Dic new_dic(int quant_dados) {
  int tamvet = quant_dados / FC;
  Dic d = NULL;

  Lista *vet = (Lista *)malloc(tamvet * sizeof(Lista));
  for (int i = 0; i < tamvet; i++) {
    vet[i] = NULL;
  }
  d = (Dic)malloc(sizeof(struct t_dic));
  d->vetlst = vet;
  d->tamanho = tamvet;

  return d;
}

Dic adDic(Dic d, char *k, t_dado valor) {
  t_item item = NULL;
  long int indice = hashFunc(k) % d->tamanho;

  if (d->vetlst[indice] == NULL)
    d->vetlst[indice] = new_lista();

  item = (t_item)malloc(sizeof(struct t_entrada));
  strcpy(item->key, k);
  item->valor = valor;
  appendLista(d->vetlst[indice], item);

  return d;
}

t_dado removeDic(Dic d, char *k) {
  int indice = hashFunc(k) % d->tamanho;
  t_item aux;

  if (d->vetlst[indice] == NULL)
    return NULL;
  else {
    for (int i = 0; i < lenLista(d->vetlst[indice]); i++) {
      aux = (t_item)elemLista(d->vetlst[indice], i);

      if (strcmp(aux->key, k)) {
        aux = removeLista(d->vetlst[indice], i);
        t_dado aux_value = aux->valor;
        free(aux);

        return aux_value;
      }
    }
    return NULL;
  }
}

t_dado elemDic(Dic d, char *k) {
  long int indice = hashFunc(k) % d->tamanho;
  t_item aux;

  if (d->vetlst[indice] == NULL)
    return NULL;
  else {
    for (int i = 0; i < lenLista(d->vetlst[indice]); i++) {
      aux = (t_item)elemLista(d->vetlst[indice], i);
      if (strcmp(aux->key, k) == 0)
        return aux->valor;
    }
    return NULL;
  }
}

int lenDic(Dic d) {
  int totalks = 0;
  for (int i = 0; i < d->tamanho; i++) {
    if (d->vetlst[i] != NULL) {
      totalks += lenLista(d->vetlst[i]);
    }
  }
  return totalks;
}

Lista keysDic(Dic d) {
  Lista todas_as_ks = new_lista();
  t_item aux;
  for (int i = 0; i < d->tamanho; i++) {
    if (d->vetlst[i] != NULL) {

      for (int j = 0; j < lenLista(d->vetlst[i]); j++) {
        aux = (t_item)elemLista(d->vetlst[i], j);
        appendLista(todas_as_ks, aux->key);
      }
    }
  }
  return todas_as_ks;
}

void estatisticas(Dic d) {
  int cont = 0;
  for (int i = 0; i < d->tamanho; i++) {
    if (d->vetlst[i] != NULL) {
      if (lenLista(d->vetlst[i]) > 1)
        printf("Lista %d, %d entradas\n", i, lenLista(d->vetlst[i]));
      cont++;
    }
  }
  printf("tam. do vet de dados: %d\n", d->tamanho);
  printf("ocupação do vet de dados: %.1f%%\n", cont / (1.0 * d->tamanho) * 100);
}