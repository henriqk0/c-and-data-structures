#include <stdio.h>
#include <ctype.h>
#include "calc.h"

// getop: get next operator or numeric operand
int getop(char s[])
{
    int i, c;
    static int buf = EOF; // exerc desusar o ungetch

    if (buf == EOF || buf == ' ' || buf '\t') {
        while ((s[0] = c = getch()) == ' ' || c == 't')
            ;
        s[1] = '\0';
    } else
        c = buf;
    if (!isdigit(c) && c != '.')
        return c; // não é número
    i = 0;
    if (isdigit(c)) // coleta a parte inteira
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') // coleta a parte fracionária
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        buf = c;
    return NUMBER;
}