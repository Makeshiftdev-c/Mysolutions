/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 02/12/2019                                          *
* Description: Program computes the volume of a sphere with *
*              a 10-meter radius.                           *
*************************************************************/

#include <stdio.h>

int main(void)
{
	float result;
	int radius = 10;
	
	result = (4.0f/3.0f) * 3.142 * radius * radius * radius;
	
	printf("volume: %f cubic meters", result);
	
	return 0;
}
