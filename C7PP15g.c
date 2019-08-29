#include <stdio.h>

int main(void)
{
	int i, j;
	long double sum = 1.00;
	
	printf("Enter a positive integer: ");
	scanf("%d", &i);
	
	for (j = i; j > 0; j--)
	{
		sum *= j;
	}
	
	printf("Factorial of %d: %Lf", i, sum);
	
	return 0;
}

