#include <stdio.h>
#include <time.h>
int ePrimo(int n)
{
    for( int i = 2; i<=n/2; i++){
        if (!(n%i)) { // tem divisor -> não será somado
            return 0;
        }
    } return 1;
}

void main() 
{
    int numPrimos = 0;
    time_t segs;

    segs = time(NULL);
    for (int i=2; i<250001; i++) {
        numPrimos += ePrimo(i);
    } printf("%d\n", numPrimos);
    printf("%ld segundos\n", time(NULL)-segs);
}

