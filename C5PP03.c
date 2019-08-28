/*Name: Abdirisak Arr
 *Date: 01/08/2019
 *Description: Program that calculates a brokers commission
*/

#include <stdio.h>

int main(void)
{
	float commission, rival_commission, price_per_share, value;
	int number_of_shares;
	
	printf("Enter the number of shares: ");
	scanf("%d", &number_of_shares);
	printf("Enter the price per share: $");
	scanf("%f", &price_per_share);
	
	value = (float)number_of_shares * price_per_share;
	printf("Value of trade: $%.2f\n", value);
	
	/*Firm's commission*/
	if (value < 2500.00f)
	 commission = 30.00f + .017f * value;
	else if (value < 6250.00f)
	 commission = 56.00f + .0066f * value;
	else if (value < 20000.00f)
	 commission = 76.00f + .0034f * value;
	else if (value < 50000.00f)
	 commission = 100.00f + .0022f * value;
	else if (value < 500000.00f)
	 commission = 155.00f + .0011f * value;
	else
	 commission = 255.00f + .0009f * value;
	
	if (commission < 39.00f)
	 commission = 39.00f;
	 
	/*Rival firm's commssion*/
	if (number_of_shares < 2000)
	 rival_commission = 33.00f + (0.03f * number_of_shares);
	else
	 rival_commission = 33.00f + (0.02f * number_of_shares);
	
	
	printf("Commission: $%.2f\n", commission);
	printf("Competitor commission: $%.2f", rival_commission);
	
	return 0;
}
