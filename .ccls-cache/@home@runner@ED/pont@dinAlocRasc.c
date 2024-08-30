#include <stdio.h>

// static, STACK, HEAP -- áreas de memória em que as variáveis são alocadas
// int *p é int* p

// Testar em c tutor

// Parte inicial: aritmética de ponteiros
/*
int main() {
  double d = 234.567;
  double *p = &d;

  printf("Tamanho do double = %ld\n", sizeof(double));
  printf("p antes = %p\n", p);
  p++;  // = p = p + 1 (1 = n bytes); também há p--
  printf("p depois = %p\n", p);

  return 0;
}
*/

/*
struct pessoa {
  int idade;
  double altura;
  char sexo;
};

int main() {
  struct pessoa aluno;
  struct pessoa *p = &aluno;

  aluno.idade = 18;
  aluno.altura = 1.78;
  aluno.sexo = 'M';

  // É indiferente usar -> ou (*p)
  p->idade = 19;
  (*p).altura = 1.56;
  (*p).sexo = 'F';

  return 0;
}
*/

/*
struct teste {
  int v[2];
  float vv[3];
};

int main() {
  struct teste varteste;
  varteste.v[0] = 10;
  varteste.v[1] = 3;
  varteste.vv[0] = 2.34;
  varteste.vv[1] = 55.7;
  varteste.vv[2] = 89.345;
  printf("%.2f%6.2f%6.2f\n", varteste.vv[0], varteste.vv[1], varteste.vv[2]);

  // int v[5] = {10, 3, 78, 9, 1};
  // float vv[3] = {2.34, 55.7, 89.345};
  int *p;

  // p = &v[0];

  // == p++;
  // for (int i = 0; i < 4; i++) {
  // p = &v[i];
  //}

  // quebrando:
  for (int i = 0; i < 4; i++) {
    p = &varteste.v[i];
  }
  *p = 34567;
  printf("%.2f%6.2f%6.2f\n", varteste.vv[0], varteste.vv[1], varteste.vv[2]);

  return 0;
}
*/

// Alocação dinâmica de memória (veremos o heap!)
#include <stdlib.h>

void zeravet1(int v[], int tam) {
  for (int i = 0; i < tam; i++) {
    v[i] = 0;
  }
}
int *zeravet2(int tam) {
  int *vet = malloc(sizeof(int) * tam);
  for (int i = 0; i < tam; i++) {
    *(vet + i) = 0;
    // vet[i] = 0;
  }
  return vet;
}

int *teste(int a) {
  int dd = 789;
  int *p;

  p = malloc(sizeof(int));
  *p = 2345544;
  return p;
}

int main() {
  // int *p;
  //  malloc(1000);
  // p = malloc(sizeof(int));
  //*p = 2345544;

  // printf("%d\n", *p + 5);
  int cc;
  cc = 234;
  int *q;
  q = teste(cc);
  // o que é dinâmico está no heap

  // todo vetor é um ponteiro para o primeiro elemento (ponteiro estático; não
  // permite, pois, utilizar malloc)
  return 0;
}

/*  // REVISANDO O STACK (pilha de funções)
void fa(int);
void fb(int );
void fa(int a) {
  int va;
  va = a;
  fb(va);
}
void fb(int b){
  int vb;
  vb = b;
  printf("%d\n", vb);
}
int main() {
  int vmain = 33;
  fa(vmain);
  return 0;
}*/

/* // REVISANDO O HEAP

typedef struct {
  int dia, mes, ano;
} tdata;

int main() {
  char *pi = malloc(5);
  if(pi != NULL){ // evitar segmentation fault
    *pi = 'A';
    free(pi);   // 'caveirinha'
    pi = NULL;  // remove a caveira (previne memory leak)
  }
  tdata d;
  d.dia = 5;
  d.mes = 6;
  d.ano = 2024;
  
  tdata* pd = malloc(sizeof(tdata));
  if(pi != NULL){
    pd = &d;
    pd->dia = 6;
  }
  
  int *x;
  x = malloc(sizeof(int) * 2);
  *x = 5;
  printf("%ld\n", sizeof(int));
  return 0;
}
*/
