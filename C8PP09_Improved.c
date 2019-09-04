/* Name: Abdirisak Arr
 * Date: 02/09/2019
 * Description: Generates a "random walk" across a 10*10 array
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <stdbool.h>
 
 #define SIZE 10
 #define MAX_VALUE 26
 
 int main(void)
 {
 	signed char path[SIZE] [SIZE];
 	const signed char walk_value[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'
	                                  , 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S'
									  , 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	int count1, count2, v = 0, h = 0, control;
	bool open_path = true;
	
	/* 10*10 array initialiation */
	for (count1 = 0; count1 < SIZE; count1++)
	{
		for (count2 = 0; count2 < SIZE; count2++)
		{
			path[count1] [count2] = '.';
		}
	}
	
	count1 = 0;
	path[h] [v] = walk_value[count1];
	srand((unsigned) time(NULL));
	
	/* Processing loop */
	while (open_path)
	{
		count1++;
		control = rand() % 4;
		
		if (path[h + 1] [v] != '.' && path[h - 1] [v] != '.' && path[h] [v + 1] != '.' && path[h] [v - 1] != '.')
		{
			break;
		}
		
		if (v == 0 && path[h + 1] [v] != '.' && path[h - 1] [v] != '.' && path[h] [v + 1] != '.')
		{
			break;
		}
		
		if (h == 0 && path[h + 1] [v] != '.' && path[h] [v + 1] != '.' && path[h] [v - 1] != '.')
		{
			break;
		}
		
		if (v == (SIZE - 1) && path[h + 1] [v] != '.' && path[h - 1] [v] != '.' && path[h] [v - 1] != '.')
		{
			break;
		}
		
		if (h == (SIZE - 1) && path[h - 1] [v] != '.' && path[h] [v + 1] != '.' && path[h] [v - 1] != '.')
		{
			break;
		}
		
		
		if (h >= 0 && v < SIZE && h < SIZE && v >= 0)
		{
			switch (control)
			{
				case 0:
					if (path[h + 1] [v] == '.')
					{
						if (h < (SIZE - 1))
						{
							h++;
							path[h] [v] = walk_value[count1];
						}
						else 
						{
							count1--;
						}
					}
					else
					{
						count1--;
					}
					break;
				case 1:
					if (path[h - 1] [v] == '.')
					{
						if (h > 0)
						{
							h--;
							path[h] [v] = walk_value[count1];
						}
						else
						{
							count1--;
						}
					}
					else
					{
						count1--;
					}
					break;
				case 2:
					if (path[h] [v + 1] == '.')
					{
						if (v < (SIZE - 1))
						{
							v++;
							path[h] [v] = walk_value[count1];
						}
						else
						{
							count1--;
						}
					}
					else
					{
						count1--;
					}
					break;
				case 3:
					if (path[h] [v - 1] == '.')
					{
						if (v > 0)
						{
							v--;
							path[h] [v] = walk_value[count1];
						}
						else
						{
							count1--;
						}
					}
					else
					{
						count1--;
					}
					break;
			}
		}
		
		if (count1 == (MAX_VALUE - 1))
		{
			break;
		}
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
