#include <stdio.h>

#include <string.h>

#define MAXLINES 5000       // máximo de linhas a serem ordenadas

#define ALLOCSIZE 100000  // armazenamento para alloc
char *lineptr[MAXLINES];    // ponteiros para a linhas de texto
static char allocbuf[ALLOCSIZE];  // armazenamento para alloc 
static char *allocp = allocbuf;   // proxima posição livre


int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

// #define MAXLEN 1000     // tamanho máximo de uma linha de input
char *alloc(int);

int my_getline(char *s, int lim, FILE *stream) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getc(stream)) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

// ler as linhas de input
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[1000];

    nlines = 0;
    while ((len = my_getline(line, 1000, stdin)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) 
            return -1;
        else {
            line[len-1] = '\0'; //deletar a nova linha
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    } return nlines;
}

// exerc retornar o ponteiro para n caracteres
char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {    
        allocp += n;
        return allocp - n; 
    } else 
        return 0;
}


// escreve as linhas de output
void writelines(char *lineptr[], int nlines) {
    int i;

    for (i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

// troca v[i] e v[j]
void swap(char *v[], int i, int j) {
    char *temp;
    
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// sort v[left] ... v[right] em ordem crescente
void qsort(char *v[], int left, int right) {
    int i, last;
    // void swap(char *v[], int i, int j);

    if (left >= right) // não fazer nada
        return;     // menor que dois elementos
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i<= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

// troca v[i] e v[j]
//void swap(char *v[], int i, int j) {
//    char *temp;
//    
//    temp = v[i];
//    v[i] = v[j];
//    v[j] = temp;
//}

// ordena linhas de input   (5.7)
int main() {
    int nlines; // número de linhas de input lidas

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("erro: input grande demais para ordenação\n");
        return 1;
    }
}


