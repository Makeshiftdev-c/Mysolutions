/*Name: Abdirisak Arr
 *Date: 31/09/2019
 *Description: Program that asks the user to enter a three-digit number, then prints the number with its digits reversed (without arithmetic)
*/

#include <stdio.h>

int main(void)
{
	int first, second, third;
	
	printf("Enter a three-digit number: ");
	scanf("%1d%1d%1d", &first, &second, &third);
	
	printf("The reversal is: %d%d%d", third, second, first);
	
	return 0;
}
