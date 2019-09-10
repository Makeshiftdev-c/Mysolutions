/* Name: Abdirisak Arr
 * Date: 10/09/2019
 * Description: Modification of Programming Project 5 from Chapter 5. Uses a function to compute the amount of
 				income tax, when passed an amount of taxable income the function will return the tax due
 */
 
 #include <stdio.h>
 
 float income_tax(float income);
 
 int main(void)
 {
 	float taxable_income, tax_due;
 	
 	printf("Enter amount of taxable income: $");
 	scanf("%f", &taxable_income);
 	
 	tax_due = income_tax(taxable_income);
 	
 	printf("Tax due: $%.2f", tax_due);
 	
 	return 0;
 }
 
 float income_tax(float income)
 {
 	if (income < 750.00f)
 	{
 		return income * .01f;
	}
	else if (income >= 750.00f && income < 2250.00f)
	{
		return (((income - 750.00f) * .02f) + 7.50f);
	}
	else if (income >= 2250.00f && income < 3750.00f)
	{
		return (((income - 2250.00f) * .03f) + 37.50f);
	}
	else if (income >= 3750.00f && income < 5250.00f)
	{
		return (((income - 3750.00f) * .04f) + 82.50f);
	}
	else if (income >= 5250.00f && income < 7000.00f)
	{
		return (((income - 5250.00f) * 0.05f) + 142.50f);
	}
	else
	{
		return (((income - 7000.00f) * .06f) + 230.00f);
	}
 }
