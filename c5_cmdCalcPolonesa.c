/* NOTE: * and % must be included in equation marks at the command prompt,
 * otherwise they will be interpreted by the shell as wildcard characters */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER '0'
#define MAXVAL 100

// funções
void push(double);
double pop(void);

// globais
int sp = 0;     // próxima posição livre do stack
double val[MAXVAL]; // valor do stack

// push f para o valor da stack
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("Erro: stack cheia, não pode empurrar %g\n", f);
    }
}

// pop e retorna o valor do top do stack
double pop(void) { 
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("erro: stack vazio/\n");
        return 0.0;
    }
}

int main(int argc, char *argv[]) {
    int type;
    double num, op2;

    if (argc < 4) {
        printf("Usage: %s <expr>... \n", *argv);
        return -1;
    }

    while (--argc > 0) { 
        ++argv;             // pular o nome do programa
        if ((num = atof(*argv))) {
            type = NUMBER;
        } else {
            type = **argv;   // primeiro caractere *argv na string
        }
        switch (type) {
        case NUMBER:
            push(num);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '*':
            push(pop() * pop());
        case '/':
            op2 = pop();
            if (op2 != 0.0) {
                push(pop() / op2);
            } else {
                printf("erro: zero como divisor");
                argc = 1;
            }
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0) {
                push((long) pop() & (long) op2);
            } else {
                printf("erro: zero como divisor");
                argc = 1;
            }
            break;
        default:
            printf("erro: comando desconhecido %s\n", *argv);
            argc = 1;
            break;
        }
    }
    printf(" %.8g\n", pop());   // imprime o resultado
    return 0;
}



