/*Name: Abdirisak Arr
 *Date: 01/08/2019
 *Description: Program that asks the user for a 24-hour time, then displays the time in 12-hour form
*/

#include <stdio.h>

int main(void)
{
	int hours, minutes;
	
	printf("Enter a 24-hour time: ");
	scanf("%2d:%2d", &hours, &minutes);
	
	printf("Equivalent 12-hour time: ");
	
	if (hours >= 12)
	{
		if (hours == 12)
	    	printf("%.2d:%.2d PM", hours, minutes);
		else if (hours == 13)
		{
			hours = 1;
			printf("%.2d:%.2d PM", hours, minutes);
		}
		else if (hours == 14)
		{
			hours = 2;
			printf("%.2d:%.2d PM", hours, minutes);
		}else if (hours == 15)
		{
			hours = 3;
			printf("%.2d:%.2d PM", hours, minutes);
		}else if (hours == 16)
		{
			hours = 4;
			printf("%.2d:%.2d PM", hours, minutes);
		}else if (hours == 17)
		{
			hours = 5;
			printf("%.2d:%.2d PM", hours, minutes);
		}else if (hours == 18)
		{
			hours = 6;
			printf("%.2d:%.2d PM", hours, minutes);
		}else if (hours == 19)
		{
			hours = 7;
			printf("%.2d:%.2d PM", hours, minutes);
		}else if (hours == 20)
		{
			hours = 8;
			printf("%.2d:%.2d PM", hours, minutes);
		}else if (hours == 21)
		{
			hours = 9;
			printf("%.2d:%.2d PM", hours, minutes);
		}else if (hours == 22)
		{
			hours = 10;
			printf("%.2d:%.2d PM", hours, minutes);
		}else if (hours == 23)
		{
			hours = 11;
			printf("%.2d:%.2d PM", hours, minutes);
		}
	}
	else if (hours == 0)
		{
			hours = 12;
			printf("%.2d:%.2d AM", hours, minutes);
		}
	else
	 printf("%.2d:%.2d AM", hours, minutes);
	
}
