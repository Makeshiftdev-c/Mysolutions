/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 29/092019                                           *
* Description: Modification of Programming Project 7 from   *
*              chapter 2 with addition of function:         *
*               void pay_amount(int dollars, int *twenties, *
*               int *tens, int *fives, int *ones);          *
*************************************************************/

#include <stdio.h>

#define TWENTY 20
#define TEN 10
#define FIVE 5
#define ONE 1

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void)
{
	int amount, twenty, ten, five, one;
	
	printf("Enter a dollar amount: $");
	scanf("%d", &amount);
	
	pay_amount(amount, &twenty, &ten, &five, &one);
	
	printf("$%d bills: %d\n", TWENTY, twenty);
	printf("$%d bills: %d\n", TEN, ten);
	printf("$%d bills: %d\n", FIVE, five);
	printf("$%d bills: %d", ONE, one);
	
	return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
	int remainder;
	
	/* twenty change */
	*twenties = dollars / TWENTY;
	remainder = dollars - (TWENTY * *twenties);
	
	/* ten change */
	*tens = remainder / TEN;
	remainder = remainder - (TEN * *tens);
	
	/* five change */
	*fives = remainder / FIVE;
	remainder = remainder - (FIVE * *fives);
	
	/* one change */
	*ones = remainder;
}
