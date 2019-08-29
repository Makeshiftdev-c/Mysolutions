#include <stdio.h>

int main(void)
{
	int i, j;
	double sum = 1.00;
	
	printf("Enter a positive integer: ");
	scanf("%d", &i);
	
	for (j = i; j > 0; j--)
	{
		sum *= j;
	}
	
	printf("Factorial of %d: %lf", i, sum);
	
	return 0;
}

/* The largest value of n for which the program correctly prints the factorial of n is 170 */

