#include <stdio.h>

int main(void)
{
	int i, j;
	long long int sum = 1;
	
	printf("Enter a positive number: ");
	scanf("%d", &i);
	
	for (j = i; j > 0; j--)
	{
		sum *= j;
	}
	
	printf("Factorial of %d: %lld", i, sum);
	
	return 0;
}

/* The largest value of n for which the program correctly prints the factorial of n is 20 */
