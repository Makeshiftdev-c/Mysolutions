#include <stdio.h>

int main(void)
{
	int i, j;
	float sum = 1.00f;
	
	printf("Enter a positive integer: ");
	scanf("%d", &i);
	
	for (j = i; j > 0; j--)
	{
		sum *= j;
	}
	
	printf("Factorial of %d: %f", i, sum);
	
	return 0;
}

/* The largest value of n for which the program correctly prints the factorial of n is 34 */
