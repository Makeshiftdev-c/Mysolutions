/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 09/11/2019                                          *
* Description: Reads a date in mm/dd/yyyy format then       *
*              prints the date in the form month, dd, yyyy  *
*              where month is the name of the month         *
*************************************************************/

#include <stdio.h>

#define MAX_LENGTH 18

int main(void)
{
	char *months_str[] = {"January", "February", "March", "April", "May", "June", "July"
	,                     "August", "September", "October", "November", "December"};
	char formatted_date[MAX_LENGTH];
	int month, day, year;
	
	printf("Enter a date (mm/dd/yyyy): ");
	scanf("%2d/%2d/%4d", &month, &day, &year);
	
	sprintf(formatted_date, "%s %d, %d", months_str[month - 1], day, year);
	
	printf("You entered the date %s\n", formatted_date);
	
	return 0; 
}
