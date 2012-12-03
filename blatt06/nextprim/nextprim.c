/* *****************************************************************************
 * Program: nextprim.c
 * Description: Reads natural numbers per stdin and computes
 *              for each given number n the smallest prime p
 *              with p>n.
 *              The range of the input is assumed to be unsigned long
 * Autor: Wilfried Elmenreich, Stefan Schuster
 * Date:  14.11.2012
 *
 * ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

/* Function isprim.
 * Check, if x is prime.
 * In:  x: Number to be checked.
 * Out: 1 if x is prime, 0 otherwise.
 */
int isprim(unsigned long x) {
    unsigned long i;
    if (x<2) return 0;
    if (x==2 || x==3) return 1;
    if (x%2==0) return 0;
    for (i=3; i*i<=x; i+=2)
        if (x%i==0) return 0;
    return 1;
}

/* Function nextprime.
 *
 * Find the next prime larger than the given number n.
 * In case of an overflow, 0 is returned.
 *
 * Note, that the largest gap between primes in the range 
 * between 0 and 2^32-1 is at prime p=3842610773, the next
 * prime beeing p+336. See also
 * http://en.wikipedia.org/wiki/Prime_gap
 *
 * In:  n: Number from where to look for next prime.
 * Out: The next prime strictly larger than n. 
 *      0 if there is no prime in the range unsigned long.
 */
unsigned long nextprime(unsigned long n)
{
    while (++n != 0 && ! isprim(n))
        ; /* Do nothing */ 
    /* n is now either 0 or the next prime we look for. */
    return n;
}

int main(int argc, char **argv) {
    char buf[100];
    while (fgets(buf,sizeof(buf),stdin)!=NULL) {
        unsigned long x,res;
        if (feof(stdin)) exit(0);
        if (ferror(stdin)) exit(1);
        x = strtoul(buf, NULL, 10);
        res = nextprime(x);
        if (res==0)
            printf("There is no prime larger than %lu and smaller than %lu.\n",
                   x, ULONG_MAX);
        else
            printf("%lu\n", res);
    }
    return 0;
}
