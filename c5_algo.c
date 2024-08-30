#include <stdio.h>
#include <stdlib.h> // atof, etc.
#include <ctype.h>
#include <math.h>


// int swap(a, b);      errado -> a função apenas realiza uma swap de cópias de a e b;

//int swap(&a, &b); ou (int *a, int *b)    // unário -> '&' produz o endereço da variável ('&a' é um ponteiro para 'a')

/*
 * The getch and ungetch functions, from section 4.3, are also required.
 */

#define BUFSIZE 100

int getch(void);
void ungetch(int);
int getint(int *);
int getfloat(double *);

int buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

int getch(void)         /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)     /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

// Exercise 5-1. As written, getint treats a + or - followed by a digit as a
// valid representation of zero. Fix it to push such a character back on the
// input

// getint: get next interer from input into *pn
int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch())) // skip white space
        ;
    if (!isdigit(c) && c != '+' && c != '-') {
        ungetch(c); // não é número
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        if (!isdigit((c = getch()))) // sign followed by a digit?
            return 0; // not a number
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
        
    *pn *= sign;
    ungetch(c);
    return c;
}


// Exercise 5-2. Write getfloat, the floating-point anolog of getint. What type
// does getfloat return as its function value?
//
// Answer: It should return an int, which then could be used to check if the
// operation was successful or not or if the EOF was reached. See main
// function.

// getfloat: get next float from input into *pn
int getfloat(double *pn) {
    int c, sign;
    double i;

    while (isspace((c = getch()))) // skip whitespace
        ;
    if (!isdigit(c) && c != '.' && c != '+' && c != '-') {
        ungetch(c); // is not a number
        return (0);
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') 
        if (!isdigit((c = getch()))) // is the sign followed by a digit?
            return (0); // it is not a number
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    if (c == '.') 
        for (i = 10.0F; isdigit(c = getch()); i = i * 10.0F)
            *pn += (c - '0') / i;

    *pn *= sign;
    ungetch(c);
    return c;
}


//void swap(int *px, int *py) // swap entre *px e *py
//{
//    int temp;
//
//    temp = *px;
//    *px = *py;
//    *py = temp;
//}

#define ALLOCSIZE 10000 // size of available space

static char allocbuf[ALLOCSIZE]; // storage for alloc
static char *allocp = allocbuf; // next free position (static char *allocp = allocbuf ==  static char *allocp = &allocbuf[0])

char *alloc(int n) // return pointer to n characters
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { // it fits
        allocp += n;
        return allocp - n; // old p
    } else { // not enough room
        return (0);
    }
}

void afree(char *p) // free storage pointed to by p
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}


// strcpy (pointer version): copy t to s    (in string.h)
void my_strcpy(char *s, char *t) {
    while ((*s++ = *t++) != '\0')   // '\0' é redundante aqui
        ;
}

// strcmp (pointer version): return <0 if s<t; 0 if s==t, >0 if s>t
int my_strcmp(char *s, char *t) {
    for ( ; *s == *t; s++, t++) { 
        if (*s == '\0') 
            return 0;
    } return *s - *t;
}

// exerc strcat(s, t) that copies the string t to the end of s (pointer version)
void my_strcat(char *s, char *t) {
    while ( (*s) != '\0' )    // redundância
        ++s;
    while ((*s++ = *t++))
        ; 
}

// exerc strend(s,t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise.
#include <string.h>
int my_strend(char *s, char *t) {
    int endS = strlen(s) - strlen(t);

    for (int i = 0; i < endS; ++i) {
        ++s;
    }   // s += strlen(s) - strlen(t) já avançaria o ponteiro 
    while ((*s)) {
        if (*s++ != *t++) {
            return 0;
        }
    } return 1;
}

// exerc strcpy, strcat, strcmp which operate on at most of the first n characters of their argument strings.
#define MAXCHAR 32
char *my_strncpy(char *, char *, const size_t);
char *my_strncat(char *, char *, const size_t);
int strnCmp(const char *, const char *, const size_t);

char *my_strncpy(char *s, char *t, const size_t n) {
    size_t i;

    for (i = 0; i<n; ++i) {
        if (!(*s++ = *t++)) {   // copia o caractere
            *s = '\0';  // t < n
        }
    } *s = '\0';    // caractere terminante
    return s - n;   
}

char *my_strncat(char *s, char *t, const size_t n) {
    size_t i, s_len, t_len, lim;

    s += (s_len = strlen(s));
    lim = (n > (t_len = strlen(t))) ? t_len : n;
    for (i = 0; i < lim && (*s++ = *t++); ++i)
        ;
    *s = '\0';
    return s - s_len - i;
}

int strnCmp(const char *s, const char *t, const size_t n) {
    size_t i; 

    for (i = 1; i < n && *s == *t; ++s, ++t, ++i)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

// ---------- arrays multidimensionais (exemplo) ----------
int day_of_year(int, int, int);
void month_day(int, int, int *, int *);

static char daytab[2][13] = { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };

char (*pdaytab)[13] = daytab;   // ponteiro para o primeiro elemento (1o array)
                                // podemos usá-lo diretamente

// adquire o dia do ano a partir do mês e seu dia
int day_of_year(int year, int month, int day) {
    int i, leap;

    if ((year < 1) || month < 1 || month > 12 || day < 1  || day > 31)
        return -1;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++) {
        day += *(*(pdaytab+leap) + i);          // ou
        // day += daytab[leap][i];
    } 
    return day;
}

// adquire o mês e o dia do mês a partir do dia do ano
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    if (year < 0 || yearday < 1 || yearday > 366) {
        *pmonth = *pday =  0;
        return;
    }
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0; 
    for (i = 1; yearday > daytab[leap][i]; i++) {
        yearday -= *(*(pdaytab + leap) + i);    // ou
        //yearday -= daytab[leap][i];
    } 
    *pmonth = i;
    *pday = yearday;
} 

// retorna o nome do enésimo mês
char *month_name(int n) {
    static char *name[] = {
        "Inexistente",
        "Janeiro", "Fevereiro", "Março", "Abril",
        "Maio", "Junho", "Julho", "Agosto",
        "Setembro", "Outubro", "Novembro", "Dezembro"
    };
    return (n < 1 || n > 12) ? name[0] : name[n];
}

/*
// echo command-line arguments
int main(int argc, char *argv[]) //arg count e arg vector
{
    int i;

    for (i = 1; i < argc; i++) 
        printf("%s%s", argv[i], (i < argc - 1) ? " ": "");
    
    //versão 2
    //while (--argc > 0)
    //  printf("%s%s", *++argv, (argc > 1) ? " " : "");  // ou
    //  //printf((argc > 1) ? "%s ": "%s", *++argv);
    
    printf("\n");
    return 0;
}
*/



/*
int main(void) {
    int n, input;
    double num;
    //int num;
    //
    //while ((input = getint(&num)) && input != EOF) {
    //    printf("%i\n", num);
    //}
    
    int yearday, month, day;

    char dest[MAXCHAR];

	printf("%s\n", my_strncpy(dest, "copy me", 4));
	printf("%s\n", my_strncat(dest, "concatenate", 4));
	printf("%i\n", strnCmp("samee", "same", 4));
	printf("%i\n", strnCmp("samee", "same", 5));

    printf("\n%i\n", day_of_year(2024, 3, 7));
    month_day(2024, 300, &month, &day);
    printf("\n%i / %i / 2024\n", month, day);
    printf("%s\n",month_name(5));


    while ((input = getfloat(&num)) && input != EOF) {
        printf("%g\n", num);
    }  
    return 0;
} */

#include <string.h>
#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

int numcmp(char *s1, char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else 
        return 0;
}

void swap(void *v[], int i, int j) {
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int, int);
    
    if (left >= right)  // do nothing if array contains
        return;         // fewer than two elements
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1, comp);
    qsort(v, last+1, right, comp);
}



// sort input lines
int main(int argc, char *argv[]) {
    int nlines;         // number of input lines read
    int numeric = 0;    // 1 if numeric sort

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

