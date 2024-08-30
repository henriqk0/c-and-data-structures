#include "tadlista.h"

typedef struct {
  char key[64];
  t_dado valor;  
} t_entrada;

typedef Lista *Dic;

Dic new_dic(int quant_dados);
int hashFunc(char *k);
Dic adDic(Dic d, char *k,t_dado valor);
Dic altDic(Dic d, char *k,t_dado valor);
t_dado removeDic(Dic d, char *k);
t_dado elemDic(Dic d, char *k);
int lenDic(Dic d);
Lista keysDic(Dic d);