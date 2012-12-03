/* Program:     binweight.c
 * Description: The binary weight of a natural number is defined
 *              as the number of '1's in its binary representation.
 *              The program reads natural numbers from stdin
 *              and computes their binary weight.
 *              The natural numbers are assumed to be given
 *              in decimal representation, the allowed range
 *              is 'unsigned int'.
 * Author:      Stefan Schuster
 * Date:        2012-11-26
 */

#include <stdio.h>
#include <limits.h>

/* Function binweight.
 * Compute the binary weight of n.
 *
 * The algorithm directly follows the well known conversion procedure
 * 'decimal -> 'binary' given in the lectures, which repeatedly computes the
 * remainders 'mod 2' and divides then by 2, denoting the remainders.
 *
 * In:  n: The natural number to compute the binary weight from.
 * Out: The binary weight of n. */
unsigned int binweight(unsigned int n)
{
    unsigned int weight = 0;
    while (n != 0) {
        weight += n%2;
        n /= 2;
    }
    return weight;
}

int main(int argc, char **arcv)
{
    unsigned int n;
    while (scanf("%u", &n) != EOF) {
        printf("%u\n", binweight(n));
    }
    return 0;
}
