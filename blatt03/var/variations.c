/* *************************************************************
 * Program: variationen
 * Author: Wilfried Elmenreich
 *
 * Calculates the number of k-permutations (german "Variationen") without 
 * repetition according to formula v = n! / (n - k)!
 * 
 * Input: read from stdin: n k (both integer numbers)
 * Output: number of k-permutations printed to stdout
 * ************************************************************* */

#include <stdio.h>
#include <stdlib.h>

void error_exit(char *errormsg) {
    fprintf(stderr,"%s",errormsg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    long n,k;
    long i;
    long v; /* the result */
    
    if (scanf("%ld %ld",&n,&k) != 2)
        error_exit("Wrong input!");
    if (n<=0 || k<=0 || k>n)
        error_exit("Numbers must be positive, k must not be larger than n!");
    
    v=1;
    for (i=n-k+1; i<=n; i++)
        v*=i;
    
    printf("%ld\n",v);
    return 0;
}

