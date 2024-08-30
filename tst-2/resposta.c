#include "tadlista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char cep[16];
  char num_casa[5];
  char familia[30];
} t_endereco1;

typedef struct {
  char cep[16];
  Lista enderecos;
} t_endereco2;

char *strip_str(char *s) {
  int ultimo = strlen(s) - 1;
  if (s[ultimo] == '\n')
    s[ultimo] = '\0';
  return s;
}

t_endereco1 *linha_para_endr(char *linha) {
  t_endereco1 *p = (t_endereco1 *)malloc(sizeof(t_endereco1));
  const char s[2] = ",";
  char *token;

  token = strtok(linha, s);
  strcpy(p->cep, token);

  token = strtok(NULL, s);
  strcpy(p->num_casa, token);

  token = strtok(NULL, s);
  strcpy(p->familia, token);

  return p;
}

Lista loadbdceps(char *nomearq) {
  Lista l = new_lista();
  FILE *arq = fopen(nomearq, "rt");
  char linha[64];
  t_endereco1 *ptr_endr;

  while (!feof(arq)) {
    (void)fgets(linha, 64, arq);
    if (strlen(strip_str(linha)) > 10) {
      ptr_endr = linha_para_endr(strip_str(linha));
      appendLista(l, ptr_endr);
    }
  }
  fclose(arq);

  return l;
}

int in(Lista l, char *s) {
  for (int i = 0; i < lenLista(l); i++) {
    char *aux = elemLista(l, i);
    if (strcmp(aux, s) == 0)
      return 1;
  }
  return 0;
} // deveria retornar a lista de ceps correspondente (ernani)

Lista converte(Lista lst1) {
  Lista l = new_lista();
  t_endereco1 *ptr_endr1;
  t_endereco2 *ptr_endr2;
  Lista endr2_ja_presentes = new_lista();

  for (int i = 0; i < lenLista(lst1); i++) {
    ptr_endr1 = (t_endereco1 *)elemLista(lst1, i);

    if (!in(endr2_ja_presentes, ptr_endr1->cep)) {
      appendLista(endr2_ja_presentes, ptr_endr1->cep);

      ptr_endr2 = (t_endereco2 *)malloc(sizeof(t_endereco2));
      strcpy(ptr_endr2->cep, ptr_endr1->cep);
      ptr_endr2->enderecos = new_lista();

      for (int j = 0; j < lenLista(lst1); j++) {
        ptr_endr1 = (t_endereco1 *)elemLista(lst1, j);
        if (strcmp(ptr_endr1->cep, ptr_endr2->cep) == 0) {
          appendLista(ptr_endr2->enderecos, ptr_endr1);
        }
      }
      appendLista(l, ptr_endr2);
    }
  }

  return l;
}

void print_enderecos_2(Lista lst) {
  t_endereco2 *ptr;

  for (int i = 0; i < lenLista(lst); i++) {
    ptr = (t_endereco2 *)elemLista(lst, i);
    printf("%s\n", ptr->cep);
    for (int j = 0; j < lenLista(ptr->enderecos); j++) {
      t_endereco1 *aux = (t_endereco1 *)elemLista(ptr->enderecos, j);
      printf("%s,%s,%s\n", aux->cep, aux->num_casa, aux->familia);
    }
    printf("\n");
  }
}

int main() {
  Lista lst = new_lista();

  lst = loadbdceps("bdceps.txt");

  Lista endrs2 = converte(lst);

  print_enderecos_2(endrs2);

  return 0;
}