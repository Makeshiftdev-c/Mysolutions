/*Name: Abdirisak Arr
 *Date: 31/07/2019
 *Description: Program that reads an integer entered by the user and displays it in octal (base 8)
*/

#include <stdio.h>

int main(void)
{
	int number, remainder, octal;
	int first_Oct, second_Oct, third_Oct, fourth_Oct, fifth_Oct;
	
	printf("Enter a number between 0 and 32767: ");
	scanf("%d", &number);
	
	fifth_Oct = number % 8;
	remainder = number / 8;
	
	fourth_Oct = remainder % 8;
	remainder /= 8;
	
	third_Oct = remainder % 8;
	remainder /= 8;
	
	second_Oct = remainder % 8;
	remainder /= 8;
	
	first_Oct = remainder % 8;
	
	octal = (first_Oct * 10000) + (second_Oct * 1000) + (third_Oct * 100) + (fourth_Oct * 10) + fifth_Oct;
	
	printf("In octal your number is: %.5d", octal);
	
	return 0;
}
