/*** 
 * Program:     gcd1
 * Description: Example solution for 'Aufgabe 1, Blatt 1'.
 *              Implementation of the euclidean algorithm as given in the lecture.
 *              gcd1 computes and outputs the gcd of three given pairs of values.
 * Author:      Stefan Schuster
 * Date:        2012-10-16
 */

#include<stdio.h> 


/*** function gcd
 * Compute and return the greatest common divisor (gcd) of two
 * positive integers using the euclidean algorithm.
 * In:      p, q: The integers of which we compute the gcd.
 * Returns: The gcd of p and q.
 */

int gcd( int p, int q ) {
  // [Even if it is not required for this exercise,
  //  it is good style to care for all eventualities.
  //  We therefore take care of non-positive values, too.]
  if ( p <= 0 || q <= 0 ) return -1;
  int r = p%q;
  while ( r>0 ) {
    p = q;
    q = r;
    r = p%q;
  }
  return q;
}


int main() {
  // We call function gcd with these values es required.
  printf( "%d\n", gcd( 142, 18 ) );
  printf( "%d\n", gcd( 969, 627 ) );
  printf( "%d\n", gcd( 1071, 1029 ) );
  return 0;
}

