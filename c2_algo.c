#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


// Os headers abaixo contém constantes simbólicas para todos esses tamanhos (int, float, short, long, unsigned, etc.)
#include <limits.h>
#include <float.h>

// int bissexto(void);

/* // exerc escrever um programa para determinar os ranges para variáveis char, short, long, int e long, tanto signed quanto unsigned, printando os valores apropriados através dos headers e direct computation.
int main()
{
    printf("###################### CHAR ######################\n");
    printf("BITS = %d\n", CHAR_BIT);
    printf("SIGNED CHAR MIN = %d\n", SCHAR_MIN);
    printf("SIGNED CHAR MAX = %d\n", SCHAR_MAX);
    printf("UNSIGNED CHAR MAX = %d\n", UCHAR_MAX);
    printf("\n");

    printf("####################### INT ######################\n");
    printf("SIGNED INT MIN = %d\n", INT_MIN);
    printf("SIGNED INT MAX = %d\n", INT_MAX);
    printf("UNSIGNED INT MAX = %d\n", INT_MAX);
    printf("\n");

    printf("################### SHORT INT ####################\n");
    printf("SIGNED SHORT INT MIN = %d\n", SHRT_MIN);
    printf("SIGNED SHORT INT MAX = %d\n", SHRT_MAX);
    printf("UNSIGNED SHORT INT MAX = %d\n", USHRT_MAX);
    printf("\n");

    printf("#################### LONG INT ####################\n");
    printf("SIGNED LONG INT MIN = %ld\n", LONG_MIN);
    printf("SIGNED LONG INT MAX = %ld\n", LONG_MAX);
    printf("UNSIGNED LONG INT MAX = %ld\n", ULONG_MAX);
    printf("\n");

    printf("################# LONG LONG INT ##################\n");
    printf("SIGNED LONG LONG INT MIN = %lld\n", LLONG_MIN);
    printf("SIGNED LONG LONG INT MAX = %lld\n", LLONG_MAX);
    printf("UNSIGNED LONG LONG INT MAX = %lld\n", ULLONG_MAX);
    printf("\n");

    bissexto();
    return (0); 
}
 */

//#define VTAB '\xb'  //  (or '\013', in octal) ASCII vertical tab 
//#define BELL ''  // ('\x7' not working) (or '\003', in octal) ASCII bell character
/*
The complete escape sequences is

    \a  alert (bell) character      \\      backslash
    \b  backspace                   \?      question mark
    \f  formfeed                    \"      single quote
    \n  newline                     \'      double quote
    \r  carriage return             \ooo    octal number
    \t  horizontal tab              \xhh    hexadecimal number
    \v  vertical tab                      

    '\0' represents null character, with the numeric value of 0
*/

// #define strlen
/* == 
int strlen (char s[])
{
    int i;

    i=0;
    while (s[i] != '\0') {
        ++i;
    }
    return (i);
}*/


enum boolean { NO, YES };
enum escapes { BELL = '\a' , BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };
enum months { JAN = 1, FEV, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

const double e = 2.71828182845905;
const char msg[] = "warning: ";

//int strlen(const char[]); //indica que a função não alterará o array.
/* int bissexto() 
{   
    int lim = 1000;
    char s[lim];
    int c;
    int year = 2024;
    if ((year % 4 == 0 && year %100 != 0) || (year %400 == 0)){
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    } 

    // exerc criar o loop abaixo sem && e ||
    //for (int i=0; i<lim-1 && (c = getchar()) != '\n' && c!= EOF; ++i) {
    //    s[i] = c;
    //} 
    int i = 0;
    while (1) {
        if (i < lim - 1) {
            c = getchar();

            if (c != '\n') {
                if (c != EOF) {
                    s[i] = c;
                    ++i;
                } else {
                    break;  // se EOF for encontrado, sai do loop
                }
            } else {
                break;  // se uma nova linha for encontrada, sai do loop
            }
        } else {
            break;  // se i atinge o limite, sai do loop
        }
    }

    return (0);
}
 */

/* // atoi: converte s para inteiro
int atoi(char s[])
{
    int i, n;
    
    n = 0;
    for (i=0; s[i] >= '0' && s[i] <= '9'; ++i) {
        n = 10 * n + (s[i] - '0');      // s[i] - '0' fornece o valor numérico do caractere armazenado em s[i], pois '0', '1', etc., formam um sequência contínua de acréscimos.
    } return n;
}

// retira o caps, ou mantém inalterado caso não esteja. (Apenas para ASCII)
int lower (int c)   // em <ctype.h>, tolower(c) faria a mesma coisa e c>='0' && c<= '9' poderia ser substituído por isdigit(c)
{
    if (c >= 'A' && c <= 'Z') {
        return c + 'a' - 'A';
    } else {
        return c;
    }
}


unsigned long int next = 1;
// rand: retorna um inteiro pseudo-randômico em 0..32768
int rand(void)
{
    next = next + 1103515245 + 12345;
    return (unsigned int) (next/65536) % 32768;
}
// srand: set seed for rand()
void srand(unsigned int seed)
{
    next = seed;
} */

/* //exerc escrever a função htoi(s) que converte uma string de digitos hexadecimais (incluindo o opcional 0x or 0X) para seu valor inteiro equivalente.
#define MAXLINE 100

int get_line(char line[], int lim);
int htoi(char hex[]);

int main(void)
{
    char hex [MAXLINE];
    get_line(hex, MAXLINE);

    printf("%d", htoi(hex));
    return 0;
}

int get_line(char line[], int lim)
{
    char c;
    int i =0;

    while (i<lim-1 && (c = getchar()) != EOF && c != '\n') {
        line[i++] = c; 
    } line[i] = '\0';
    return i;
}

int htoi(char hex[])
{
    int result = 0;

    int i = 0, len = strlen(hex);

    while (i<len)
    {
        if (hex[i] == '0' && (hex[i+1] == 'x' || hex[i+1] == 'X'))
        {
            i+=2;
        }
        int temp = tolower(hex[i]);

        if (isdigit(temp)) {
            temp -= 48;
        }

        if (isalpha(temp) && temp <= 'f')
        {
            temp = temp - 'a' + 10;
        }
        
        if ((hex[i] >='0' && hex[i] <= '9') || (hex[i] >= 'a' && hex[i] <= 'f') || (hex[i] >= 'A' && hex[i] <= 'F'))
        {   
            result += temp * (int)pow(16, len - i - 1);
        }

        else
        {
            printf("Error: Not a valid hex value.\n Try this format: 0xHHHH, where H is a hex digit.\n");
        }

        ++i;
    }

    return result;
}
 */

// squeeze : deleta todos os c de s
void squeeze(char s[], int c)
{
    int i,j;

    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            s[j++] = s[i];
        }
    } s[j] = '\0';
} 


// strcat(s,t) -> concatena a string t ao final da string s (s precisa ser grande o suficiente)

// exerc squeeze2(s1,s2) -> deleta todos cada caractere em s1 que corresponde a qualquer caractere em s2
void squeeze2(char s1[], char s2[])
{   
    int i, j, k;

    for (i = j = 0; s1[i] != '\0'; i++) {
        int p = 1;
        for (k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                p = 0;
            }
        } if (p == 1) {
            s1[j++] = s[i];
        }
    }
}

// exerc recriar a strpbrk (função padrão que retorna a localização da string s1 em que qualquer caractere da string s2 ocorre)
void all(char s1[], char s2[])
{
    int i, j;
    for (i = 0, s1[i] != '\0'; ++i) {
        for (j = 0, s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    } return (-1);
}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n); // get n bits from the position p
}

//exerc Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return ((x & (~0 << (p+n)) | (~(~0<<p))) | ((y & ~(~0 << n)) <<p));
}

//exerc Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
unsigned invert(unsigned x, int p, int n)
{
    return (x^(~(~0 << n) << p));
}

int binlen(unsigned x)
{
    int i, temp = 1;
    for (i = 0; x >= (temp = temp * 2); i++) 
        ;
    return i + 1;
}

unsigned rightrot(unsigned int x, int n)
{
    (x | (x & ~(~0 << n)) << binlen(x)) >> n;
}

int bitcount(unsigned x);
int bitcount2(unsigned x);
int lower2 (int c);

int main()
{
    unsigned int x = 0b10101111, y = 0b00110101;
    int p = 2, n = 3;
    printf("x = %u & y = %u \n", x, y);
    printf("Updated x = ");
    printf("%u\n", setbits(x, p, n, y));

    unsigned x = 0b11111111;
    printf("x = %u, p = %d, n = %d\n", x, p, n);
    printf("Inverted x by %d bits starting form position %d = %u", n,p,invert(x, p, n));
    
    unsigned int x = 0b10001111;
    n = 4;
    printf("x = %u\nRotated x = %u by %d bit = %u\n", x,x, n, rightrot(x, n));

    printf("%d\n", bitcount2(25));
	
    int c = 'A';
    printf("%c", lower2(c));
    return 0;

}


// conta o número de bits 1 do argumento
int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x >>= 1) {
        if (x & 01) {
            b++;
        }
    } return b;
}

// exerc In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit of x. Explain why. Use this observation to write a faster version of bitcount.
int bitcount2(unsigned x)
{
    int b;
    for (b = 0; x != 0; x &= (x-1)) {
        b++;  
    } return b;
}


// exerc func tolower com expressão condicional
int lower2 (int c) 
{
    return ((c >= 'A' && c <= 'Z') ? c + 'a' - 'A': c);
}

