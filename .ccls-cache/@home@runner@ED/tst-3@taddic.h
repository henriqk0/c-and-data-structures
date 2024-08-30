/*
  NÃO ALTERAR ESTE ARQUIVO
 */
#ifndef ___BSI_ED_2024_1_DIC__

#define ___BSI_ED_2024_1_DIC__

#include "tadlista.h"

typedef struct t_entrada {
  char key[64];
  t_dado valor;
} * t_item;

typedef struct t_dic {
  Lista *vetlst; // vetor dinâmio de lista
  int tamanho;   // tamanho alocado do vetor dinâmico
} * Dic;

Dic new_dic(int quant_dados);
Dic adDic(Dic d, char *k, t_dado valor);
t_dado removeDic(Dic d, char *k);
t_dado elemDic(Dic d, char *k);
int lenDic(Dic d);
Lista keysDic(Dic d);
void estatisticas(Dic d);

#endif
