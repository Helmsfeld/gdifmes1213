/***
 * Program:     bunnies
 * Description: Solution for second problem set, problem 2, bunny population.
 *              Calculate the size of a bunny population after one year 
 *              according to certain rules. See the exercise sheet for the 
 *              exact formulation of the problem.
 *
 *              This exercise mainly demonstrates how important it is to 
 *              specify exactly what one wants...
 *
 *              The program reads lines containing one integer, the initial 
 *              population size. For each line read, its output is one line
 *              containing the bunny population after one year.
 *
 * Author:      Stefan Schuster
 * Date:        2012-10-26
 */

#include <stdio.h>

/* Compute the population size given the initial population size initialP. 
 * In: The initial population size initialP.
 * Returns: The population size after one year. */
int compPopulation(int initialP);

int main(void)
{
    int n;
    /* Read input from stdin. We do not care for errors. */
    while (scanf("%d", &n) == 1)
    {
        printf( "%d\n", compPopulation( n )  );
    }
    return 0;
}

/* Compute the population size given the initial population size initialP. */
int compPopulation(int initialP)
{
    /* Bunnies of different ages and a temporary bunny variable. */
    int b0, b15, b30, bTmp;
    /* Index for looping. */
    int i;
    
    /* Initially, all bunnies are >= 30d old. */
    b30 = initialP;
    b0 = b15 = bTmp = 0;
    
    /* Iterate the rules for 24 == (int)(365/15) times, ie., one year */
    for (i = 0; i<24; i++)
    {
        bTmp = b0;
        /* 10% of newborns die. */
        b0 = b30 * 0.9;
        /* Of those who mature, 30% leave. */
        b30 = b30 + b15*0.7;
        b15 = bTmp;
        /* And now, of all remaining bunnies 25% die of flue.  */
        b0 *= 0.75;
        b15 *= 0.75;
        b30 *= 0.75;
    }
    /* The total population consists of the newborns, 15 days old and
     * at least 30 days old bunnies. */
    return b0+b15+b30;
}

