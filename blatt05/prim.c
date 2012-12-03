#include <stdio.h>
#include <stdlib.h>

/* ****************************************************************************
 * Program: prim.c
 * Description: Reads non-negative integers from stdin
 *              tests, if a given number is prime or not and
 *              outputs "prim!" or "nicht prim!", respectively.
 *              This is an optimized version, cf. prim_slow.c, which
 *              demonstrates, how even moderate optimizations can speed up
 *              the whole computation.
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

int isprim(unsigned long x) {
    unsigned long i;
    if (x<2) return 0;
    if (x==2 || x==3) return 1;
    if (x%2 == 0) return 0;
    
    for (i=3; i*i<=x; i+=2)
        if (x % i ==0) return 0;
    return 1;
}

int main(int argc, char **argv) {
    char buf[100];
    
    while (fgets(buf,sizeof(buf),stdin)!=NULL) {
       unsigned long x;
       if (feof(stdin)) exit(0);
       if (ferror(stdin)) exit(1);
       x = atol(buf);
       if (isprim(x))
         printf("prim!\n");
       else
         printf("nicht prim!\n");
    }
    return 0;
}
