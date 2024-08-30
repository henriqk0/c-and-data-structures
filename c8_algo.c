#include <stdio.h>
#include <fcntl.h>
/*
#include <syscall.h>


// 0, 1 e 2 -> stdin, stdout e stderr (escritos no arquivo para execução)

// redirecionamento entrada e saída (no terminal)
// prog <infile >outfile


// file descriptor. buffer do arquivo (armazenamento), numero de bytes a ser transferido
// int n_read = read(int fd, char *buf, int n);
// int n_written = write(int fd, char *buf, int n);

// unbuffered single char input
int getcharub(void) {
    char c;

    return (read(0, &c, 1) == 1) ? (unsigned char) c: EOF;  // c deve ser um char, pelo read necessita um ponteiro de caractere (&c = apontando para o endereço de c)
}

// simple buffered version
int getcharb(void) {
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;

    if (n==0) { // buffer está vazio
        n = read(0, buf, sizeof buf);
        bufp = buf;
    }
    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}


int main(void) { // copia o input no output
    char buf[BUFSIZ];
    int n;

    while ((n = read(0, buf, BUFSIZ)) > 0) {
        write(1, buf, n);
    } return 0;
}*/

#include <string.h>     //flags for read and write
#include <sys/types.h>  //typedefs
#include <sys/stat.h>   //structure returned by stat

#include <stdarg.h>
#include "dirent.h"
#include "syscall.h"

#define PERMS 0666  // RW for owner, group, others

void error(char *, ...);

void error(char *fmt, ...) {
    va_list args;

    va_start(args, fmt);
    fpritnf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}

//lseek(fd , 0L, 0); // trata arquivos de maneira similar a como trata os arrays longos, pelo preço de um acesso mais lento

// stdlib - descrita por ponteiros de arquivos em vez de descriptores de arquivo

// 20 é o número máximo de arquivos abertos de uma vez

#define MAX_PATH 1024
void fsize(char *);
void dirwalk(char *, void (*fcn)(char *));
int stat(char *, struct stat *);

// apply fnc to all files in dir
void dirwalk(char *dir, void (*fcn)(char *)) {
    char name[MAX_PATH];
    DIR *dfd;
}

// print size of file "name"
void fsize(char *name) {
    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't acess %s\n", name);
        return;
    } 
    if ((stbuf.st_mode & __S_IFMT) == __S_IFDIR)
        dirwalk(name, fsize);
    printf("%8ld %s\n", stbuf.st_size, name);
}

int main(int argc, char *argv[]) {
    // copy f1 to f2
    //int f1, f2, n;
    //char buf[BUFSIZ];
    //
    //if (argc != 3) 
    //    error("Usage: copy from to");
    //if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
    //    error("cop: cant open %s", argv[1]);
    //if ((f2 = creat(argv[2], PERMS)) == -1)
    //    error("cop: can't create %s, mode %03o", argv[2], PERMS);
    //while ((n = read(f1, buf, BUFSIZ)) > 0) 
    //    if (write(f2, buf, n) != n)
    //        error("cop: write error on file %s", argv[2]);
    //return 0;

    //print file sizes
    if (argc == 1 ) //current directory
        fsize(".");
    else
        while (--argc > 0)
            fsize(*++argv);
    return 0;
}







