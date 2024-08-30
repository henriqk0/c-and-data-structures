#include <stdio.h>
#define BUFSIZE 100 
static char buf[BUFSIZE];     // buffer para ungetch
static bufp = 0;           // próxima posição livre no buff

int getch(void) // get a (possibly pushed back) character
{
    return (bufp>0 ? buf[--bufp]: getchar());
}

void ungetch(int c) // push character back on input
{
    if (bufp >= BUFSIZE)
        printf("ungetch: muitos caracteres\n");
    else
        buf[bufp++] = c;
}
