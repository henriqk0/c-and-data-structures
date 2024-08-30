// como hash de outros tipos (problemas com o resto de divs inteiros, por
// exemplo (?))

// hash : para busca !!

#include "../../tadlista.h"

typedef struct t_entrada {
  char key[64];
  t_dado valor;
} * t_item;

typedef struct t_dic {
  Lista *vetlst; // vetor dinâmio de lista
  int tamanho;   // tamanho alocado do vetor dinâ,ico
} * Dic;

Dic new_dic(int quant_dados);
int hashFunc(char *k);
Dic adDic(Dic d, char *k, t_dado valor);
t_dado removeDic(Dic d, char *k);
t_dado elemDic(Dic d, char *k);
int lenDic(Dic d);
Lista keysDic(Dic d);