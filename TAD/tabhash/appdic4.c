/*
1. CRIE UM DICIONÁRIO PARA ARMAZENAR O CONTEÚDO DA BASE DE DADOS bdemails.txt.
CRIE UM TIPO DE DADO PARA REPRESENTAR A LINHA DA BASE DE DADOS.
NO TIPO DE DADO, SELECIONE UM CAMPO PARA SER A CHAVE DO DICIONÁIRO.
APÓS O PREENCHIMENTO DO DICIONÁRIO, SOCILTE AO USUÁRIO UM VALOR DE EMAIL E EXIBA
O RESTANTE DOS DADOS ASSOCIADOS AO EMAIL. CONTINUE A INTERAGIR COM O USUÁRIO ATÉ
ELE FORNECER A PALAVRA "FIM" COMO VALOR PARA EMAIL.

2. CONSTRUA UMA APLICAÇÃO TADDIC QUE REMOVA OS ACENTOS DE UMA STRING DE TEXTO.
ANALISE O PROBLEMA E USE A INTERFACE DO DICIONÁRIO PARA CONSTRUIR O SEU
PROGRAMA.
*/

#include "taddic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc appdic4.c taddic.c ../tadlista.c "nomedobin".bin

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

Dic loadacentos(char *filename) {
  FILE *arq = fopen(filename, "rt");
  Dic dd = new_dic(6);
  char linha[64];
  char *chave;
  char *valor;
  char *token;

  while (!feof(arq)) {
    fgets(linha, 64, arq);
    chave = (char *)malloc(3 * sizeof(char));
    valor = (char *)malloc(3 * sizeof(char));
    token = strtok(linha, ",");
    strcpy(chave, token);

    token = strtok(NULL, ",");
    strcpy(valor, token);
    adDic(dd, chave, valor);
  }
  return dd;
}

void removeAcentos(char *txt, Dic ddd) {
  int tam = strlen(txt);
  for (int i = 0; i < tam; i++) {
  }
}

int main() {
  // Dic dic_emails = loademails("bdemails.txt");
  // t_user_data user;
  // char user_email[64];

  // printf("Entre com o email: ");
  // fgets(user_email, 63, stdin);
  // strip(user_email);
  // while (strcmp(user_email, "FIM") != 0) {
  //   user = (t_user_data)elemDic(dic_emails, user_email);
  //   if (user == NULL)
  //     puts("E-Mail não encontrado!!\n");
  //   else {
  //     printf("%s, %s, %d\n\n", user->email, user->nome, user->idade);
  //   }
  //   printf("Entre com o email: ");
  //   fgets(user_email, 63, stdin);
  //   strip(user_email);
  // }

  Dic dicap = loadacentos("tabacentos.txt");
  // letras acentuadas em C ocupam mais de 1 espaço no vetor (procurar resolver)
  char texto[256];
  // toda chave deste dicinário é string
  printf("Entre com o texto: ");
  fgets(texto, 255, stdin);
  printf("ANTES: %s\n", texto);

  removeAcentos(texto, dicap);
  printf("DEPOIS: %s\n", texto);
  return 0;
}