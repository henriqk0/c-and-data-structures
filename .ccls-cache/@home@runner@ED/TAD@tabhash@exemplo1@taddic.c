#include "./taddic.h"
// #include "../tadlista.h"
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

// fator de carga:
#define FC 0.5

Dic new_dic(int quant_dados) {
  Dic d = NULL;
  Lista *vet;
  int tamvet = quant_dados / FC; // quantidade de elementos

  vet = (Lista *)malloc(tamvet * sizeof(Lista));
  for (int i = 0; i < tamvet; i++) {
    vet[i] = NULL;
  }

  d = malloc(sizeof(struct t_dic));
  d->tamanho = tamvet;
  d->vetlst = vet;

  return d;
}

int hashFunc(char *k) {
  int soma = 0;

  for (int i = 0; i < strlen(k); i++)
    soma = soma + k[i];

  return soma;
}

/* Por enquanto, só cria um novo item, mas não altera*/
Dic adDic(Dic d, char *k, t_dado valor) {
  int indice = hashFunc(k) % d->tamanho;

  if (d->vetlst[indice] == NULL) {
    d->vetlst[indice] = new_lista();
  }

  t_item item = (t_item)malloc(sizeof(struct t_entrada));
  strcpy(item->key, k);
  item->valor = valor;

  printf("%s\n", (char *)valor); // ok

  appendLista(d->vetlst[indice], item);
  return d;
}

int lenDic(Dic d) {
  int totalks = 0;
  for (int i = 0; i < d->tamanho; i++) {
    if (d->vetlst[i] != NULL)
      totalks += lenLista(d->vetlst[i]);
  }
  return totalks;
}

t_dado elemDic(Dic d, char *k) {
  int index = hashFunc(k) % d->tamanho;
  if (d->vetlst[index] == NULL)
    return NULL;
  else {
    Lista lst = d->vetlst[index];
    for (int i = 0; i < lenLista(lst); i++) {
      t_item aux = (t_item)elemLista(lst, i);
      if (strcmp(aux->key, k) == 0)
        return aux->valor;
    } // for
    return NULL;
  } // else
} // fim de elemDic

Lista keysDic(Dic d) {
  Lista todas_as_ks = new_lista();
  t_item aux;
  for (int i = 0; i < d->tamanho; i++) {
    if (d->vetlst[i] != NULL) {
      for (int j = 0; j < lenLista(d->vetlst[i]); j++) {
        aux = (t_item)elemLista(d->vetlst[i], j);
        appendLista(todas_as_ks, aux->key);
      } // for j
    }   // if
  }     // for i
  return todas_as_ks;
} // fim keysDic

t_dado removeDic(Dic d, char *k) {
  int index = hashFunc(k) % d->tamanho;
  t_item aux;
  if (d->vetlst[index] == NULL)
    return NULL;
  else {
    Lista lst = d->vetlst[index];
    for (int i = 0; i < lenLista(lst); i++) {
      aux = (t_item)elemLista(lst, i);
      if (strcmp(aux->key, k)) {
        aux = removeLista(lst, i);
        return aux->valor;
      }
    } // for
    return NULL;
  }
}