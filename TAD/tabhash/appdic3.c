#include "taddic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct user_data {
  char placa[16];
  char marca[32];
  char modelo[32];
} * t_user_data;

char *strip(char *s) {
  if (s[strlen(s) - 1] == '\n')
    s[strlen(s) - 1] = '\0';
  return s;
}

t_user_data linha2userdata(char *s) {
  t_user_data dados = (t_user_data)malloc(sizeof(struct user_data));
  char *token;

  token = strtok(s, ",");
  strcpy(dados->placa, token);

  token = strtok(NULL, ",");
  strcpy(dados->marca, token);

  token = strtok(NULL, ",");
  strcpy(dados->modelo, token);
  strip(dados->modelo);

  return dados;
}

Dic loademails(char *filename) {
  FILE *arq = fopen(filename, "rt");
  Dic dd = new_dic(500);
  char linha[256];
  t_user_data user;

  while (!feof(arq)) {
    fgets(linha, 255, arq);
    user = linha2userdata(linha);
    adDic(dd, user->placa, user);
  }
  return dd;
}

int main() {
  Dic dic_emails = loademails("bdveiculos500.txt");
  t_user_data user;

  estatisticas(dic_emails);

  return 0;
}