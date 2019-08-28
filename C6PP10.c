/*Name: Abdirisak Arr
 *Date: 11/08/2019
 *Description: Determines which of multiple dates comes earlier. User may enter any number of dates
 */
 
 #include <stdio.h>
 
 int main(void)
 {
 	int mm, dd, yy, mm_1 = 0, dd_1 = 0, yy_1 = 0, month, day, year;
 	
 	printf("Determines which date comes earlier, enter 0/0/0 when dates to be compared have been entered.\n");
 	
 	for(;;) //Input and comparison loop
 	{
 		printf("Enter a date (mm/dd/yy): ");
 		scanf("%2d/%2d/%2d", &mm, &dd, &yy);
 		
 		if (mm == 0 && dd == 0 && yy == 0) //Exits loop if 0/0/0 is entered
 		{
 			break;
		}
		else
		{
			if (yy >= yy_1)
			{
				if (yy == yy_1)
				{
					if (mm >= mm_1)
					{
						if (mm == mm_1)
						{
							if (dd > dd_1)
							{
								month = mm_1;
								day = dd_1;
								year = yy_1;
							}
							else
							{
								month = mm;
								day = dd;
								year = yy;
							}
						}
						else
						{
							month = mm_1;
							day = dd_1;
							year = yy_1;
						}
					}
					else
					{
						month = mm;
						day = dd;
						year = yy;
					}
				}
				else
				{
					month = mm;
					day = dd;
					year = yy;
				}
			}
			else
			{
				month = mm;
				day = dd;
				year = yy;
			}
		}
 		mm_1 = mm;
 		dd_1 = dd;
 		yy_1 = yy;
	}
	
	printf("%.2d/%.2d/%.2d is the earliest date", month, day, year);
	
	return 0;
 }
