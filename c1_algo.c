#include <stdio.h>
#include <stdlib.h>

#define LOWER 0
#define UPPER 300
#define STEP 20
// Pressione Ctrl+D no terminal para os programas funcionarem corretamente.
/* //print Fahrenheit-Celsius table
    for fahr = 0, 20,..., 300 */ 

/* //while loop 
int main()
{
    float fahr, celsius;
    int lower, upper, step;
    
    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        //celsius = 5 * (fahr-32)/9;
        celsius = (5.0/9.0)*(fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
} */

/* //for loop 
int main()
{
    int fahr;
    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}*/

/* //output
int main()
{
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
*/
/* //exercício output
int main()
{
    int fahr;
    for (fahr = UPPER; fahr > LOWER; fahr = fahr - STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
*/

/* // input versão 1:
int main()
{
    int c;
    c = getchar();
    while (c != EOF){
        putchar(c);
        c = getchar();
    }
}
*/
/* // input versão 2:
int main()
{
    int c;

    while ((c = getchar()) != EOF)
        putchar(c);
    
}*/ 
/* // exercícios input:
int main()
{
    // printar o valor de EOF
    printf("O valor de EOF é: %d\n", EOF );
    // verificar se getchar() != EOF é 0 ou 1)
    printf("%d\n",(getchar() != EOF) );
    // CTRL D é o padrão do EOF para UNIX  
    return 0;
}
*/

// contar caracteres
/*  //  versão 1
int main()
{
    long nc;
    nc = 0;
    // na versão 2: while (nc=0; getchar()!=EOF; ++nc) e ; identada na linha seguinte (null statemant, requerido em C), com double nc; e %.0f no print
    while (getchar() != EOF){
        ++nc;   
    }
    printf("%ld\n", nc);
}*/ 
/* //  versão conta linhas
int main()
{
    int c, n1;
    n1 = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++n1;
    printf("%d\n",n1);
}


*/
/*  // versão conta somente caracteres digitados
int main() {
    double nc = 0;
    int c;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            ++nc;
        }
    }
    printf("%.0f\n", nc);
    return 0;
} */
/* // exerc conta espaços em branco, tabs, e quebras de linha
int main()
{
    int c, n1;
    n1 = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            ++nc;
        }
    }
    printf("%d\n",n1);
}
*/
/* // exerc imprime o input, trocando cada string de um ou mais espaços em branco por apenas um espaço em branco
int main()
{
    char cB, cA = '\0'; //\0 = caractere nulo
    // imprime o input, trocando cada string de um ou mais espaços em branco por apenas um espaço em branco
    while ((cA = getchar()) != EOF) {
        if (cA != ' ' || cB != ' '){
            putchar(cA);
        }
        cB = cA;
    }
    return 0;
}
*/
/* // exerc imprime o input, trocando os tabs por \t, os espaços por \b e cada backslash por ( \\ )
int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == ' ') {
            putchar('\\');
            putchar('b');
        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }
    }
    return 0;
}
*/

// operadores lógicos (&& e ||) e arrays
#define IN 1    // inside a word          útil em códigos longos (legibilidade)
#define OUT 0   // outside a word         util em códigos longos (legibilidade) 
/*int main() {
    int c, nl, nw, nc, state; 
    // count lines, words, and characters in input
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
        } if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    nc = nc - nl;   // desconta os \n no nº de caracteres digitados
    printf("%d %d %d\n", nl,nw,nc);
    return 0;
} */
/* // exerc printa seu input uma palavra por linha
int main() {
    int c; 
    while ((c = getchar()) != EOF) {
        ;
        if (c == ' ' || c == '\n' || c == '\t') {
            putchar('\n');
        } else {
            putchar(c);
        }
    }
    return 0;
} */
/* // contar dígitos, espaços em branco e outros
int main()
{
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i=0; i<10; ++i){
        ndigit[i] = 0;
    } 
    while ((c = getchar()) != EOF){
        if (c >= '0' && c <= '9'){
            ++ndigit[c-'0'];
        } else if (c == ' ' || c == '\n' || c == '\t') {
            ++nwhite;
        } else {
            ++nother;
        }
    } 
    printf("Digitos = ");
    for (i=0; i<10; ++i){
        printf(" %d", ndigit[i]);
    } printf(", white space = %d, other = %d\n", nwhite, nother);
}*/
/* // exerc histograma vertical pelo tamanho de caracteres de cada palavra
int main()
{
    int c, i, nw, nc; 
    int v[5];

    // Indicando o ponteiro para permitir alocação dinâmica:
    // *v; 

    nw = nc = 0;

    // Alocar espaço inicial para o array:
    //v = (int *)malloc(sizeof(int)); 

    while (( (c = getchar()) != EOF ) && nw < 5) {
        ++nc;
        if (c == ' ' || c == '\n' || c == '\t') {
            if (nc>0) {
                v[nw] = nc;
                nc = 0;
                ++nw;
                // Realocar espaço para o próximo elemento do array:
                // v = (int *)realloc(v, (nw + 1) * sizeof(int));
            }
        }
    }
    // Exibir barras horizontais
    for (i = 0; i < nw; ++i) {
        printf("%d: ", i + 1);
        for (int j = 0; j < v[i]; ++j) {
            printf("-");
        }
        printf("\n");
    }
    // '' verticais
    // Encontrar o comprimento máximo da palavra para determinar a altura do histograma
    //int maxHeight = 0;
    //for (i = 0; i < 5; ++i) {
    //    if (v[i] > maxHeight) {
    //        maxHeight = v[i];
    //    }
    //}
    // Exibir o histograma vertical
    //for (int h = maxHeight; h > 0; --h) {
    //    for (i = 0; i < 5; ++i) {
    //        if (v[i] >= h) {
    //            printf("|\t");
    //        } else {
    //            printf("\t");
    //        }
    //    }
    //    printf("\n");
    //}
    // Exibir rótulos na parte inferior
    //for (i = 0; i < 5; ++i) {
    //    printf("%d\t", i + 1);
    //}
    //printf("\n");

    //free(v);
    return 0;
}*/
/* // exerc histograma das frequencias de diferentes caracteres
#define MAX_CHAR 128

int main() {
    int c;
    int charFrequencies[MAX_CHAR] = {0}; // Array to store frequencies, initialized to zero

    // Read input and count character frequencies
    while ((c = getchar()) != EOF) {
        if (c >= 0 && c < MAX_CHAR && c != ' ' && c != '\n' && c != '\t') {
            charFrequencies[c]++;
        }
    }

    // Print histogram with horizontal bars
    for (int i = 0; i < MAX_CHAR; ++i) {
        if (charFrequencies[i] > 0) {
            printf("%c | ", i);
            for (int j = 0; j < charFrequencies[i]; ++j) {
                printf("-");
            }
            printf(" (%d)\n", charFrequencies[i]);
        }
    }

    return 0;
} */

/* // funções (1o ex.: potenciação)
int power(int base, int n)
{
    int i, p;
    p=1;
    for (i = 1; i <= n ; ++i){
        p = p * base;
    } return p; //potência uma base no expoente n (não há ** em C)
}
int main()
{
    int i;
    for (i = 0;i < 10; ++i){
        printf("%d |\t%d\t%d\n", i, power(2,i), power(-3,i));
    } return 0;
}
*/
/* // exerc reescrever a tabela fahrenheit
float conversion(float fahr, float celsius)
{
    celsius = (5.0/9.0)*(fahr-32.0);
    return celsius; // a variável mudada dentro da função auxiliar não altera, se não retornada, seu valor na original.
}
int main()
{
    float fahr, celsius;
    celsius = 0;
    for (fahr=LOWER; fahr <= UPPER; fahr = fahr + STEP){
        printf("F: %3.0f\tC°: %6.1f\n", fahr, conversion(fahr, celsius));
    } return 0;
} */

#define MAXLINE 1000    //tamanho máximo da linha do input
/* // continuação + exerc's printar maior palavra digitada, exerc printar palavras com mais de 80 caracteres; exerc remover espaços em branco, espaços ao final e tabs de cada palavra; exerc reverter as palavras
void reversedS(char s[], int start, int end)
{
    s[start] = s[start] ^ s[end];
    s[end] = s[start] ^ s[end];
    s[start] = s[start] ^ s[end];
}
int getline_noSpaceAndTab(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && ((c=getchar()) != EOF && c != '\n');){
        if (c != ' ' && c != '\t'){
            s[i] = c;
            ++i;
        }
    } if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
int my_getline(char s[], int lim)   //getline era uma função reservada, por isso o my_ 
{
    int c, i;
    for (i = 0; i < lim - 1 && ((c=getchar()) != EOF && c != '\n'); ++i){
        s[i] = c;
    } if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';    // caractere nulo no índice que corresponderia ao tamanho da linha, para mostrar seu fim. Ex.: hello\n\0; tamanho = 6
    for (int start = 0, end = i - 2; start < end; ++start, --end) {
        // ^ = swap; comecei com end = i-2 para trocar a partir do ultimo caracterer antes de \n
        reversedS(s, start, end);
        // ou com uma variável auxiliar aux = s[start]; s[start] = s[end], etc
    }
    return i;
}
void copy(char to[], char from[])   // void especifica que nenhum valor é retornado
{
    int i;
    i=0;
    while ((to[i]=from[i]) != '\0'){
        ++i;
    }
}
// printar maior linha de input
int main()
{
    int len; // atual tamanho da linha
    int max = 0; // máximo tamanho da linha
    char line[MAXLINE]; // atual linha de input
    char longest[MAXLINE]; // maior linha salva
    while ((len = my_getline(line, MAXLINE))>0){
        // exerc printar linhas com mais de 80 caracteres
        if (len > 80){
            printf("\nPalavra com > 80 caracteres:\t%s", line);
        }
        if (len > max){
            max = len;
            copy(longest, line);
        }
    } 
    if (max > 0){
        printf("\n(%d)\t\t%s",max, longest);   // então havia uma linha (não há tamanho negativo)
    } 

    return 0;
}

*/

/* // variávies externas e escopo 
int max;                // máximo comprimento encontrado
char line[MAXLINE];     // linha corrente do input
char longest[MAXLINE];  // maior linha salva 

// versão especializada do getline
int my_getline(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE - 1 && (c=getchar()) != EOF && c != '\n'; ++i){
        line[i] = c;
    } if (c == '\n') {
        line[i] = c;
        ++i;
    } 
    line[i] = '\0';
    return i;
}

// versão especializada do copy
void copy(void)
{
    int i;
    extern char line[], longest[];

    i=0;
    while ((longest[i] = line[i]) != '\0') {
        ++i;
    }
}

// imprimir a linha de maior comprimento; versão especializada
int main()
{
    int len;
    extern int max;
    extern char longest[];

    max=0;
    while ((len = my_getline()) > 0){
        if (len > max){
            max = len;
            copy();
        }
    } 
    if (max > 0){
        printf("\n%s", longest);   // então havia uma linha (não há tamanho negativo)
    }
    return 0;
}*/
#define MAX_TAB_WIDTH 8
/* // exerc detab (trocar os tabs pela quantidade correspondente de espaços em branco)
int main()
{
    int c;
    int col = 0; // Contador para coluna

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            // Calcula a quantidade de espaços em branco necessários (Divisão inteira)
            int spacesNeeded = MAX_TAB_WIDTH - (col % MAX_TAB_WIDTH);

            for (int i = 0; i < spacesNeeded; ++i) {
                putchar(' '); // Substitui o tab por espaços em branco
                ++col;
            }
        } else {
            if (c == '\n') {
                putchar(c); // Mantém a nova linha
                col = 0; // Reinicia o contador quando encontrar uma nova linha
            } else {
                putchar(c); // Mantém outros caracteres inalterados
                ++col;
            }
        }
    }
    return 0;
}
*/
/* // exerc entab
int main()
{
    int c;
    int inb, col;  
    inb = 0;
    col = 0;
    // Substitui os espaços em branco pela quantidade mínima de tabs e espaços em branco
    while ((c = getchar()) != EOF) {
        if (c == ' '){
            ++inb;
            ++col;

        } else {
            if (inb > 0) {
                if (col % MAX_TAB_WIDTH == 0) {
                    int tabs = inb / MAX_TAB_WIDTH;
                    int spaces = inb % MAX_TAB_WIDTH;
                    for (int j = 0; j < tabs; ++j) {
                        putchar('\t');
                    }
                    for (int i = 0; i < spaces; ++i) { 
                        putchar(' ');
                    }
                } else {
                    for (int i = 0; i < inb; ++i) {
                        putchar(' ');
                    }
                }
                inb = 0;
            }
            if (c == '\n') {
                putchar(c); // Mantém a nova linha
                col = 0; // Reinicia o contador quando encontrar uma nova linha
            } else {
                putchar(c); // Mantém outros caracteres inalterados
                ++col;
            }
        }
    }
    return 0;

}
*/
/* // exerc write a program to "fold" long line input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.
void divisor(char p[], char s[], int i)
{
    int j = i/2;
    int k = 0;

    for (int l = 0; l < j; ++l) {
        while (p[k] == ' ' || p[k] == '\t') {
            ++k;  // Skip leading white spaces and tabs
        }
        s[l] = p[k++];
    }
    s[j] = '\n';
    
    for (int l = j + 1; l <= i; ++l) {
        while (p[k] == ' ' || p[k] == '\t') {
            ++k;  // Skip leading white spaces and tabs
        }
        s[l] = p[k++];
    }
}

int dobraLinhas(char s[], int lim)   
{
    char p[lim];
    int c, i;
    for (i = 0; i < lim - 1 && ((c=getchar()) != EOF && c != '\n');){
        if (c != '\t' && c != ' '){
            p[i++] = c;
        }
    } if (c == '\n'){
        p[i++] = c;
    }
    divisor(p, s, i);
    s[i+1] = '\0';    // black character
    return i;
}

int main()
{
    int len; // atual tamanho da linha
    char lines[MAXLINE]; // atual linha de input
    while ((len = dobraLinhas(lines, MAXLINE)) > 0){
        printf("%s\n", lines);
    } return 0;
} */
/* //exerc remove todos os comentários
void removeComments() {
    int c, nextChar;
    int insideComment = 0;  // Flag to determine if inside a comment block
    int insideString = 0;   // Flag to determine if inside a string
    int insideChar = 0;     // Flag to determine if inside a character constant
    int lastChar = EOF;     // To track the previous character

    while ((c = getchar()) != EOF) {
        if (!insideComment && !insideString && !insideChar) {
            if (c == '/') {
                nextChar = getchar();
                if (nextChar == '*') {
                    insideComment = 1;  // Start of comment block
                } else if (nextChar == '/') {
                    // Start of line comment, ignore until end of line
                    while ((nextChar = getchar()) != EOF && nextChar != '\n');
                    if (nextChar == '\n') {
                        putchar(nextChar);
                    }
                } else {
                    putchar(c);
                    lastChar = c;
                    if (nextChar != EOF) {
                        putchar(nextChar);
                    }
                }
            } else if (c == '"') {
                insideString = 1;  // Start of string
                putchar(c);
            } else if (c == '\'') {
                insideChar = 1;  // Start of character constant
                putchar(c);
            } else {
                putchar(c);
                lastChar = c;
            }
        } else {
            if (insideComment) {
                if (c == '*') {
                    nextChar = getchar();
                    if (nextChar == '/') {
                        insideComment = 0;  // End of comment block
                    }
                }
            } else if (insideString) {
                putchar(c);
                if (c == '"' && lastChar != '\\') {
                    insideString = 0;  // End of string
                }
            } else if (insideChar) {
                putchar(c);
                if (c == '\'' && lastChar != '\\') {
                    insideChar = 0;  // End of character constant
                }
            }
        }

        if (c == '\n' && !insideComment && !insideString && !insideChar) {
            lastChar = EOF;  // Reset lastChar at the end of the line
        } else {
            lastChar = c;
        }
    }
}

int main() {
    removeComments();
    return 0;
} */

#define MAXSTR 10000
#define TRUE (1 == 1)
#define FALSE !TRUE

// exerc Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences and comments. 
#define YES                    1
#define NO                     0  

/* globals */
int leftParens = 0;
int rightParens = 0;
int leftBrackets = 0;
int rightBrackets = 0;
int leftBraces = 0;
int rightBraces = 0;

/* functions */
void printInfo();
int  skipChar(int);
void checkSymbolsBallance(void);
void countSymbols(void);
int  skipComment(int);
int  skipQuote(int);

/* skipChar: skips n characters in the input stream */
int skipChar(int n)
{
	int c;

	while (n--)
		c = getchar();
	return c ;
}

/* skipComment: skip characters in the input stream until encountered the
 * ending symbol of a c-style comment */
int skipComment(int c)
{
	int stop = NO;

	while (stop == NO && (c = getchar()) != EOF)
		if (c == '*' && (c = getchar()) == '/')
			stop = YES;
	return c;
}

/* skipComment: skip characters in the input stream until encountered the
 * ending character of a c-style quote (single or double) */
int skipQuote(int type)
{
	int c, stop = NO, step = 2;

	while (stop == NO && (c = getchar()) != EOF) {
		if (c == '\\')
			c = skipChar(step);
		if (c == type)
			stop = YES;
	}
	return c;
}

/* countSymbols: count c-style demarcating symbols for comments and quote */
void countSymbols(void) {
	extern int leftParens, rightParens, leftBrackets, rightBrackets,
		       leftBraces, rightBraces;
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '/' && (c = getchar()) == '*') /* skip comments */
			c = skipComment(c);
		if (c == '"')  /* skip double quotes */
			c = skipQuote(c);
		if (c == '\'') /* skip single quotes */
			c = skipQuote(c);
		if (c == '(')
			++leftParens;
		if (c == ')')
			++rightParens;
		if (c == '[')
			++leftBrackets;
		if (c == ']')
			++rightBrackets;
		if (c == '{')
			++leftBraces;
		if (c == '}')
			++rightBraces;
	}
}

/* checkSymbolsBallance: check if number of c-style demarcating symbols for
 * comments and quotes are balanced. Print an error message if not. */
void checkSymbolsBallance(void)
{
	extern int leftParens, rightParens, leftBrackets, rightBrackets,
		       leftBraces, rightBraces;

	if (leftParens - rightParens < 0)
		printf("Error: missing '('\n");
	else if (leftParens - rightParens > 0)
		printf("Error: missing ')'\n");
	if (leftBrackets - rightBrackets < 0)
		printf("Error: missing '['\n");
	else if (leftBrackets - rightBrackets > 0)
		printf("Error: missing ']'\n");
	if (leftBraces - rightBraces < 0)
		printf("Error missing '{'\n");
	else if (leftBraces - rightBraces > 0)
		printf("Error missing '}'\n");
}

/* printInfo: print the number of demarcating symbols for comments and quotes */
void printInfo(void)
{
	extern int leftParens, rightParens, leftBrackets, rightBrackets,
		       leftBraces, rightBraces;

	printf("'(': %i ')': %i Total: %i\n",
			leftParens, rightParens, leftParens + rightParens);
	printf("'[': %i ']': %i Total: %i\n",
			leftBrackets, rightBrackets, leftBrackets + rightBrackets);
	printf("'{': %i '}': %i Total: %i\n",
			leftBraces, rightBraces, leftBraces + rightBraces);
}

int main(void)
{
	countSymbols();
	printInfo();
	checkSymbolsBallance();
	return 0;
}

/* 
int get_str(char str[], int limit);
void check_syntax(char str[]);

int main(void)
{
  char str[MAXSTR];

  get_str(str, MAXSTR);
  check_syntax(str);

  return 0;
}

int get_str(char str[], int limit)
{
  int c, i = 0;

  while (i < limit - 1 && (c = getchar()) != EOF)
  {
    str[i++] = c;
  }
  str[i] = '\0';

  return i;
}

void check_syntax(char str[])
{
  int parentheses = 0;
  int brackets = 0;
  int braces = 0;

  int single_quotes = FALSE;
  int double_quotes = FALSE;

  int block_comment = FALSE;
  int line_comment = FALSE;

  int i = 0;
  while (str[i] != '\0' && parentheses >= 0 && brackets >= 0 && braces >= 0)
  {
    if (!line_comment && !block_comment && !single_quotes && !double_quotes)
    {
      if (str[i] == '(')
      {
        ++parentheses;
      }
      else if (str[i] == ')')
      {
        --parentheses;
      }

      if (str[i] == '[')
      {
        ++brackets;
      }
      else if (str[i] == ']')
      {
        --brackets;
      }

      if (str[i] == '{')
      {
        ++braces;
      }
      else if (str[i] == '}')
      {
        --braces;
      }
    }

    if (!line_comment && !block_comment)
    {
      if (str[i] == '\'' && !single_quotes && !double_quotes)
      {
        single_quotes = TRUE;
      }
      else if (single_quotes && str[i] == '\'' && (str[i - 1] != '\\' || str[i - 2] == '\\'))
      {
        single_quotes = FALSE;
      }

      if (str[i] == '"' && !single_quotes && !double_quotes)
      {
        double_quotes = TRUE;
      }
      else if (double_quotes && str[i] == '"' && (str[i - 1] != '\\' || str[i - 2] == '\\'))
      {
        double_quotes = FALSE;
      }
    }

    if (!single_quotes && !double_quotes)
    {
      if (str[i] == '/' && str[i + 1] == '*' && !line_comment)
      {
        block_comment = TRUE;
      }
      else if (str[i] == '*' && str[i + 1] == '/')
      {
        block_comment = FALSE;
      }

      if (str[i] == '/' && str[i + 1] == '/' && !block_comment)
      {
        line_comment = TRUE;
      }
      else if (str[i] == '\n')
      {
        line_comment = FALSE;
      }
    }

    ++i;
  }

  if (parentheses)
  {
    printf("Error: unbalanced parentheses.\n");
  }

  if (brackets)
  {
    printf("Error: unbalanced brackets.\n");
  }

  if (braces)
  {
    printf("Error: unbalanced braces.\n");
  }

  if (single_quotes)
  {
    printf("Error: unbalanced single quotes.\n");
  }

  if (double_quotes)
  {
    printf("Error: unbalanced double quotes.\n");
  }

  if (block_comment)
  {
    printf("Error: block comment not closed.\n");
  }
} */
