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
	
	switch (hours)
	{
	case  0: printf("%.2d:%.2d AM", hours, minutes);
	         break;
	case 13: hours = 1;
	         printf("%.2d:%.2d PM", hours, minutes);
	         break;
	case 14: hours = 2;
	         printf("%.2d:%.2d PM", hours, minutes);
	         break;
	case 15: hours = 3;
	         printf("%.2d:%.2d PM", hours, minutes);
	         break;
	case 16: hours = 4;
	         printf("%.2d:%.2d PM", hours, minutes);
	         break;
	case 17: hours = 5;
	         printf("%.2d:%.2d PM", hours, minutes);
	         break;
	case 18: hours = 6;
	         printf("%.2d:%.2d PM", hours, minutes);
	         break;
	case 19: hours = 7;
	         printf("%.2d:%.2d PM", hours, minutes);
	         break;
	case 20: hours = 8;
	         printf("%.2d:%.2d PM", hours, minutes);
	         break;
	case 21: hours = 9;
	         printf("%.2d:%.2d PM", hours, minutes);
	         break;
	case 22: hours = 10;
	         printf("%.2d:%.2d PM", hours, minutes);
	         break;
	case 23: hours = 11;
	         printf("%.2d:%.2d PM", hours, minutes);
	         break;
	default: printf("%.2d:%.2d AM", hours, minutes);
	         break;
	}
	
	return 0;
}
