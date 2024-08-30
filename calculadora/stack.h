#include <stdio.h>
#include "calc.h"
#define MAXVAL 100    // max depth of val stack

static sp = 0;           // próxima posição livre no stack
static val[MAXVAL];   // valor do stack

// push: push f onto value stack
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else   
        printf("erro: stack cheio, não pode empurar %g\n", f);
}

// pop: pop and return top value from stack
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("erro: stack vazio\n");
        return 0.0;
    }
}
