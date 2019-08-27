/*Name: Abdirisak Arr
 *Date: 31/07/2019
 *Description: Program that reads an integer entered by the user and displays it in octal (base 8)
*/

#include <stdio.h>

int main(void)
{
	int number, octal, truncated_R;
	int first_Oct, second_Oct, third_Oct, fourth_Oct, fifth_Oct;
	float remainder, new_Number;
	
	printf("Enter a number between 0 and 32767: ");
	scanf("%d", &number);
	
	new_Number = number;
	fifth_Oct = number % 8;
	remainder = new_Number / 8;
	
	truncated_R = remainder;
	fourth_Oct = truncated_R % 8;
	remainder = truncated_R / 8;
	
	truncated_R = remainder;
	third_Oct = truncated_R % 8;
	remainder = truncated_R / 8;
	
	truncated_R = remainder;
	second_Oct = truncated_R % 8;
	remainder = truncated_R / 8;
	
	truncated_R = remainder;
	first_Oct = truncated_R % 8;
	
	octal = (first_Oct * 10000) + (second_Oct * 1000) + (third_Oct * 100) + (fourth_Oct * 10) + fifth_Oct;
	
	printf("In octal your number is: %.5d", octal);
	
	return 0;
}
