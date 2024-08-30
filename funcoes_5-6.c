#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER '0'  // sinal que um número foi encontrado
#define NAME '1'    // sinal que um comando string foi encontrado

int atoip(const char *);
double atofp(const char *);
void itoap(int , char *);
int getlinep(char *, int);
int getopp(char *);
void reversep(char *);
int strindexp(const char *, const char *);

// converte s para inteiro (cap. 3)
int atoip(const char *s) {
    int n, sign;

    while (isspace(*s))
        ++s;    // pular espaços em branco
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        ++s;    // pular o sinal
    for (n = 0; isdigit(*s); ++s)
        n = 10 * n + (*s - '0');
    return sign * n;
}

// converte a string s para double (cap. 4)
double atofp(const char *s) {
    int sign, expSign;
    double val, power, exponent;

    while (isspace(*s))
        ++s;    // pular espaços em branco
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        ++s;    // pular o sinal
    for (val = 0.0; isdigit(*s); ++s)
        val = 10.0 * val + (*s - '0');
    if (*s == '.')
        ++s;
    for (power = 1.0; isdigit(*s); ++s) {
        val = 10.0 * val + (*s - '0');
        power *= 10.0;
    }
    if (tolower(*s) == 'e')     // notação científica
        ++s;
    expSign = (*s == '-') ? -1: 1;     // guardar o sinal do expoentes
    if (*s == '+' || *s == '-')
        ++s;    // pular o sinal
    for (exponent = 0.0; isdigit(*s); s++)
        exponent = 10 * exponent + (*s - '0');
    while (exponent-- != 0)     // ajustar a potência de acordo com o expoente
        power = (expSign > 0) ? power / 10: power * 10;
    return sign * val / power;
}

// converte n para caracteres em s (cap. 3)
void itoap(int n, char *s) {
    int sign;
    sign = n;   // guardar o sinal
    do {    // gera digitnos ao inverso
        *s++ = abs(n % 10 + '0');   // gera o próximo dígito
    } while ((n /= 10) > 0);    // deleta-o
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reversep(s - strlen(s));
}

// lê uma linha em s, retorna o tamanho
int getlinep(char *s, int lim) {
    int c;
    char *len;

    len = s;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n') 
        *s++ = c;
    *s = '\0';
    return strlen(len); 
}

// conseguir o próximo operador ou operador numérico (cap. 4) - getch/ungetch version
int getopp(char *s) {
    int c;
    char *var;

    while (isblank(s[0] = c = getchar())) 
        ;
    s[1] = '\0';
    if (c == '-') // checar o sinal
        if (!isdigit(*++s = c = getchar())) {
            ungetc(c, stdin);
            c = *--s; // não é um sinal
        }
    if (isalnum(c)) {   // comando string
        var = s;
        while (isalnum(*++s = c = getchar()))
            ;
        *s = '\0';
        ungetc(c, stdin);
        return (strlen(var) == 1) ? var[0] : NAME;
    }
    if (!isdigit(c) && c != '.')
        return c;   // não é um número
    if (isdigit(c))
        while (isdigit(*++s = c = getchar()))
            ;
    if (c == '.')   // coleta a parte fracional
        while (isdigit(*++s = c = getchar()))
            ;
    *s = '\0';
    ungetc(c, stdin);
    return NUMBER;
}

// inverte a string s (cap. 3)
void reversep(char *s) {
    char *p, *q, tmp;

    q = s + strlen(s) - 1;
    for (p = s; p < q; ++p, --q) {
        tmp = *p;
        *p = *q;
        *q = tmp;
    }
}

// retorna o índice de t em s, 01 se nao houver (cap. 4)
int strindexp(const char *s, const char *t) {
    int pos;
    const char *j, *k;

    for (pos = 0; *s; ++s, ++pos) {
        for (j = s, k = t; *k && (*j == *k); ++j, ++k)
            ;
        if (k > t && *k == '\0')
            return pos;
    }
    return -1;
}

int main(void) {
    char str[] = "It's not personal";
    const char *pattern = "son";
    char str2[] = "5892";
    int pos, number;

    // strindex
    if ((pos = strindexp(str, pattern)) < 0)
        printf("Not found\n");
    else    
        printf("%i\n", pos);
    // reverse
    reversep(str);
    printf("%s\n", str);
    // atoi
    number = atoip(str2);
    printf("%i\n", number);
    printf("%i\n", atoip("4092"));
    return 0;

} 