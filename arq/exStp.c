/*
CONSTRUA UM PROGRAMA  QUELEIA O CONTEÚDO DO ARQUIVO nomes.txt E ARMAZENE O
CONTEÚDO EM UM ARRAY C. DEFINA UM TAMANHO DE ARRAY QUE SEJA CAPAZ DE COMPORTAR O
CONTEÚDO DO ARQUIVO. EM SEGUIDA, DESCARREGUE O CONTEÚDO DO ARRAY EM UM ARQUIVO
CHAMADO nomescopy1.txt

MELHORE O PROGRAMA "ex1" ACRESCENTANDO A FUNCIONALIDADE DO USUÁRIO ESCOLHER O
NOME DO ARQUIO A SER COPIADO. FAÇA O PROGRAMA GERAR AUTOMATICAMENTE O
NOME DO ARQUIVO DESTINO ACRESCENTANDO copy AO NOME ORIGINAL

MELHORE O PROGRAMA "ex1" CRIANDO A FUNÇÃO void strip(char *). A FUNÇÃO REMOVE
<espaço>, \n, \t, \r DO INÍCIO E DO FIM DE UMA STRING. USE A FUNÇÃO strip(char
*) PARA REMOVER OS \n LIDOS POR fgets.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[32];

void novonome(String n) {
  // String aux = "";
  String aux;
  int i = 0;
  int k;

  // Copia para aux tudo que vem antes do ponto
  while (n[i] != '.') {
    aux[i] = n[i];
    i++;
  }
  aux[i] = '\0';

  strcat(aux, "copy");
  k = i + 4;

  // Copia para aux tudo que vem no e depois do ponto
  while (n[i] != '\0') {
    aux[k] = n[i];
    i++;
    k++;
  }
  aux[k] = '\0';

  // Copia aux em n
  strcpy(n, aux);
}

void altstrip(String s) {
  int k = 0, i = 0;
  char aux[32];
  strcat(aux, s);

  while (s[i]) {
    if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t') {
      aux[k] = s[i];
      k++;
    }
    i++;
  }
  aux[k] = '\0';

  // novo s
  strcpy(s, aux);
}

int main() {
  String nomes[100];
  String arqnome;
  // char arqCopiado[32];
  int i = 0;
  FILE *arq;

  printf("Digite o nome do arquivo a copiar: ");
  scanf("%s", arqnome);

  // strcat("./txt/", arqnome) // não funcionando;
  arq = fopen(arqnome, "rt");

  fgets(nomes[i], 32, arq);
  nomes[i][strlen(nomes[i]) - 1] = '\0';

  while (!feof(arq)) {
    fgets(nomes[++i], 32, arq);
    if (nomes[i][strlen(nomes[i]) - 1] == '\n')
      nomes[i][strlen(nomes[i]) - 1] = '\0';
  }

  fclose(arq);

  novonome(arqnome);

  FILE *wrt = fopen(arqnome, "wt");
  for (int j = 0; j <= i; j++) {
    /*
    if (j < 99)
      fprintf(wrt, "%s\n", nomes[j]);
    else
      fprintf(wrt, "%s", nomes[j]);
    */
    altstrip(nomes[j]);
    fprintf(wrt, "%s", nomes[j]);
    // printf("%3d\t %s\n", j + 1, vet[j]);
  }

  fclose(wrt);

  // MODO CLI = command line interface => imediato
  // MODO GUI = graphic user interface

  return 0;
}