/*Name: Abdirisak Arr
  Date: 30/07/2019
  Description: Program thats prompts user to enter two fractions and returns the unsimplified sum
*/

#include <stdio.h>

int main(void)
{
	int numer1, numer2, denom1, denom2;
	int numerator, denominator;
	
	printf("Enter two fractions separated by a plus sign: ");
	scanf("%d/%d+%d/%d", &numer1, &denom1, &numer2, &denom2);
	
	denominator = denom1 * denom2;
	numerator = (numer1 * denom2) + (numer2 * denom1);
	
	printf("The sum is %d/%d", numerator, denominator);
	
	return 0;
}
