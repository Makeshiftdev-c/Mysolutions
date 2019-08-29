/* Name: Abdirisak Arr
 * Date: 21/08/2019
 * Description: Asks user for a 12-hour time, then displays the ime in 24-hour format
 */
 
 #include <stdio.h>
 #include <ctype.h>
 
 int main(void)
 {
 	int hh, mm;
 	char marker;
 	
 	printf("Enter 12-hour time: ");
 	scanf("%d:%2d %c", &hh, &mm, &marker);
    
	
	marker = toupper(marker);
	
	switch (marker)
	{
		case 'P':
			if (hh == 12)
			{
				hh = hh;
			}
			else
			{
				hh += 12;
			}
			break;
		case 'A':
			if (hh == 12)
			{
				hh = 0;
			}
			else
			{
				hh = hh;
			}
			break;
	}
	
	printf("The 24-hour format is: %.2d:%.2d", hh, mm);
	
	return 0;
			
	}
