/*Name: 
 *Date: 09/08/2019
 *Description: Prompts user to enter a number n, then prints all even squares between 1 and n
*/

#include <stdio.h>

int main(void)
{
	int i = 2, n;
	
	printf("Enter a number n: ");
	scanf("%d", &n);
	
	printf("Even squares between 1 and n are:\n");
	while ((i*i) <= n)
	{
		printf("%d\n", i*i);
		i += 2;
	}
	
	return 0;
}
