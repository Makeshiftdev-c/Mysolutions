/*Name: Abdirisak Arr
 *Date: 09/08/2019
 *Description: Prompts user to enter integer and reverses the input
*/

#include <stdio.h>

int main(void)
{
	int i, count = 1, n, j = 0, n2;
	
	printf("Enter an integer: ");
	scanf("%d", &i);
	
	printf("The reverse is ");
	
	n2 = i;
	while (n2 > 0) //determines order of magnitude of entry
		{
			count *= 10;
			n2 /= 10;
		}
    
	do
	{
		count /= 10;
		n = i % 10;
		j = j + (n * count);
		i /= 10;
	} while (i != 0);
	
	printf("%d", j);
	
	return 0;
}
