/*Name: Abdirisak Arr
 *Date: 03/08/2019
 *Description: Aks user to enter a time (expressed in hours and minutes, using the 24-hour clock).
               The program then displays the departure and arrival times for the whose departure
               time is closest to that entered by the user
               Note: Badly wrote code for C5PP8 upon which this program is based, hence hard to modify within required parameters
               . Come back to it at some later point to rewrite
*/

#include <stdio.h>

int main(void)
{
	int hours, minutes;
	
	printf("Enter a 24-hour time: ");
	scanf("%2d:%2d", &hours, &minutes);
	
	if (hours <= 23 && minutes <= 60)
	{
		printf("Closest departure time is ");
       	if (hours < 8)
    	{
	    	printf("8:00 a.m., arriving at 10:16 a.m.");
	    }
	    else if (hours >= 8 && hours < 10)
	    {
		if (hours == 9 && minutes >= 44)
	    	{
	   	    	printf("11:19 a.m., arriving at 1:31 p.m.");
		    }
		else
		    {
	    		printf("9:43 a.m., arriving at 11:52 a.m.");
	        }
	    }
    	else if (hours >= 10 && hours < 12)
    	{
  		if (hours == 11 && minutes >= 20)
    		{
    			printf("12:47 a.m., arriving at 1:31 p.m.");
    		}
		else
    		{
    			printf("11:19 a.m., arriving at 1:31 p.m.");
    		}
    	}
    	else if (hours >= 12 && hours <= 14)
    	{
    		if (hours == 14 && minutes > 0)
       		{
    			printf("3:45 p.m., arriving at 5:55 p.m.");
			}
			else
			{
				printf("2:00 p.m., arriving at 4:08 p.m.");
			}
	    }
	    else if (hours > 14 && hours < 16)
	    {
		if (hours == 15 && minutes >= 46)
    		{
    			printf("7:00 p.m., arriving at 9:20 p.m.");
    		}
		else
    		{
    			printf("2:00 p.m., arriving at 4:08 p.m.");
    		}
	    }
	    else if (hours >= 16 && hours < 19)
        {
    	    printf("7:00 p.m., arriving at 9:20 p.m.");
        }
    	else 
        {
        if (hours <= 21 && minutes >= 45)
            {
            	printf("9:45 p.m., arriving at 11:58 p.m.");
        	}
       	else 
		    {
     		    printf("8:00 a.m., arriving at 10:16 a.m.");
    		}	
        }
    }
	else 
	{
		printf("Invalid input");
	}
	
	return 0;
}
