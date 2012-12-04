/***
 * Program:     revert.c
 * Description: 
 * Author:      Stefan Schuster
 * Date:        2012-11-02
 */

#include <stdio.h>
#include <string.h>

/* Number of characters to be stored in the char-arrays. */
#define MAX_LENGTH 80

/* Functon revert
 * Store the reverted string s in r.
 * In: s: Pointer to the string to be reverted, will not be altered.
 *     r: Pointer to the char-array that recieves the reverted s.
 */
void revert (const char *const s, char *r)
{
	int i, length;
	length = (int) strlen (s);
	for (i = 0; i<length; i++) {
		r[i] = s[length-i-1];
	}
	r[i] = '\0';
}

int main(void)
{
	char s[MAX_LENGTH+1], r[MAX_LENGTH+1];
	/* Read string s from stdin */
	while ( fgets(s, MAX_LENGTH+1, stdin ) != NULL  ) {
		/* If the last character of the string is a newline,
                 * remove the newline. */
		if ( s[strlen (s)-1] == '\n' ) {
			s[strlen (s)-1] = '\0';
		}
		/* Revert string. */
		revert (s, r);
		/* Output string. */
		printf ("%s\n", r);
	}
	return 0;
}
