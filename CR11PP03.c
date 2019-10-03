/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 03/10/2019                                          *
* Description: Modification of Programming Project 3 from   *
*              Chapter 6 with the addition of the function: *
*                void reduce(int numerator, int denominator,*
*                            int *reduced_numerator,        *
*                            int *reduced_denominator);     *
*************************************************************/

#include <stdio.h>

/* prototype */
void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

/************************************************************
* main: Prompts for and reads user input; calls reduce;     *
*       outputs simplified user input.                      *
*************************************************************/

int main(void)
{
	int top, bottom, reduced_top, reduced_bottom;
	
	printf("Enter a fraction: ");
	scanf("%d/%d", &top, &bottom);
	
	reduce(top, bottom, &reduced_top, &reduced_bottom);
	
	printf("In lowest terms: ");
	/* handles special case */
	if (reduced_bottom == 0)
	{
		printf("Undefined expression");
	}
	/* normal execution */
	else
	{
		printf("%d/%d", reduced_top, reduced_bottom);
	}
	
	return 0;
}

/************************************************************
* reduce: Simplifies fractions using Euclid's algorithm     *
*************************************************************/

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
	/* handles special case */
	if (denominator == 0)
	{
		*reduced_numerator = 0;
		*reduced_denominator = 0;
		return;
	}
	
	/* Euclid's algorithm */
	int n = numerator, m = denominator, remainder, gcd;
	
	for (;;)
	{
		if (n == 0)
		{
			gcd = m;
			break;
		}
		else
		{
			remainder = m % n;
			m = n;
			n = remainder;
		}
	}
	
	/* passes results to function arguments */
	*reduced_numerator = numerator / gcd;
	*reduced_denominator = denominator / gcd;
}
