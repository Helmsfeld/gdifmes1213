/* Program: add.c
 * Description: This program reads two lines of binary numbers, of length
 *              <= 100 from stdin and prints the sum of these two numbers.
 * Author: Stefan Schuster
 * Date: 2012-11-14
 */

#include <stdio.h>
#include <string.h>

#define MAX_LEN 101

typedef char * string;

/* Return the maximum of a and b. */
size_t max(size_t a, size_t b) { return a<b ? b : a; }

/* String utils */

/* Reverse a string inplace. */
void reverse(string str)
{
    size_t i,j;
    for (i=0, j=strlen(str)-1; i<j; i++, j--) {
        char t=str[i];
        str[i] = str[j];
        str[j] = t;
    }
}

/* Trim leading zeroes from string s. */
void trim(string s)
{
    if (strlen(s) == 0
          || s[0] != '0')
        return;

    int i=0;
    /* Find index i with first occuring '1', if there is one. */
    while (s[i] != '\0' && s[i] != '1') i++;

    if (s[i] == '\0')
        /* There was no '1' but there is a leading '0'! *
         * So, simply set the string to "0" */
        s[1] = '\0';
    else {
        /* Otherwise, s[i] is the first '1', so now we shift. */
        int j=0;
        do { s[j++] = s[i++]; } while (s[i-1] != '\0');
    }
}


/* Assuming str is a string containing only '0' and '1',
 * return the integer value of the k-th digit, where
 * we count from the right (this is the place with value 2^k).
 * If k is larger than the length of the string, we return 0.
 */
int getKthDigit(string str, size_t k)
{
    size_t l = strlen(str);
    if (k >= l) return 0;
    return ((str[l-1-k]) - '0');
}

/* Assuming s1 and s2 to be two strings consisting only of '0' and '1',
 * compute the binary representation of their sum.
 */
void addStrings(string s1, string s2, string result)
{
    int c = 0, /* carry bit */
        s = 0; /* sum bit */
    size_t i;
    for (i=0; i<max(strlen(s1), strlen(s2)); i++) {
        int n1 = getKthDigit(s1, i);
        int n2 = getKthDigit(s2, i);
        s = n1+n2+c; /* s <= 3 */
        c = s/2; /* c <= 1 */
        /* 'result' will contain the string in reverse order. */
        result[i] = '0'+s%2;
    }
    if (c == 1)
        result[i++] = '1';
    result[i] = '\0';
    reverse(result);
    trim(result);
}

int main(void)
{
	char s1[MAX_LEN], s2[MAX_LEN], r[MAX_LEN+1];
	/* Read first line */
	scanf("%s", s1);
	/* Read second line */
	scanf("%s", s2);

	addStrings(s1, s2, r);
	printf("%s\n", r);
}
