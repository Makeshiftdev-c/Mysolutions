/* Name: Abdirisak Arr
 * Date: 02/09/2019
 * Description: Generates a "random walk" across a 10*10 array
 */
 
 #include <stdio.h>
 #include <stdbool.h>
 #include <stdlib.h>
 #include <time.h>
 
 #define SIZE 10
 #define MAX_VALUE 26
 
 int main(void)
 {
 	signed char path[SIZE] [SIZE];
 	const signed char walk_value[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'
	                                  , 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S'
									  , 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	bool is_seen[SIZE] [SIZE];
	int count1, count2, v = 0, h = 0, control;
	
	/* 10*10 array initialiation */
	for (count1 = 0; count1 < SIZE; count1++)
	{
		for (count2 = 0; count2 < SIZE; count2++)
		{
			path[count1] [count2] = '.';
		}
	}
	
	srand((unsigned) time(NULL));
	
	/* Processing loop */
	count1 = 0;
	count2 = 1;
	while (count1 < MAX_VALUE)
	{
		path[h] [v] = walk_value[count1];
		control = rand() % 4;
		
		if (h >= 0 || h < 10 && v >= 0 || v < 10)
		{
			switch (control)
			{
				case 0:
					if (path[h + 1] [v] == '.')
					{
						h++;
					}
					else if (path[h - 1] [v] == '.')
					{
						h--;
					}
					else if (path[h] [v + 1] == '.')
					{
						v++;
					}
					else if (path[h] [v - 1] == '.')
					{
						v--;
					}
					break;
				case 1:
					if (path[h - 1] [v] == '.')
					{
						h--;
					}
					else if (path[h + 1] [v] == '.')
					{
						h++;
					}
					else if (path[h] [v - 1] == '.')
					{
						v--;
					}
					else if (path[h] [v + 1] == '.')
					{
						v++;
					}
					break;
				case 2:
					if (path[h] [v + 1] == '.')
					{
						v++;
					}
					else if (path[h] [v - 1] == '.')
					{
						v--;
					}
					else if (path[h + 1] [v] == '.')
					{
						h++;
					}
					else if (path[h - 1] [v] == '.')
					{
						h--;
					}
				case 3:
					if (path[h] [v - 1] == '.')
					{
						v--;
					}
					else if (path[h] [v + 1] == '.')
					{
						v++;
					}
					else if (path[h - 1] [v] == '.')
					{
						h--;
					}
					else if (path[h + 1] [v] == '.')
					{
						h++;
					}
			}
		}
		else
		{
			break;
		}
		count1++;
	}
	
	/* Output loop */
	for (count1 = 0; count1 < SIZE; count1++)
	{
		for(count2 = 0; count2 < SIZE; count2++)
		{
			printf("%c", path[count1] [count2]);
		}
		printf("\n");
	}
	
	
	return 0;
 }
