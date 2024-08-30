#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#define MAXOP 100   // tamanho máximo do operando ou operador
// calculadora polonesa reversa
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop()/op2);
                else   
                    printf("erro: zero no divisor\n");
                break;
            // exercicio bugado abaixo
            //case '%':
            //    op2 = pop();
            //    if (op2 != 0.0)
            //        push(fmod(pop(), op2));
            //    else   
            //        printf("erro: zero no divisor\n");
            //    break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("erro: comando desconhecido %s\n", s);
                break;
        }
    }
    return 0;
}