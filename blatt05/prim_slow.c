#include <stdio.h>
#include <stdlib.h>
/* ****************************************************************************
 * Program: prim_slow.c
 * Description: Reads non-negative integers from stdin
 *              tests, if a given number is prime or not and
 *              outputs "prim!" or "nicht prim!" respectively.
 *              This is a naive implementation that demonstrates
 *              how long it may take to check larger primes, see
 *              the examples below.
 *
 * Autor: Wilfried Elmenreich, Stefan Schuster
 * Date:  14.11.2012
 *
 * recommended test cases:
 * 0 (n)
 * 1 (n)
 * 2 (p)
 * 399999959 (p)
 * 2147483647 (p)
 * 4293001441 (n)
 * ***************************************************************************/

int isprim_slow(unsigned long x) {
    unsigned long i;
    if (x<2) return 0;
    for (i=2; i<x; i++)
        if (x%i == 0) return 0;
    return 1;
}

int main(int argc, char **argv) {
    char buf[100];
    while (fgets(buf,sizeof(buf),stdin)!=NULL) {
        unsigned long x;
        if (feof(stdin)) exit(0);
        if (ferror(stdin)) exit(1);
        x = atol(buf);
        if (isprim_slow(x))
            printf("prim!\n");
        else
            printf("nicht prim!\n");
    }
    return 0;
}
