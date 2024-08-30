#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char t_nomes[50];

typedef struct {
  t_nomes cep;
  t_nomes rua;
} t_endereco;

int main() {
  t_endereco *p;
  t_nomes linha;
  t_nomes auxCep;
  t_nomes auxRua;
  p = malloc(20 * sizeof(t_endereco));

  FILE *arq = fopen("./bdcepseruas.txt", "rt");
  if (arq == NULL)
    return 1;

  int k = 0; // contador para endereco seguinte

  while (!feof(arq)) {
    int i = 0; // contador p/ primeira palavra (cep)
    int j = 0; // contador p/ segunda palavra (rua)
    fgets(linha, 50, arq);

    // percorre a linha até encontrar a vírgula
    while (linha[i] != ',' && linha[i] != '\0') {
      auxCep[i] = linha[i];
      i++;
    }
    auxCep[i] = '\0'; // adiciona o caractere de terminação

    // pula a vírgula e espaços em branco
    i++;
    while (auxCep[i] == ' ') {
      i++;
    }

    // copia o resto da linha para auxRua
    while (linha[i] != '\0') {
      auxRua[j] = linha[i];
      i++;
      j++;
    }
    auxRua[j] = '\0';

    // passa auxCep para o campo cep e auxRua para o campo rua do ponteiro[k]
    strcpy(p[k].cep, auxCep);
    strcpy(p[k].rua, auxRua);
    printf("%s\n", p[k].cep);

    k++;
  }

  fclose(arq);
  return 0;
}