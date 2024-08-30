#include <stdio.h>
#include <ctype.h>

/* #include <string.h>

//if program name starts with '.', parse it, i.e. trim the full pathname and return name only, otherwise return name as is
char *parsename(char *name) {
    return name[0] == '.' ? strrchr(name, '/') + 1: name;
}

int main(int argc, char *argv[]) {
    int c;
    int (*func)(int);   // function pointer to tolower or toupper
    char *prog;         // program name

    --argc;
    prog = parsename(argv[0]);
    if (!strcmp("tolower", prog))
        func = tolower;
    else if (!strcmp("toupper", prog))
        func = toupper;
    else {
        printf("Error: rename program to tolower or toupper\n")
        return -1;
    }
    while ((c = getchar()) != EOF) {
        putchar(func(c));
    } return 0;
} */

/* #define MAXLEN 100
#define NCHAR 6     // number of actually printed characters

// increment line's length by the number of actually printed characters. Break the line if its too long.
int inclen(int len, int n) {
    if ((len += n) < MAXLEN) 
        return len;
    printf("\n");
    return n;
}

int main(void) {
    int c;
    int len;    // length of currently read line  

    len = 0;
    while ((c = getchar()) != EOF) {
        if (!isgraph(c)) {
            printf(" 0x%02o", c);   // replace by NCHAR hex characters
            len = inclen(len, NCHAR);
            if (c == '\n') {
                printf("\n");       //break the line
                len = 0;
            }
        } else { // graphical character
            printf("%c", c);
            len = inclen(len, 1);
        }
    } return 0;
} */


#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#define MAXNUMB 20
#define FLT_PRCISION 6
#define FIELD_WIDTH 1

#define PRINT_N(la, x, w, v, nc) (la) ? (nc += printf("%-*" # x, w, v)) : (nc += printf("%*" # x, w, v))
#define PRINT_D(la, x, w, p, v, nc) (la) ? (nc += printf("%-*.*" # x, w, p, v)): (nc += printf("%*.*" # x, w, p, v))

int minprintf(char *, ...);

// minimal printf with variable argument list
int minprintf(char *fmt, ...) {
    va_list ap;   // points to each unnamed arg in turn
    char *p, *sval, number[MAXNUMB];
    int ival, i, width, precision, nchar = 0;
    double dval; 
    unsigned uval;
    void *pval;
    int leftAdjust, *pival;

    va_start(ap, fmt);

    for (p = fmt; *p; p++) {

		if (*p != '%') {
			putchar(*p);
			++nchar;
			continue;
		}

		leftAdjust = 0;
		width = 1;
		precision = -1;

		if (*++p == '-') {
			leftAdjust = 1;            // left adjust 
			++p;
		}

		if (isdigit(*p)) {             // get width 
			for (i = 0; isdigit(*p) && i < MAXNUMB; i++)
				number[i] = *p++; 
			number[i] = '\0';
			width = atoi(number);
		}
		if (*p == '.') {               
			++p;
			for (i = 0; isdigit(*p) && i < MAXNUMB; i++) // get precision pts 
				number[i] = *p++; 
			number[i] = '\0';
			precision = atoi(number);
		}

		switch (*p) {
		case 'd':
			ival = va_arg(ap, int);
			PRINT_N(leftAdjust, d, width, ival, nchar);
			break;
		case 'i':
			ival = va_arg(ap, int);
			PRINT_N(leftAdjust, i, width, ival, nchar);
			break;
		case 'o':
			uval = va_arg(ap, int);
			PRINT_N(leftAdjust, o, width, uval, nchar);
			break;
		case 'x':
			uval = va_arg(ap, int);
			PRINT_N(leftAdjust, x, width, uval, nchar);
			break;
		case 'X':
			uval = va_arg(ap, int);
			PRINT_N(leftAdjust, X, width, uval, nchar);
			break;
		case 'u':
			uval = va_arg(ap, int);
			PRINT_N(leftAdjust, u, width, uval, nchar);
			break;
		case 'c':
			ival = va_arg(ap, int);
			PRINT_N(leftAdjust, c, width, ival, nchar);
			break;
		case 's':
			sval = va_arg(ap, char *);
			if (precision < 0)
				precision = strlen(sval);
			PRINT_D(leftAdjust, s, width, precision, sval, nchar);
			break;
		case 'f':
			dval = va_arg(ap, double);
			if (precision < 0)
				precision = FLT_PRCISION;
			PRINT_D(leftAdjust, f, width, precision, dval, nchar);
			break;
		case 'e':
			dval = va_arg(ap, double);
			if (precision < 0)
				precision = FLT_PRCISION;
			PRINT_D(leftAdjust, e, width, precision, dval, nchar);
			break;
		case 'E':
			dval = va_arg(ap, double);
			if (precision < 0)
				precision = FLT_PRCISION;
			PRINT_D(leftAdjust, E, width, precision, dval, nchar);
			break;
		case 'g':
			dval = va_arg(ap, double);
			PRINT_N(leftAdjust, g, width, dval, nchar);
			break;
		case 'G':
			dval = va_arg(ap, double);
			PRINT_N(leftAdjust, G, width, dval, nchar);
			break;
		case 'p':
			pval = va_arg(ap, void *); 
			PRINT_N(leftAdjust, p, width, pval, nchar);
			break;
		case 'n':
			pival = va_arg(ap, int *);
			*pival = nchar;
			break;
		default:
			putchar(*p);
			++nchar;
			break;
		}
	}
	va_end(ap);                        // clean up when done 
	return nchar;
}

int minscanf(char *fmt, ...) {
	va_list ap;
	char *p, *sval, *cval;
	int *ival;
	float *fval;
	unsigned fval;
	int nchar = 0;

	va_start(ap, fmt) 	// make ap point to 1st unnamed arg
	for (p = fmt; *p; p++) {
		if (*p != '%') 
			continue;
		
		switch (*++p) {
		case 'd':
			ival = va_arg(ap, int *);
			nchar += scanf("%d", ival);
			break;
		case 'i':
			ival = va_arg(ap, int *);
			nchar += scanf("%i", ival);
			break;
		case 'o':
			uval = va_arg(ap, unsigned *);
			nchar += scanf("%u", uval);
			break;
		case 'c':
			cval = va_arg(ap, char *);
			nchar += scanf("%c", cval);
			break;
		case 's':
			sval = va_arg(ap, char *);
			nchar += scanf("%s", sval);
			break;
		case 'e':
			fval = va_arg(ap, float *);
			nchar += scanf("%e", fval);
			break;
		case 'f':
			fval = va_arg(ap, float *);
			nchar += scanf("%f", fval);
			break;
		case 'g':
			fval = va_arg(ap, float *);
			nchar += scanf("%g", fval);
			break;
		
		default:
			break;
		} 
		va_end(ap);
	} 
	return nchar;
}


/* int main(void)
{
	//minprintf("minprintf() output:\n");
	//minprintf("%s\n", "hello, world");
	//minprintf("%10s\n", "hello, world");
	//minprintf("%-10s\n", "hello, world");
	//minprintf("%.10s\n", "hello, world");
	//minprintf("%-15s\n", "hello, world");
	//minprintf("%.15s\n", "hello, world");
	//minprintf("%-15.10s\n", "hello, world");
	//minprintf("%15.10s\n", "hello, world");
	//
	//
	//printf("\n");	printf("printf() output:\n");
	//
	//printf("%10s\n", "hello, world");
	//printf("%s\n", "hello, world");
	//printf("%-10s\n", "hello, world");
	//printf("%.10s\n", "hello, world");
	//printf("%-15s\n", "hello, world");
	//printf("%.15s\n", "hello, world");
	//printf("%-15.10s\n", "hello, world");
	//printf("%15.10s\n", "hello, world");

	int day, year;
	char monthname[20];
	scanf("%d/%s/%d", &day, monthname, &year);		// (ou %d %s %d); mês sem o & por ser um array de caracteres, que é um ponteiro 


	// rudimentary calculator
	float sum, v;
	sum = 0;
	while (scanf("%1f", &v) == 1) 
		printf("\t%.2f\n", sum += v);
	return 0;
} */



#define MAXLEN 1000
#define MAXNAME 100

typedef struct { 
	char name[MAXNAME];	// file name
	FILE *fptr; 		// file pointer
	char line[MAXLEN];	// currently read line
	int lineno;			// number of read lines
} File
 
char *prog;		// program name (global)

void openfile(const char *, File *);
void comparefiles(File *, File *);

void openfile(const char *filename, File *file) {
	if (!(file->fptr = fopen(filename, "r"))) {
		fprintf(stderr, "%s: can't open %s\n", prog, filename);
	}
	strcpy(file->name, filename);
	*file->line = '\0';
	file->lineno = 0;
}

void comparefiles(File *f1, File *f2) {
	do {
		if (fgets(f1->line, MAXLEN, f1->fptr))
			++f1->lineno;
		if (fgets(f2->line, MAXLEN, f2->fptr))
			++f2->lineno;
		if (!feof(f1->fptr) && !feof(f2->fptr))	// are all there lines?
			if (strcmp(f1->line, f2->line)) // compare lines
				break;	// lines differ
	} while (!feof(f1->fptr) && !feof(f2->fptr));	// until either return EOF
	if (!feof(f1->fptr))
		fprintf(stdout, "\n%s:%i: %s", f1->name, f1->lineno, f1->line);
	if (!feof(f2->fptr))
		fprintf(stdout, "\n%s:%i: %s", f2->name, f2->lineno, f2->line);
}

// concatenate files
int main(int argc, char *argv[]) {
	//FILE *fp;
	//void filecopy(FILE *, FILE *);
	//char *prog = argv[0];	// prog name for errors
	//
	//if (argc == 1) filecopy(stdin, stdout);	// no args, copy standard input
	//
	//else {
	//	while (--argc > 0) {
	//		if ((fp = fopen(*++argv, "r")) == NULL) {
	//			fprintf(stderr, "%s: can't open %s\n", prog, *argv);
	//			exit(1);
	//		} else {
	//			filecopy(fp, stdout);
	//			fclose(fp);
	//		}
	//	}
	//} if (ferror(stdout)) {
	//	fprintf(stderr, "%s: error writing stdout\n", prog);
	//	exit(2);
	//}
	//exit(0);

	// exerc 7.6
	File file_1, file_2;

	prog = *argv++;		// program name for errors 

	if (--agrc != 2) {
		fprintf(stderr, "Usage: %s <file1> <file2>\n", prog);
		exit(EXIT_FAILURE);
	} 
	openfile(*agrv++, &file_1);
	openfile(*argv, &file_2);
	comparefiles(&file_1, &file_2);
	fclose(file_1.fptr);
	fclose(file_2.fptr);
	exit(EXIT_SUCCESS);
}