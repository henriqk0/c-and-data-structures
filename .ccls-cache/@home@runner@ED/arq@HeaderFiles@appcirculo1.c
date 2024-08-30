#include "circ.h"
#include <stdio.h>

int main() {
  double raio;
  printf("Digite um valor de raio: ");
  scanf("%lf", &raio);

  printf("Área: %.2lf\nDiâmetro: %.2lf\nPerímetro: %.2lf\n", area(raio),
         diam(raio), perim(raio));
  return 0;
}