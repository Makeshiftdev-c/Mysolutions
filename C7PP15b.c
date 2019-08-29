#include <stdio.h>

int main(void)
{
	int i, j, sum = 1;
	
	printf("Enter a postive integer: ");
	scanf("%d", &i);
	
	for (j = i; j > 0; j--)
	{
		sum *= j;
	}
	
	printf("Factorial of %d: %d", i, sum);
	
	return 0;
}

/* The largest value of n for which the program correctly prints the factorial of n is 12 */
