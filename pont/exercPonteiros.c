#include <stdio.h>
// Lista de Exercícios: ponteiros
/* Enunciados
1. Quais das seguintes instruções são corretas para declarar um ponteiro?
a) int _ptr x;
c) *int ptr;
b) int *ptr;
d) *x;
2. Qual é a maneira correta de referenciar ch, assumindo que o endereço de ch
foi atribuído ao ponteiro indica? a) *indica; d) ch b) int *indica; e) *ch; c)
*indic;
3. Na expressão float *pont; o que é do tipo float?
a) a variável pont.
c) a variável apontada por pont.
b) o endereço de pont.
d) nenhuma das anteriores.
5. Assumindo que o endereço de num foi atribuído a um ponteiro pnum, quais das
seguintes expressões são verdadeiras? a) num == &pnum c) pnum == *num b) num ==
*pnum d) pnum == &num
6. Assumindo que queremos ler o valor de x, e o endereço de x foi atribuído a
px, a instrução seguinte é correta? Por que? scanf ( “%d”, *px );
7. Qual é a instrução que deve ser adicionada ao programa seguinte para que ele
trabalhe corretamente? main () { int j, *pj; *pj = 3;
}
8. Assumindo que o endereço da variável x foi atribuído a um ponteiro px,
escreva uma expressão que não usa x e divida x por 5.
9. Qual o valor das seguintes expressões:
int i = 3, j = 5;
int *p = &i, *q = &j;
a) p == &i b) *p - *q c) **&p
10. Qual será a saída deste programa?
main () {
int i = 5, *p = &i;
printf ( “%u %d %d %d %d \n”, p, *p+2, **&p, 3**p, **&p+4);
}
11. Se i e j são variáveis inteiras e p e q são ponteiros para inteiros, quais
das seguintes expressões de atribuição são ilegais? a) p = &i; b) *q = &j; c) p
= &*&i; d) i = (*&)j; e) i = *&*&j; f) q = &p; g) i = (*p) ++ + *q;
12. Seja a seguinte seqüência de instruções em um programa C:
int *pti;
int i = 10;
pti = &i;
Qual afirmativa é falsa?
a) pti armazena o endereço de i
b) *pti é igual a 10
c) ao se executar *pti = 20; i passará a ter o valor 20
d) ao se alterar o valor de i, *pti será modificado
e) pti é igual a 10
13. Considerando as variáveis e ponteiros definidos abaixo; quais são as
atribuições permitidas?
int x, *ptx, **pp; float a, *pta, **pf;
a) x = 100;
b)*pta = &a;
c) ptx = &a;
d) *pf = &a;
e) pp = &pta;
f) **pf = 7.9;
g) *ptx = 20;
h) ptx = &x;
i) pp = &x;
j) pf = &pta;
14. Considerando as variáveis e ponteiros definidos abaixo; quais são as
atribuições permitidas?
int i, *pi, **ppi; float f, *pf, **ppf;
a) i = f;
b) pf= &i;
c) *pf = 5.9;
d) *ppi = &pi;
e) *pf = 10;
f) f = i;
g) pi = &f;
h) *pi = 7.3;
i) ppf = &pf;
j) **ppi = 100;
15. Dadas as declarações abaixo; qual é o valor dos itens:
int x = 10, *px = &x, **ppx = &x;
float y = 5.9, *py = &y, **ppy = &py;
x[ ] FFA0; y[ ] FFB4; px[ ] FFF0; py[ ] FFC6; ppx[ ] FFD4; ppy[ ] FFA6
a) x =
b) *py =
c) px =
d) &y =
e) *px =
f) y =
g) *ppx =
h) py =
i) &x =
j) py++ =
k) *px-- =
l) **ppy =
m) &ppy =
n) *&px =
o) **ppx++ =
p) px++ =
q) &ppx =


*/
/* Respostas
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

10. R: 4278193108  7  5  15  9

11. R: b , f (* recebendo **)

12. R: e

13. R: a, c, e, g, h, i, j

14. R: a, b, c, e, f, g, h, i

15.int x = 10, *px = &x, **ppx = &x;
float y = 5.9, *py = &y, **ppy = &py;
x[ ] FFA0; y[ ] FFB4; px[ ] FFF0; py[ ] FFC6; ppx[ ] FFD4; ppy[ ] FFA6
a) x = 10
b) *py = 5.9
c) px = FFA0
d) &y = FFB4
e) *px = 10
f) y = 5.9
g) *ppx = 10
h) py = FFB4
i) &x = FFA0
j) py++ = FFC6
k) *px-- = inexistente
l) **ppy = FFB4
m) &ppy = FFA6
n) *&px = FFA0
o) **ppx++ = FFD4
p) px++ = 5.9
q) &ppx = FFA

*/

/*
int main() {
  // notas importantes e rascunhos
  int c, *pont;

  // tanto faz a ordem de inicialização a seguir:
  c = 0;
  pont = &c;

  // printf("%d\n", (pont == &c)); // endereço == endereço
  // printf("%d\n", (*pont == c));  // armazenado no endereço pont == c
  scanf("%d", pont); //  == "%d", &*px);
  printf("%d\n", c);

  return 0;
}*/
