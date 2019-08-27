/*Name: Abdirisak Arr
 *Date: 31/09/2019
 *Description: Program that asks the user to enter a three-digit number, then prints the number with its digits reversed (using arithmetic)
*/

#include <stdio.h>

int main(void)
{
	int number, first_Digit, second_Digit, third_Digit, reverse;
	
	printf("Enter a three-digit number: ");
	scanf("%3d", &number);
	
	first_Digit = number / 100;
	second_Digit = (number / 10) % 10;
	third_Digit = number % 10;
	
	reverse = (third_Digit * 100) + (second_Digit * 10) + first_Digit;
	
	printf("The reversal is: %d", reverse);
	
	return 0;
}
