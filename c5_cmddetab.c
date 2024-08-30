#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000 // tamanho máximo da linha de i/o
#define MAXTABS 100 // número máximo de posições de paradas de tabs
#define N 4 // paradas de tab padrões (a cada n colunas)

// funções
int getLine(char *, int);
int setTabList(int, char **, int *);
int ToTabStop(int, int *, int);
void detab(char *, char *, int *, int);

// lê uma linha em s, retorna seu tamanho
int getLine(char *s, int lim) { 
    int c;
    char *len;

    len = s;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        *s++ = c;
    } if (c == '\n') {
        *s++ = c;
    } *s = '\0';
    return strlen(len);
}

// extracts topstops positions from command line arguments and store them in tabList. Return size of size of tabList, 0 if no tabstop list was provided, or -1 if arg is an invalid tabstop value.
int setTabList(int count, char **arg, int *tabList) {
    int i;

    for (i = 0; --count > 0; ++i) {
        if (!(tabList[i] = atoi(*++arg)) || tabList[i] < 0) {
            printf("Invalid tabstop: %s\n", *arg);
            return -1;
        }
        return i;   // i is 0 if no tabList
    }
}

// return the number of blanks to the next tab stop position
int ToTabStop(int column, int *tabList, int tlSize) {
    if (!tlSize) {
        return N - (column % N);
    }
    // if list exists, find nearest tab stop position in it
    while (tlSize != 0 && column >= *tabList) {
        ++tabList;
        --tlSize;
    }
    return *tabList - column;
}

// replaces tabs with the proper number of blanks
void detab(char *in, char *out, int *tabList, int tlSize) {
    int i;  // index for read line
    int j;  // index for modified (written) line
    int nblanks;    // number of required blanks

    for (i = j = 0; in[i] != '\0'; ++i) {
        if (in[i] == '\t') {
            nblanks = ToTabStop(j, tabList, tlSize);
            while (nblanks-- > 0) {
                out[j++] = ' ';
            }
        } else {
            out[j++] = in[i];
        }
    } 
    out[j] = '\0';
}

int main(int argc, char *argv[]) {
    char in[MAXLEN];    // currentlu read line
    char out[MAXLEN];   // modified line
    int tabList[MAXTABS];   // a list of tab stop positions;
    int tlSize;  // size of tablist

    if ((tlSize = setTabList(argc, argv, tabList)) >= 0) {
        while (getLine(in, MAXLEN) > 0) {
            detab(in, out, tabList, tlSize);
            printf("%s", out);
        }
    }
    return 0;
}
