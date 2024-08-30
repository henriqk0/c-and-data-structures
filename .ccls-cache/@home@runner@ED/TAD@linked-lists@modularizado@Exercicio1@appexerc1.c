#include "tadlista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[64];
  char email[64];
} tipo_item;

char *strip_str(char *s) {
  int ultimo = strlen(s) - 1;
  s[ultimo] = '\0';
  return s;
}

tipo_item *linha_para_item(char *linha) {
  tipo_item *p = (tipo_item *)malloc(sizeof(tipo_item));
  const char s[2] = ",";
  char *token;

  token = strtok(linha, s);
  strcpy(p->nome, token);

  token = strtok(NULL, " ");
  strcpy(p->email, token);

  return p;
}

int main() {
  tipo_item *ptr_item;
  char linha[64];
  Lista lst = new_lista();
  FILE *arq = fopen("./bdex1.txt", "rt");

  char email_buscado[64];
  int encontrado = 0;

  printf("Digite o email a ser buscado: ");
  scanf("%s", email_buscado);
  // se não estiver corretamente buscando, tentar digitar um espaço em branco
  // antes do email.

  // Carga do arquivo para a lista
  while (!feof(arq)) {
    fgets(linha, 64, arq);
    ptr_item = linha_para_item(strip_str(linha));
    appendLista(lst, ptr_item);
  }
  fclose(arq);

  for (int i = 0; i < lenLista(lst); i++) {
    ptr_item = (tipo_item *)elemLista(lst, i);
    // printf("%s, %s\n", ptr_item->nome, ptr_item->email);
    if (strcmp(ptr_item->email, email_buscado) == 0) {
      printf("%s\n", ptr_item->nome);
      encontrado = 1;
    }
  }
  if (encontrado != 1) {
    printf("EMAIL NÃO ENCONTRADO\n");
    printf("%s", email_buscado);
  }

  return 0;
}