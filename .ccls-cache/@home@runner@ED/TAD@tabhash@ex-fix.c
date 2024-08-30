/*
CRIE UM DICIONÁRIO PARA ARMAZENAR CONTEÚDO DA BASE DE DADOS bdemail(ls.txt).
CRIE UM TIPO DE DADO PARA REPRESENTAR A LINHA DA BASE DE DADOS.
NO TIPO DE DADO, SELECIONE UM CAMPO PARA SER A CHAVE DO DICIONÁRIO.
APÓS O PREENCHIMENTO DO DICIONÁRIO, SOLICITE AO USUÁRIO UM VALOR DE EMAIL E
EXIBA O RESTANTE DOS DADOS ASSOCIADOS AO EMAIL. CONTINUE A INTERAGIR COM O
USUÁRIO ATÉ ELE FORNECER A PALAVRA FIM COMO VALOR DE EMAIL.
*/

#include "taddic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct user_data {
  char nome[64];
  int idade;
  char email[64];
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
  strcpy(dados->nome, token);

  token = strtok(NULL, ",");
  dados->idade = atoi(token);

  token = strtok(NULL, ",");
  strcpy(dados->email, token);
  strip(dados->email);

  return dados;
}

Dic loademails(char *filename) {
  FILE *arq = fopen(filename, "rt");
  Dic dd = new_dic(32);
  char linha[256];
  t_user_data user;

  while (!feof(arq)) {
    fgets(linha, 255, arq);
    user = linha2userdata(linha);
    // printf("%s, %s, %d\n\n", user->email, user->nome, user->idade);
    adDic(dd, user->email, user);
  }
  return dd;
}

int main() {
  Dic dic_emails = loademails("bdemails.txt");
  t_user_data user;
  char user_email[64];
  /*
    printf("Entre com o email: ");
    fgets(user_email,63,stdin);
    strip(user_email);
    while(strcmp(user_email,"FIM") != 0){
      user = (t_user_data)elemDic(dic_emails,user_email);
      if(user == NULL)
        puts("E-Mail não encontrado!!\n");
      else {
        printf("%s, %s, %d\n\n", user->email, user->nome, user->idade);
      }
      printf("Entre com o email: ");
      fgets(user_email,63,stdin);
      strip(user_email);
    }

    puts("Fim do processamento!!\n");
    */
  status(dic_emails);

  return 0;
}