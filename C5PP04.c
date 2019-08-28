/*Name: Abdirisak Arr
 *Date: 02/08/2019
 *Description: Program that asks the user to enter a wind speed (in knots), then displays the corresponding description
*/

#include <stdio.h>

int main(void)
{
	float speed;
	
	printf("Enter wind speed (in knots): ");
	scanf("%f", &speed);
	
	printf("Description: ");
	
	if (speed < 1.00f)
	 printf("Calm");
	else if (speed >= 1.00f && speed <= 3.00f)
	 printf("Light air");
	else if (speed >= 4.00f && speed <= 27.00f)
	 printf("Breeze");
	else if (speed >= 28.00f && speed <= 47.00f)
	 printf("Gale");
	else if (speed >= 48.00f && speed <= 63.00f)
	 printf("Storm");
	else
	 printf("Hurricane");
	
	return 0;
}
