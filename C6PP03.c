/*Name: Abdirisak Arr
 *Date: 08/08/2019
 *Description: Asks user to enter a fraction, then reduces the fraction to the lowest terms
*/

#include <stdio.h>

int main(void)
{
	int numer, denom, n, m, remainder, gcd;
	
	printf("Enter a fraction: ");
	scanf("%d/%d", &numer, &denom);
	
	n = numer;
	m = denom;
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
	
	numer /= gcd;
	denom /= gcd;
	
	printf("In lowest terms: %d/%d", numer, denom);
	
	return 0;
}
