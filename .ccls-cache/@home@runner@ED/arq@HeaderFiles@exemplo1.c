#include "./Vitória/arit.h"
#include <stdio.h>

// gcc exemplo1.c arit.c -o cont.bin -Wall
// tanto faz a ordem entre exemplo1.c e arit.c

int main() {
  int n1, n2;

  printf("Entre com primeiro int: ");
  scanf("%d", &n1);
  printf("Entre com segundo int: ");
  scanf("%d", &n2);

  printf("%d\n%d\n%d\n", soma(n1, n2), sub(n1, n2), mult(n1, n2));

  return 0;
}
