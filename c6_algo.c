#include <stdio.h>

struct point makepoint(int, int);

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

struct point middle;
struct rect screen;

// make a point from x and y components
struct point makepoint(int x, int y) {
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

// add two points
struct point addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

// return 1 if p in r, 0 if not
int ptinrect(struct point p, struct rect r) {
    return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

// canonicalize coordinates of rectangle
struct rect canonrect(struct rect r) { 
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    return temp;
}


struct point *pp;
struct point origin, *pp;



struct rect r, *rp = &r; // r.pt1.x == rp->pt1.x == (r.pt1).x == (rp->pt1).x

struct {
    int len;
    char *str;
} *p;
// ++p->len   (incrementa o len, e não o p; é o mesmo que ++(p->len) )
// (++p)->len (incrementa o p antes de acessar o len)
// (++p)->len (incrementa o p após acessar o len)
// *p->str++   (busca qualquer str apontado)
// (*p->str)++ (qualquer str apontado)
// *p++->str (incrementa    o p após acessar qualquer str)

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab/ sizeof keytab[0])

struct key
{
    char *word;
    int count;
};


int getword(char *, int);
int binsearch(char *, struct key *, int);

// exerc 6.1:
// NOTE: run: ./count_c_keywords < count_c_keywords.c

void skip_blanks();
void skip_comments();
void skip_chars_between(char start, char end);
void skip_char_literal();
void skip_string_literal();


struct key keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    {"do", 0},
    {"double", 0},
    {"else", 0},
    {"enum", 0},
    {"extern", 0},
    {"float", 0},
    {"for", 0},
    {"goto", 0},
    {"if", 0},
    {"int", 0},
    {"long", 0},
    {"register", 0},
    {"return", 0},
    {"short", 0},
    {"signed", 0},
    {"size_t", 0},
    {"sizeof", 0},
    {"static", 0},
    {"struct", 0},
    {"switch", 0},
    {"typedef", 0},
    {"union", 0},
    {"unsigned", 0},
    {"void", 0},
    {"volatile", 0},
    {"while", 0},
};

void skip_blanks() {
    int c;
    while (isblank(c = getc(stdin)))
        ;
    ungetc(c, stdin);
}

void skip_comments() {
    int c = getc(stdin);
    if (c == '/')
    {
        c = getc(stdin);
        if (c == '/')
        {
            while ((c = getc(stdin)) != '\n' && c != EOF)
                ;
        }
        else if (c == '*')
        {
            while ((c = getc(stdin)) != '*' && c != EOF)
                ;
            c = getc(stdin);
            if (c == '/') { 
                ungetc('\n', stdin);
                return;
            }
        }
    }
    ungetc(c, stdin);
}

void skip_chars_between(char start, char end)
{
    int c = getc(stdin);
    if (c == start)
    {
        while ((c = getc(stdin)) != EOF)
        {
            if (c == '\\')
            {
                if ((c = getc(stdin)) == EOF)
                {
                break;
                }
            }
            else if (c == end)
            {
                return;
            }
        }
    }
    ungetc(c, stdin);
}

void skip_char_literal(void) {
    skip_chars_between('\'', '\'');
}

void skip_string_literal(void) {
    skip_chars_between('"', '"');
}

int getword(char *word, int lim) {
    skip_blanks();
    skip_comments();
    skip_char_literal();
    skip_string_literal();

    //int c, getch(void);
    //void ungetch(int);
    //char *w = word;
    //
    //while (isspace(c = getch()))
    //    ;
    //if (c != EOF)
    //    *w++ = c;
    //if (!isalpha(c)) {
    //    *w = '\0';
    //    return c;
    //}
    //for ( ; --lim > 0; w++)
    //    if (!isalphanum(*w = getch())) {
    //        ungetch(*w);
    //        break;
    //    }
    //*w = '\0';
    //return word[0];
    int c = getc(stdin);
    size_t i = 0;

    if (c != EOF) {
        word[i++] = c;
    }

    if (!isalpha(c) && c != '_') {
        word[i] = '\0';
        return c;
    }

    while ((isalnum(c = getc(stdin)) || c == '_') && i < max_word_len) {
        word[i++] = c;
    }
    ungetc(c, stdin);
    word[i] = '\0';

    return word[0];
}

int binsearch(char *word, struct key tab[], int n) {
    int cond;
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low+high)/2;
        if ((cond = strcmp(word, tab[mid].word))<0)
            high = mid - 1;
        else if (cond > 0)
            low = mid+1;
        else 
            return mid;
    }
    return -1;
}

struct key *binsearchp(char *word, struct key *tab, int n) {
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low < high) {
        mid = low + (high - low)/2;
        if ((cond = strcmp(word, mid->word))<0)
            high = mid;
        else if (cond > 0)
            low = mid+1;
        else 
            return mid;
    }
    return NULL;
}


#define NR_OF_TYPES sizeof(data_types) / sizeof(data_types[0])

struct tnode {          // the tree node:
    char *word;             // points to the text
    int count;              // number of occurrences
    struct tnode *left;     // left child
    struct  tnode *right;   // right child
}

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
struct tnode *talloc(void);
char *strdup(char *);

char *strdup(char *s) {     // make a duplicate of s
    char *p;

    p = (char *) malloc(strlen(s) + 1); // +1 for '\0'
    if (p != NULL) 
        strcpy(p, s);
    return p;
}
// make a tnode
struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

// in-order print of tree p 
void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count. p->word);
        treeprint(p->right);
    }
}



// add a node with w, at or beow p
struct tnode *addtree(struct tnode *p, char *w) {
    int cond;

    if (p == NULL) {    // a new word has arrived
        p = talloc();   // make a new node
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;     // repeated word
    else if (cond < 0)  // less than into left subtree
        p->left = addtree(p->left, w);
    else            // greater than into right subtree
        p->right = addtree(p->right, w);
    return p
}


int main(void) {
    //screen.pt1 = makepoint(0, 0);
    //// screen.pt2 = makepoint(XMAX, YMAX);
    //screen.pt2 = makepoint(320, 200);
    //middle = makepoint((screen.pt1.x + screen.pt2.x) / 2, (screen.pt1.y + screen.pt2.y) / 2);
    //
    //pp = &origin;
    ////printf("origin is (%d, %d)\n", (*pp).x, (*pp).y);   
    //printf("origin is (%d, %d)\n", pp->x, pp->y);


    //int n;
    //char word[MAXWORD];
    //
    //// pointer version : p->count em vez de keytab[n].count e p = keytab; p < keytab + NKEYS; p++ no for
    //struct key *p;
    //
    //while (getword(word, MAXWORD) != EOF) {
    //    if (isalpha(word[0]))
    //        if ((n = binsearch(word, keytab, NKEYS)) >= 0)
    //            keytab[n].count++;
    //} for (size_t i = 0; i < NKEYS; ++i)
    //    if (keytab[i].count)
    //        printf("%4d %s\n", 
    //            keytab[i].count, keytab[i].word);
    
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF) 
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
}