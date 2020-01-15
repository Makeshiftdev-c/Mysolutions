/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 15/01/2020                                          *
* Description: Program computes the volume of a sphere with *
*              a user input radius.                         *
*************************************************************/

#include <stdio.h>

int main(void)
{
	float result;
	int radius;

  printf("Enter radius: ");
  scanf("%d", &radius);

	result = (4.0f/3.0f) * 3.142 * radius * radius * radius;

	printf("volume: %f cubic meters\n", result);

	return 0;
}
