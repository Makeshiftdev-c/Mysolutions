/*Name: Abdirisak Arr
 *Date: 04/08/2019
 *Description: Prompts user to enter two dates and then indicates which date comes earlier on the calendar
*/

#include <stdio.h>

int main(void)
{
	int first_dd, second_dd, first_mm, second_mm, first_yy, second_yy, max_dd;
	
	printf("Enter first date (mm/dd/yy) : ");
	scanf("%2d/%2d/%2d", &first_mm, &first_dd, &first_yy);
	
	switch (first_mm)                                      //assigns variable for restraint maximum number of days in month variable
	{
		case 1:
			max_dd = 31; 
			break;
		case 3:
			max_dd = 31; 
			break;
		case 5:
			max_dd = 31; 
			break;
		case 7:
			max_dd = 31; 
			break;
		case 8:
			max_dd = 31; 
			break;
		case 10:
			max_dd = 31; 
			break;
		case 12:
    		max_dd = 31; 
			break;
    	case 4:
    		max_dd = 30;
    		break;
		case 6:
			max_dd = 30;
    		break;
		case 9:
			max_dd = 30;
    		break;
		case 11:
    		max_dd = 30;
    		break;
    	case 2:
    		max_dd = 28;
    		break;
	}
	
	if (first_dd <= max_dd)                                //skips rest of program if invalid input is entered (formatted-output related)
	{
		
	printf("Enter second date (mm/dd/yy) : ");
	scanf("%2d/%2d/%2d", &second_mm, &second_dd, &second_yy);
	
	switch (second_mm)                                      //assigns variable for restraint maximum number of days in month variable
	{
		case 1:
			max_dd = 31; 
			break;
		case 3:
			max_dd = 31; 
			break;
		case 5:
			max_dd = 31; 
			break;
		case 7:
			max_dd = 31; 
			break;
		case 8:
			max_dd = 31; 
			break;
		case 10:
			max_dd = 31; 
			break;
		case 12:
    		max_dd = 31; 
			break;
    	case 4:
    		max_dd = 30;
    		break;
		case 6:
			max_dd = 30;
    		break;
		case 9:
			max_dd = 30;
    		break;
		case 11:
    		max_dd = 30;
    		break;
    	case 2:
    		max_dd = 28;
    		break;
	}
	
	
	if (first_dd <= max_dd && second_dd <= max_dd && first_mm <= 12 && second_mm <= 12) //sets restraints for days and months
	{
			if (first_yy >= second_yy)                                         //compares years
        	{
        		if (first_yy == second_yy)                                       //accounts for special case of equal years
        		{
        			if (first_mm >= second_mm)                                       //compares months
        			{
        				if (first_mm == second_mm)                                    //accounts for special case of equal months
        				{
        					if (first_dd > second_dd)                                   //compares days
        					{
        						printf("%d/%d/%.2d is earlier than %d/%d/%.2d", second_mm, second_dd, second_yy, first_mm, first_dd, first_yy);
        					}
        					else
        					{
        						printf("%d/%d/%.2d is earlier than %d/%d/%.2d", first_mm, first_dd, first_yy, second_mm, second_dd, second_yy);
							}
        				}
        				else
        				{
        					printf("%d/%d/%.2d is earlier than %d/%d/%.2d", second_mm, second_dd, second_yy, first_mm, first_dd, first_yy);
						}
           			}
           			else
           			{
           				printf("%d/%d/%.2d is earlier than %d/%d/%.2d", first_mm, first_dd, first_yy, second_mm, second_dd, second_yy);
					}
        		}
        		else
        		{
        			printf("%d/%d/%.2d is earlier than %d/%d/%.2d", second_mm, second_dd, second_yy, first_mm, first_dd, first_yy);
				}
        	}
        	else
        	{
        		printf("%d/%d/%.2d is earlier than %d/%d/%.2d", first_mm, first_dd, first_mm, second_mm, second_dd, second_yy);
			}
    }
	else
	{
		printf("Invalid input.");
	}
	}
	else
	{
		printf("Invalid input.");
	}
	
	return 0;
}
