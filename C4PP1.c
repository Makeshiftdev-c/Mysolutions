/*Name: Abdirisak Arr
 *Date: 31/07/2019
 *Description: Program that asks the user to enter a two-digit number, then prints the number with its digits reversed (using arithmetic)
*/

#include <stdio.h>

int main(void)
{
	int number, first_Digit, second_Digit, reverse;
	
	printf("Enter a two-digit number: ");
	scanf("%2d", &number);
	
	first_Digit = number / 10;
	second_Digit = number % 10;
	
	reverse = (second_Digit * 10) + first_Digit;
	
	printf("The reversal is: %d", reverse);
	
	return 0;
}
  
