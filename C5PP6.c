/*Name: Abdirisak Arr
 *Date: 31/07/2019
 *Description: Program that checks the validity of a Universal Product Code
*/

#include <stdio.h>

int main(void)
{
	int check_digit, d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, calculated_check_digit;
	int first_sum, second_sum, total;
	
	printf("Enter a UPC: ");
	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &d, &i1, &i2, &i3, &i4, &i5, &j1, &j2, &j3, &j4, &j5, &check_digit);
	
	first_sum = d + i2 + i4+ j1 + j3 + j5;
	second_sum = i1 + i3 + i5 + j2 + j4;
	total = 3 * first_sum + second_sum;
	calculated_check_digit = 9 - ((total - 1) % 10);
	
	if (check_digit == calculated_check_digit)
	 printf("Valid");
	else
	 printf("Invalid");
	
	return 0;
}
