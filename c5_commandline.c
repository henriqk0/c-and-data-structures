#include <stdio.h>
#include <string.h>

/*
define MAXLINE 1000
int getline(char *line, int max);

// print lines that match pattern from 1st arg
int main(int argc, char *argv[]) {
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c) {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                found = -1;
                break;
            }
    if (argc != 1) 
        printf("Usage: find -x -n pattern\n");
    else
        while (getline(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    
    //if (argc != 2) 
    //    printf("Usage: find pattern\n");
    //else
    //    while (getline(line, MAXLINE) > 0)
    //        if (strstr(line, argv[1]) != NULL) {
    //            printf("%s", line);
    //            found++;
    //        }
    return found;
} */

// exerc tail -n que printa as últimas n linhas do input
#include <stdlib.h>

#define MAXLEN 1000 // max length of any input
#define MAXLINES 5000   // max lines to be stored
#define ALLOCSIZE 10000 // size of available space

static char allocbuf[ALLOCSIZE];    // storage for alloc
static char *allocp = allocbuf; // next free position

// functions
int getLine(char *, int);
char *alloc(int);
int readlines(char *[], int);
void writelines(char *[], int);
int expandArg(int, char **, int *);

// read a line into s, return lenght
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

char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {   // it fits
        allocp += n;
        return allocp - n;  // old p
    }
    return NULL;    // not enough room
}

// read input lines
int readlines(char *linerptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getLine(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } line[len -1] = '\0';  // delete newline
        strcpy(p, line);
        linerptr[nlines++] = p;
    }
    return nlines;
}

// write output lines
void writelines(char *lineptr[], int nlines) {
    while (nlines-- > 0) {
        printf("%s\n", *lineptr++);
    }
}

int expandArg(int count, char **list, int *n) {
    char *prog = *list, *end;

    while (--count > 0) {
        if (!strcmp(*++list, "-n")) { 
            end = NULL;
            if (!(*n = strtol(*++list, &end, 10)) || end) {
                printf("%s: invalid number of lines: %s\n", prog, *list);
                return 0;
            }
            *n = abs(*n);   // treat negative numbers as positives
            --count;
        } else {
            printf("Usage: %s [-n lines]\n", prog);
            return 0;
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    char *lineptr[MAXLINES];    // pointers to text lines
    int nlines; // number of read lines
    int n = 10; // default last n lines to print

    if (!expandArg(argc, argv, &n)) {
        return -1;
    } if ((nlines = readlines(lineptr, MAXLINES)) < 0) {
        printf("Error: input too big\n");
        return -1;
    }
    if (n > nlines) {   // max limit check
        n = nlines; // print entire input, not more
    } writelines(linetpr + nlines - n, n);
}
