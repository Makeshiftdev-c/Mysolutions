/*Name:
 *Date: 09/08/2019
 *Description: Square3.c with for loops that initialises, tests, and increments i
*/

#include <stdio.h>

int main(void)
{
	int i, n, odd, square;
	
	printf("Enter number of entries in the table: ");
	scanf("%d", &n);
	
	odd = 3;
	for (i = 1, square = 1; i <= n; ++i, odd += 2)
	{
		printf("%10d%10d\n", i, square);
		square += odd;
	}
	
	return 0;
}
