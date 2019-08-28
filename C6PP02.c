/*Name: Abdirisak Arr
 *Date: 08/08/2019
 *Description: Asks user to enter two integers, then calculates and displays their greatest common divisor (GCD)
*/

#include <stdio.h>

int main(void)
{
	int n, m, remainder, gcd;
	
	printf("Enter two integers: ");
	scanf("%d %d", &n, &m);
	
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
	
	printf("Greatest common divisor: %d", gcd);
	
	return 0;
}
