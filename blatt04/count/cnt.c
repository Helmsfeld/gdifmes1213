/***
 * Progam: cnt.c 
 * Description: Read text from stdin and find the printable characters
 *              with maximum number of occurrences. We assume, that the
 *              text contains ANSI characters only.
 * Author: Stefan Schuster
 * Date: 2012-11-10
 */

#include <stdio.h>
#include <string.h>

#define MAX_ARR_SIZE 256

int main(void)
{
	char currentChar;
	char charCount[MAX_ARR_SIZE];
	int i, max, notFirst;
	memset(charCount, 0, sizeof(charCount));

	while ((currentChar = getchar()) != EOF)
	{
		/* Since we deal with ASCII only, we make
		 * our life ease and just look, if the ASCII code is
		 * larger than the code of ' ' (space, 32), which is the first
		 * printable but non-visible character. All characters
		 * with larger ASCII code are printable. */
		if ((int)currentChar > 32)
			charCount[(int)currentChar]++;
	}
	/* Find maximum number of occurences of a character. */
	max = 0;
	for (i=0; i<MAX_ARR_SIZE; i++)
		if (charCount[i] > max)
			max = charCount[i];
	notFirst = 0;
	for (i=33; i<MAX_ARR_SIZE; i++)
	{		
		if (charCount[i] == max)
		{
			if (notFirst)
				printf(",");
			printf("%c", (char)i);
			notFirst = 1;
		}
	}
	printf(":%d\n", max);
	return 0;
}
