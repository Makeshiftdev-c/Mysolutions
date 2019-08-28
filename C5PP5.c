/*Name: Abdirisak Arr
 *Date: 02/08/2019
 *Description: Asks user to enter the amount of taxable income, then displays the tax due
*/

#include <stdio.h>

int main(void)
{
	float income, tax;
	
	printf("Enter income: $");
	scanf("%f", &income);
	
	if (income < 750.00f)
	 tax = income * 0.01f;
	else if (income >= 750.00f && income < 2250.00f)
	 tax = ((income - 750.00f) * 0.02f) + 7.50f;
	else if (income >= 2250.00f && income < 3750.00f)
	 tax = ((income - 2250.00f) * 0.03f) + 37.50f;
	else if (income >= 3750.00f && income < 5250.00f)
	 tax = ((income - 3750.00f) * 0.04f) + 82.50f;
	else if (income >= 5250.00f && income < 7000.00f)
	 tax = ((income - 5250.00f) * 0.05f) + 142.50f;
	else
	 tax = ((income - 7000.00f) * 0.06) + 230.00f;
	 
	printf("Tax due: $%.2f", tax);
	
	return 0;
}
