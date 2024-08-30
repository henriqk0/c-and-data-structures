#include "taddic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc reposta.c taddic.c tadlista.c -o teste.bin

char *strip(char *s) {
  if (s[strlen(s) - 1] == '\n')
    s[strlen(s) - 1] = '\0';
  return s;
}

Dic carregadi(char *nomearq) {
  FILE *arq = fopen(nomearq, "r");
  Dic dictwords = new_dic(250);
  char linha[64];
  char *token;
  char *key;
  char *value;

  while (!feof(arq)) {
    fgets(linha, 64, arq);
    key = (char *)malloc(64 * sizeof(char));
    value = (char *)malloc(64 * sizeof(char));

    token = strtok(linha, ",");
    strcpy(key, token);
    token = strtok(NULL, ",");
    strcpy(value, token);
    strip(value);

    adDic(dictwords, key, value);
  }
  fclose(arq);
  return dictwords;
}

Dic invertedi(Dic paramdi) {
  Dic inverted = new_dic(250);
  for (int i = 0; i < paramdi->tamanho; i++) {
    if (paramdi->vetlst[i] != NULL) {
      t_item aux;
      for (int j = 0; j < lenLista(paramdi->vetlst[i]); j++) {
        aux = (t_item)elemLista(paramdi->vetlst[i], j);
        // valor se torna a chave, e a chave, o valor
        adDic(inverted, aux->valor, aux->key);
      }
    }
  }

  // Mais simples:
  // Lista l = keysDic(paramdi);
  // for (int i = 0; i < lenLista(l); i++) {
  //   t_item aux = (t_item)elemDic(paramdi, (char *)elemLista(l, i));
  //   adDic(inverted, aux->valor, aux->key);
  // }

  return inverted;
}

Dic combinadi(Dic diA, Dic diB) {
  Dic dAB = new_dic(250);
  for (int i = 0; i < diA->tamanho; i++) {
    if (diA->vetlst[i] != NULL) {
      t_item auxA;
      t_item auxB;
      for (int j = 0; j < lenLista(diA->vetlst[i]); j++) {
        // key's A == key's B; tam A == tam B =>
        auxA = (t_item)elemLista(diA->vetlst[i], j);
        auxB = (t_item)elemLista(diB->vetlst[i], j);
        adDic(dAB, auxA->valor, auxB->valor);
      }
    }
  }
  return dAB;
}

Dic salvadi(Dic di, char *nomearq) {
  FILE *arq = fopen(nomearq, "w");
  for (int i = 0; i < di->tamanho; i++) {
    if (di->vetlst[i] != NULL) {
      t_item auxA;
      for (int j = 0; j < lenLista(di->vetlst[i]); j++) {
        auxA = (t_item)elemLista(di->vetlst[i], j);
        if (j < lenDic(di) - 1)
          fprintf(arq, "%s,%s\n", auxA->key, (char *)auxA->valor);
        else
          fprintf(arq, "%s,%s", auxA->key, (char *)auxA->valor);
      }
    }
  }
  fclose(arq);
  return di;
}

int main() {
  char *idiomaOrig = (char *)malloc(10 * sizeof(char));
  char *idiomaDest = (char *)malloc(10 * sizeof(char));
  char *traduzir = (char *)malloc(10 * sizeof(char));

  Dic ptEn = carregadi("di-pt-en.txt");
  Dic ptEs = carregadi("di-pt-es.txt");
  Dic ptFr = carregadi("di-pt-fr.txt");

  Dic enPt = invertedi(ptEn);
  Dic esPt = invertedi(ptEs);
  Dic frPt = invertedi(ptFr);

  Dic enFr = combinadi(ptEn, ptFr);
  Dic esFr = combinadi(ptEs, ptFr);
  Dic enEs = combinadi(ptEn, ptEs);
  Dic frEn = combinadi(ptFr, ptEn);

  Dic dm = new_dic(10);
  adDic(dm, "pt-en", (Dic)ptEn);
  adDic(dm, "pt-es", (Dic)ptEs);
  adDic(dm, "pt-fr", (Dic)ptFr);
  adDic(dm, "en-pt", (Dic)enPt);
  adDic(dm, "es-pt", (Dic)esPt);
  adDic(dm, "fr-pt", (Dic)frPt);
  adDic(dm, "en-fr", (Dic)enFr);
  adDic(dm, "es-fr", (Dic)esFr);
  adDic(dm, "fr-es", (Dic)enEs);
  adDic(dm, "fr-en", (Dic)frEn);

  char *k_dm;
  Dic aux;

  strcpy(idiomaOrig, "INICIO");
  while (strcmp(idiomaOrig, "FIM") != 0) {
    printf("=============================================\n\n");
    printf("ED TRANSLATOR VERSÃO 1.0\n");

    printf("\nTRADUZIR DO IDIOMA (pt, en, fr, es): ");
    scanf(" %9s", idiomaOrig);

    if (strcmp(idiomaOrig, "FIM") != 0) {

      printf("\nPARA O IDIOMA (pt, en, fr, es): ");
      scanf(" %9s", idiomaDest);

      printf("\nENTRE COM A PALAVRA A TRADUZIR: ");
      scanf(" %9s", traduzir);

      // Concatenando para obter a chave do dicionário master
      k_dm = (char *)malloc(10 * sizeof(char));
      strcat(k_dm, idiomaOrig);
      strcat(k_dm, "-");
      strcat(k_dm, idiomaDest);
      strip(k_dm);

      aux = elemDic(dm, k_dm);
      if (elemDic(aux, traduzir) != NULL)
        printf("\nTRADUÇÃO: %s\n", (char *)elemDic(aux, traduzir));
      else
        printf("\nPALAVRA NÃO ENCONTRADA!\n");

      printf("\n=============================================\n");
    }
  }

  return 0;
}