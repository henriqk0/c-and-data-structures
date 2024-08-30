#include <stdio.h>
/*
Lista de Exercícios: Ponteiros
1. R: b

2. R: a

3. R: c

5. R: d, b

6. R: Não, pois a função scanf opera em cima do endereço de uma variável e
acrescentar * ao ponteiro fará com que scanf leia o conteúdo do endereço, o que
não é possível.

7. R: Compilará, mas é preciso inicializar j, e não *pj, como 3, inicializar pj,
e não *pj, com o valor armazenado em j, para que o endereço de pj armazene
corretamente 3.

8. R: px = &x;  *px = *px / 5;

9. R: a) 1    b) -2    c) 3

10.

*/

int main() {
  int c, *pont;

  // tanto faz a ordem de inicialização a seguir:
  c = 0;
  pont = &c;

  // printf("%d\n", (pont == &c)); // endereço = endereço
  // printf("%d\n", (*pont == c));  // armazenado no endereço pont = c
  scanf("%d", pont); //  == "%d", &*px);
  printf("%d\n", c);
  return 0;
}