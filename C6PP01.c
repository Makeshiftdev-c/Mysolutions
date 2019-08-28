/*Name: Abdirisak Arr
 *Date:08/08/2019
 *Description: Finds the largest in a series of numbers entered by the user. Prompts user to enter one by one.
               When user enters zero or negative integer, the program displays the largest non-negative number
               entered.
*/

#include <stdio.h>

int main(void)
{
	float number1, number2 = 0.00f, large;
		
	for (;;)
	{
		printf("Enter a number: ");
		scanf("%f", &number1);
		
		if (number1 <= 0.00f)
		{
			break;
		}
		
		else if (number1 > number2)
		{
			large = number1;
			number2 = number1;
		}
	}
	
	printf("The largest number entered was %g", large);
	
	return 0;
}
