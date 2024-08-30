/* ENUNCIADO
   Construa um programa C que leia o arquivo bdceps.txt,
   linha a linha, e armazene o conteúdo de cada linha em um vetor
   dinâmico. O vetor deve ter o seu tipo base definido pelo usuário.

   Após o preenchimento, exibir o conteúdo do vetor no console
   no formato tabela.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char strcep[10];
  char strrua[64];
} t_endereco;

void bsi3strip(char s[]) {
  if (s[strlen(s) - 1] == '\n')
    s[strlen(s) - 1] = '\0'; /* faz o strip */
}

void set_endereco_1(t_endereco *e, char *s) {
  char *token;
  token = strtok(s, ",");
  strcpy(e->strcep, token);
  token = strtok(NULL, ",");
  strcpy(e->strrua, token);
}

t_endereco set_endereco_2(t_endereco e, char *s) {
  char *token;
  token = strtok(s, ",");
  strcpy(e.strcep, token);
  token = strtok(NULL, ",");
  strcpy(e.strrua, token);

  return e;
}

int main() {
  t_endereco *vetcep; /* vetor dinâmico de t_enderecos */
  FILE *arq;
  char linha[128];

  //(t_endereco*)malloc pode ser necessário em outros compiladores e versões do
  // GCC mais antigas
  vetcep = (t_endereco *)malloc(20 * sizeof(t_endereco));
  arq = fopen("./bdcepseruas.txt", "rt");

  int indice = 0;

  while (!feof(arq)) {
    fgets(linha, sizeof(linha) - 1, arq);
    bsi3strip(linha);

    set_endereco_1(&vetcep[indice], linha);

    /*
      ou
      vetcep[indice] = set_endereco_2(vetcep[indice],linha);
    */

    indice++;
  } // fim while

  for (int i = 0; i < 20; i++)
    printf("CEP: %s, RUA: %s\n", vetcep[i].strcep, vetcep[i].strrua);

  fclose(arq);

  return 0;
}