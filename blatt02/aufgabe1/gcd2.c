/***
 * Program:     gcd2.c
 * Description: Solution for second problem set, problem 1, gcd with input.
 *              The file reads pairs of integers from stdin.
 *              For each pair read, the output consists of one line containing 
 *              the gcd of the respective numbers.
 * Author:      Stefan Schuster
 * Date:        2012-10-26
 */

#include <stdio.h>


/***
 * Function gcd
 * Compute and return the greatest common divisor (gcd) of two
 * positive integers using the euclidean algorithm.
 * In: p, q: The integers of which we compute the gcd.
 * Returns: The gcd of p and q if p>0 and q>0. Otherwise -1 is returned.
 */
int gcd(int a, int b);

int main(void)
{
    int p, q;
    while (scanf("%d %d\n", &p, &q ) == 2)
    {
        printf( "%d\n", gcd(p, q) );
    }
    return 0;
}

/* Compute and return the greatest common divisor (gcd) of two
 * positive integers using the euclidean algorithm. */
int gcd(int a, int b)
{
    /* Remainder of integral division */
    int r;
    
    /* If a or b is not positive, the return value was
     * specified to be -1. */
    if ( a<=0 || b<=0 )
    {
        return -1;
    }
    /* Now execute the euclidean algorithm.
     *  [Note: Even though '!= 0' is not strictly necessary,
     *   if we add it, it becomes clearer what we mean.] */
    while ((r=a%b) != 0)
    {
        a = b;
        b = r;
    }
    return b;
}

