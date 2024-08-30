#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#include <ctype.h>

#include <string.h>

#include <limits.h>     // para obter a função abs()

#define MAX_ELEMENT 20000
/* int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n -1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid]) {
            high = mid -1;
        } 
        else if (x > v[mid]) {
            low = mid +1;
        }
        else {
            return mid;
        }
    } 
    return -1;
}

int binsearch2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n -1;
    mid = (low+high)/2;
    while (low <= high && low != mid) {
        if (x < v[mid]) {
            high = mid -1;
        } 
        else {
            low = mid +1;
        }
        mid = (low+high)/2;
    }
    if (x == v[mid]) {
        return mid;
    } return (-1);
}

int main()
{
    int testdata[MAX_ELEMENT];
    int index;                  //  Index of found element in test data  
    int n = 6;                 //  Element to search for  
    int i;
    clock_t time_taken;

    //  Initialize test data  
    
    for ( i = 0; i < MAX_ELEMENT; ++i )
        testdata[i] = i;
    
    
    //  Output approximation of time taken for
    //    100,000 iterations of binsearch()       
    
    for ( i = 0, time_taken = clock(); i < 100000; ++i ) {
        index = binsearch(n, testdata, MAX_ELEMENT);
    }
    time_taken = clock() - time_taken;
    
    if ( index < 0 )
        printf("Element %d not found.\n", n);
    else
        printf("Element %d found at index %d.\n", n, index);
    
    printf("binsearch() took %lu clocks (%lu seconds)\n",
           (unsigned long) time_taken,
           (unsigned long) time_taken / CLOCKS_PER_SEC);
    
    
    //  Output approximation of time taken for
    //    100,000 iterations of binsearch2()        
    
    for ( i = 0, time_taken = clock(); i < 100000; ++i ) {
        index = binsearch2(n, testdata, MAX_ELEMENT);
    }
    time_taken = clock() - time_taken;
    
    if ( index < 0 )
        printf("Element %d not found.\n", n);
    else
        printf("Element %d found at index %d.\n", n, index);
    
    printf("binsearch2() took %lu clocks (%lu seconds)\n",
           (unsigned long) time_taken,
           (unsigned long) time_taken / CLOCKS_PER_SEC);
    
}*/

/* //contador de dígitos com switch
int main()
{
    int c, i, nwhite, nother, ndigit[10];

    nwhite = nother = 0;
    for (i=0; i<10; i++) {
        ndigit[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        switch (c) {
        case '0': case '1': case '2': case '3' : case '4': 
        case '5': case '6': case '7': case '8' : case '9':
            ndigit[c-'0']++;
            break;
        case ' ':
        case '\n':
        case '\t':
            nwhite++;
            break;
        default:
            nother++;
            break;
        }
    }
    printf("digits =");
    for (i=0; i<10; i++) {
        printf(" %d", ndigit[i]);
    } printf(", white space = %d, other = %d\n", nwhite, nother);
    return 0;
}
 */

/* // exerc escape(s,t) que converte caracteres como novas linhas e tabs em sequências visíveis de escape, como \n e \t e copia a string t para s. Utilizar switch. Fazer também uma função que realize o processo inverso.
void escape(char * s, char * t );
void escapeInv(char * s, char * t );   //unescape

int main()
{
    int c, i;
    char s[1000];
    char t[1000];

    for (i = 0; i < MAX_ELEMENT-1 && (c = getchar()) != EOF; ++i) {
        t[i] = c;
    }
    t[i] = '\0';
    escape(s, t);
    printf("\nSequência de caracteres sem os escapes: %s\n", s);
    escapeInv(t, s);
    printf("\nSequência com os escapes: %s\n", t);
}

void escape(char * s, char * t)
{
    int i, j;
    i = j = 0;
    while ( t [i] ) {
        switch ( t [i] ) {
        case '\n':
            s[j++] = '\\';
            s[j] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j] = 't';
            break;
            
        case '\a':
            s[j++] = '\\';
            s[j] = 'a';
            break;
            
        case '\b':
            s[j++] = '\\';
            s[j] = 'b';
            break;
            
        case '\f':
            s[j++] = '\\';
            s[j] = 'f';
            break;
            
        case '\r':
            s[j++] = '\\';
            s[j] = 'r';
            break;
            
        case '\v':
            s[j++] = '\\';
            s[j] = 'v';
            break;
            
        case '\\':
            s[j++] = '\\';
            s[j] = '\\';
            break;
            
        case '\"':
            s[j++] = '\\';
            s[j] = '\"';
            break;
         default:         
            s[j] = t[i];    // Não é caractere especial.
            break;
        }
        ++i;
        ++j;
    }
    s[j] = t[i];    // Não esquecer do caractere nulo.
}

void escapeInv( char * s, char * t ) 
{
    int i, j;
    i = j = 0;

    while ( t[i] ) {
        switch ( t[i] ) {
        case '\\':
            switch ( t[++i]) {
            case 'n':
                s[j] = '\n';
                break;
            case 't':
                s[j] = '\t';
                break;
            case 'a':
                s[j] = '\a';
                break;
            case 'b':
                s[j] = '\b';
                break;
            case 'f':
                s[j] = '\f';
                break;
            case 'r':
                s[j] = '\r';
                break;
            case 'v':
                s[j] = '\v';
                break;
            case '\\':
                s[j] = '\\';
                break;
            case '\"':
                s[j] = '\"';
                break;
            default:
                s[j++] = '\\';
                s[j] = t[i];
            }
            break;
        
        default:
            s[j] = t[i];    // Não é sequência de escape
        }
        ++i;
        ++j;
    }
    s[j] = t[j]; // Caractere nulo
} */

// atoi: converte s para inteiro; versão 2.
/* int atoi (char s[])
{
    int i, n, sign;
    for (i = 0; isspace(s[i]); i++) {
        ;   // pula espaços em branco
    } sign = (s[i] == '-') ? -1: 1;
    if (s[i] == '+' || s[i] = '-') { 
        i++; // pula o sinal
    } for (n=0; isdigit(s[i]); i++) {
        n = 10 * n + (s[i] - '0');
    } return sign * n;
} */


// shellsort
void shellsort(int v[], int n) 
{ 
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            for (j = i-gap; j>=0 && v[j] > v[j+gap]; j-=gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
}

// reverse: reverse string s in place (com comma "," -> avaliadas da esquerda para a direita)
void reverse( char s[] )
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        // ou
        // c = s[i], s[i] = s[j], s[j] = c;
    }
}


// exerc write a function expand(s1, s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to  handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing is taken literraly.
void expand ( char * s1, char * s2);

int main(void) 
{
    char *s[] = {"a-z-", "z-a-", "-1-6-", "a-ee-a", "a-R-L", "1-9-1", "5-5", NULL};
    char result[100];
    int i = 0;
    while ( s[i] ) {
        // expande e printa oa próxima string em nosso array s[]
        expand(result, s[i]);
        printf("Não expandido: %s\n", s[i]);
        printf("Expandido    : %s\n", result);
        i++;
    }
    return 0;
}
// Copia a string s2 para s1, expandido ranges como 'a-z' e '8-3'

void expand(char * s1, char * s2) 
{
    static char upper_alph[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static char lower_alph[27] = "abcdefghijklmnopqrstuvwxyz";
    static char digits[11]     = "0123456789";

    char * start, * end, * p;
    int i = 0;
    int j = 0;


    /*  Loop through characters in s2  */

    while ( s2[i] ) {
        switch( s2[i] ) {
            case '-':
                if ( i == 0 || s2[i+1] == '\0' ) {

                    /*  '-' is leading or trailing, so just copy it  */

                    s1[j++] = '-';
                    ++i;
                    break;
                }
                else {

                    /*  We have a "range" to extrapolate. Test whether
                        the two operands are part of the same range. If
                        so, store pointers to the first and last characters
                        in the range in start and end, respectively. If
                        not, output and error message and skip this range.    */

                    if ( (start = strchr(upper_alph, s2[i-1])) &&
                         (end   = strchr(upper_alph, s2[i+1])) )
                        ;
                    else if ( (start = strchr(lower_alph, s2[i-1])) &&
                              (end   = strchr(lower_alph, s2[i+1])) )
                        ;
                    else if ( (start = strchr(digits, s2[i-1])) &&
                              (end   = strchr(digits, s2[i+1])) )
                        ;
                    else {

                        /*  We have mismatched operands in the range,
                            such as 'a-R', or '3-X', so output an error
                            message, and just copy the range expression.  */

                        fprintf(stderr, "EX3_3: Mismatched operands '%c-%c'\n",
                                s2[i-1], s2[i+1]);
                        s1[j++] = s2[i-1];
                        s1[j++] = s2[i++];
                        break;
                    }


                    /*  Expand the range  */

                    p = start;
                    while ( p != end ) {
                        s1[j++] = *p;
                        if ( end > start )
                            ++p;
                        else
                            --p;
                    }
                    s1[j++] = *p;
                    i += 2;
                }
                break;

            default:
                if ( s2[i+1] == '-' && s2[i+2] != '\0' ) {

                    /*  This character is the first operand in
                        a range, so just skip it - the range will
                        be processed in the next iteration of
                        the loop.                                   */

                    ++i;
                }
                else {

                    /*  Just a normal character, so copy it  */

                    s1[j++] = s2[i++];
                }
                break;
        }
    }
    s1[j] = s2[i];    /*  Don't forget the null character  */
}

// itoa: converte n para caracteres em s
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0) {
        n = -n;     // transforma n em positivo, se não for
    } i = 0;
    do {    // gera digitos na ordem inversa
        s[i++] = n%10 + '0'; // obtém o próximo dígito
    } while ((n /= 10) > 0); // deleta-o
    if (sign < 0) {
        s[i++] = '-';
    } s[i] = '\0';
    reverse(s);
}



//  -128            : 10000000
//  One's complement: 01111111
//  Subtract 1      : 10000000  , complemento de 2
// troca-se (n /= 10) > 0 por (n/=10), desde que as partes fracionais são truncadas com a divisão inteira, n se tornará 0 após sucessivas divisões por 10 e n/=10 se tornará falsa posteriormente. E troca-se n % 10 + '0 to 'abs(n % 10) + '0 para conseguir o caractere exato
// exerc resolver o problema acima no itoa.
/* void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0) {
        n = -n;     // transforma n em positivo, se não for
    } i = 0;
    do {    // gera digitos na ordem inversa
        s[i++] = abs(n%10) + '0'; // obtém o próximo dígito
    } while ( n /= 10 ); // deleta-o
    if (sign < 0) {
        s[i++] = '-';
    } s[i] = '\0';
    reverse(s);
} */

//int main(void) {
//  char buffer[20];
//    
//  printf("INT_MIN: %d\n", INT_MIN);
//  itoa(INT_MIN, buffer);
//  printf("Buffer : %s\n", buffer);
//    
//  return 0;
//  }

// exerc escrever a funcao itob (n,s,b) que converte o inteiro n para uma representação de caractere na base b na string s
void itob(int n, char s[], int b) {
    int i=0; 
    do
    {
        if (n%b>9) {
            s[i++] = n%b + 'A'-10;
        } else {
            s[i++] = n%b + '0';
        }
    } while (n/=b);
    reverse(s);
}

//int main() 
//{
//    int b = 16;   // hexadecimal
//    char s[MAXIMUM];
//    itob(123456,s,b);
//    printf("Base %d = %s\n",b,s);
//    return 0;
//}

//exerc faça uma versão do itoa que aceita três argumentos ao invés de dois. O terceiro argumento é um tamanho mínimo de campo; o número convertido deve ser preenchido com espaços em branco à esquerda, se necessário, para torná-lo suficientemente largo.
/* void itoa(int n, char s[], int width)
{
    int i = 0, sign, gap;
    if ((sign = n) < 0) {
        n = -n;
    } 
    do
    {
        s[i++] = n%10 + '0';
    } while (n/=10);
    if (sign<0) {
        s[i++] = '-';
    }
    gap = width - strlen(s);
    if (gap>0) {
        while gap>0 {
            s[i++] = ' ';
            gap--;
        }
    } else { 
        while (gap<0) {
            i--;
            s[i] = '\b';
            gap ++;
        }
    } reverse(s);
}*/


// trim: remove trailing blanks, tabs, newlines (parando o loop quando o mais a direita não-espaçamento é encontrado)
int trim(char s[])
{
    int n;

    for (n=strlen(s)-1; n>=0; n--) {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n') {
            break;
        }
    } s[n+1] = '\0';
    return n;
}

// for (i = 0); i<n; i++) 
//      if (a[i] < 0)
//          continue;

// goto
//  for ()
//      for ()
//          if (a[i] == b[j])
//              goto found;
// found:
//      got one a[i] == b[j]

