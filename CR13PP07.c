/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 01/11/2019                                          *
* Description: Modification of Programming Project 11 from  *
*              Chapter 5 so that it uses arrays containing  *
*              pointers to strings instead of switch        *
*              statements                                   *
*************************************************************/

#include <stdio.h>

void print_name(int number);

int main(void)
{
	int input;
	
	printf("Enter a positive two-digit number: ");
	scanf("%d", &input);
	
	printf("You entered the number ");
	print_name(input);
	
	return 0;
}

void print_name(int number)
{
	char *ones[] = {"one", "two", "three", "four"
	,               "five" ,"six", "seven", "eight", "nine"};
	char *teens_case[] = {"eleven", "twelve", "thirteen", "fourteen"
	,                   "fifteen", "sixteen", "seventeen", "eighteen"
	,                    "nineteen"};
	char *tens[] = {"ten" ,"twenty", "thirty", "fourty", "fifty"
	,               "sixty" ,"seventy", "eighty", "ninety"};
	int ones_digit = number % 10, tens_digit = number / 10;
	
	if (number < 0)
	{
		printf("Invalid Input; negative number entered");
	}
	else if (number < 10)
	{
		printf("Invalid input; one digit number entered");
	}
	else if ((tens_digit >= 1 && tens_digit <= 9) && ones_digit == 0 && number < 100)
	{
		printf("%s", tens[tens_digit - 1]);
	}
	else if (number >= 11 && number < 20)
	{
		printf("%s", teens_case[ones_digit - 1]);
	}
	else if (tens_digit != 1 && (ones_digit >= 1 && ones_digit <= 9) && number < 100)
	{
		printf("%s-%s", tens[tens_digit - 1], ones[ones_digit - 1]);
	}
	else
	{
		printf("Invalid input; number has more than 2 digits");
	}
}
