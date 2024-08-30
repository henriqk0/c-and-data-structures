#include "taddic.h"
//#include "../tadlista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FC 0.5 // fator de carga

long int hashFunc2(char *k) {
  long int sum = 0, mul = 1;
  for (int i = 0; i < strlen(k); i++) {
    mul = (i % 4 == 0) ? 1 : mul * 256;
    sum = sum + k[i] * mul;
  }
  return sum;
}

Dic new_dic(int quant_dados) {
  Dic d = NULL;
  Lista *vet;
  int tamvet = quant_dados / FC; // quantidade de elementos

  vet = (Lista *)malloc(tamvet * sizeof(Lista));
  for (int i = 0; i < tamvet; i++)
    vet[i] = NULL;

  d = malloc(sizeof(struct t_dic));
  d->tamanho = tamvet;
  d->vetlst = vet;

  return d;
}

t_item procura_item(Lista l, char *chave) {
  t_item item = NULL;
  for (int i = 0; i < lenLista(l); i++) {
    item = (t_item)elemLista(l, i);
    if (strcmp(item->key, chave) == 0)
      return item;
  } // for
  return NULL;
}

/* Por enquanto, só cria um novo ite, não altera */
Dic adDic(Dic d, char *k, t_dado valor) {
  t_item item = NULL;
  long int indice = hashFunc2(k) % d->tamanho;

  if (d->vetlst[indice] == NULL)
    d->vetlst[indice] = new_lista();

  item = procura_item(d->vetlst[indice], k);

  if (item != NULL) // Altera um item já existente
    item->valor = valor;
  else {
    item = (t_item)malloc(sizeof(struct t_entrada));
    strcpy(item->key, k);
    item->valor = valor;
    appendLista(d->vetlst[indice], item);
  }

  return d;
}

int lenDic(Dic d) {
  int totalks = 0;
  for (int i = 0; i < d->tamanho; i++) {
    if (d->vetlst[i] != NULL)
      totalks = totalks + lenLista(d->vetlst[i]);
  }
  return totalks;
}

t_dado elemDic(Dic d, char *k) {
  long int indice = hashFunc2(k) % d->tamanho;
  t_item aux;

  if (d->vetlst[indice] == NULL)
    return NULL;
  else {
    Lista lst = d->vetlst[indice];
    for (int i = 0; i < lenLista(lst); i++) {
      aux = (t_item)elemLista(lst, i);
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
  int indice = hashFunc2(k) % d->tamanho;
  t_item aux;
  if (d->vetlst[indice] == NULL)
    return NULL;
  else {
    Lista lst = d->vetlst[indice];
    for (int i = 0; i < lenLista(lst); i++) {
      aux = (t_item)elemLista(lst, i);
      if (strcmp(aux->key, k)) {
        aux = removeLista(lst, i);
        t_dado valor_aux = aux->valor;
        free(aux); // resolvendo vazamento de memória
        return valor_aux;
      }
    } // for
    return NULL;
  }
}

void status(Dic d) {
  int cont = 0;
  for (int i = 0; i < d->tamanho; i++) {
    if (d->vetlst[i] != NULL) {
      printf("índice: %d, tam: %d\n", i, lenLista(d->vetlst[i]));
      cont++;
    }
  }
  printf("%.1f%% de ocupação\n", (float)cont / d->tamanho);
  printf("\n");
}

void estatisticas(Dic d) {
  int cont = 0;
  for (int i = 0; i < d->tamanho; i++) {
    if (d->vetlst[i] != NULL) {
      printf("Lista %d, %d entradas\n", i, lenLista(d->vetlst[i]));
      cont++;
    }
  }
  printf("Taxa de ocupação do vetor de dados:\n");
  printf("Tamanho do vetor de dados: %d\n", d->tamanho);
  printf("ocupação do vetor de dados: %.1f%%\n",
         (cont / (1.0 * d->tamanho) * 100));
  printf("\n");
}
