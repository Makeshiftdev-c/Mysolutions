/* Name: Abdirisak Arr
 * Date: 10/09/2019
 * Description: Modification of Programming Project 9 from Chapter 8, using two funcions to generate and print
 				'random walk' through 10*10 array
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <stdbool.h>
 
 #define DIMENSION 10
 #define LAST_ELEMENT (DIMENSION - 1)
 #define FIRST_ELEMENT 0
 
 void generate_random_walk(char walk[10] [10]);
 void print_array(char walk[10] [10]);
 
 int main(void)
 {
 	char array[DIMENSION] [DIMENSION];
 	
 	generate_random_walk(array);
 	print_array(array);
 	
 	return 0;
 }
 
 void generate_random_walk(char walk[10] [10])
 {
 	int counter1, counter2, control, r = 0, c = 0;
 	const signed char walk_value[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
	 									'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
 	
 	for (counter1 = FIRST_ELEMENT; counter1 <= LAST_ELEMENT; counter1++)
 	{
 		for (counter2 = FIRST_ELEMENT; counter2 <= LAST_ELEMENT; counter2++)
 		{
 			walk[counter1] [counter2] = '.';
		}
	}
	
	counter1 = 0;
	walk[r] [c] = walk_value[counter1];
	srand((unsigned) time(NULL));
	
	while (true)
	{
		control = rand() % 4;
		counter1++;
		
		if (walk[r + 1] [c] != '.' && walk[r - 1] [c] != '.' && walk[r] [c + 1] != '.' && walk[r] [c - 1] != '.')
		{
			break;
		}
		
		if (r == 0 && walk[r + 1] [c] != '.' && walk[r] [c + 1] != '.' && walk[r] [c - 1] != '.')
		{
			break;
		}
		
		if (r == 9 && walk[r - 1] [c] != '.' && walk[r] [c + 1] != '.' && walk[r] [c - 1] != '.')
		{
			break;
		}
		
		if (c == 0 && walk[r + 1] [c] != '.' && walk[r - 1] [c] != '.' && walk[r] [c + 1] != '.')
		{
			break;
		}
		
		if (c == 9 && walk[r + 1] [c] != '.' && walk[r - 1] [c] != '.' && walk[r] [c - 1] != '.')
		{
			break;
		}
		
		switch (control)
		{
			case 0:
				if (walk[r + 1] [c] == '.')
				{
					if (r < 9)
					{
						r++;
						walk[r] [c] = walk_value[counter1];
					}
					else
					{
						counter1--;
					}
				}
				else
				{
					counter1--;
				}
				break;
			case 1:
				if (walk[r - 1] [c] == '.')
				{
					if (r > 0)
					{
						r--;
						walk[r] [c] = walk_value[counter1];
					}
					else
					{
						counter1--;
					}
				}
				else
				{
					counter1--;
				}
				break;
			case 2:
				if (walk[r] [c + 1] == '.')
				{
					if (c < 9)
					{
						c++;
						walk[r] [c] = walk_value[counter1];
					}
					else
					{
						counter1--;
					}
				}
				else
				{
					counter1--;
				}
				break;
			case 3:
				if (walk[r] [c - 1] == '.')
				{
					if (c > 0)
					{
						c--;
						walk[r] [c] = walk_value[counter1];
					}
					else
					{
						counter1--;
					}
				}
				else
				{
					counter1--;
				}
				break;
		}
		
		if (counter1 == 25)
		{
			break;
		}
	}
 }
 
 void print_array(char walk[10] [10])
 {
 	int counter1, counter2;
 	
 	for (counter1 = FIRST_ELEMENT; counter1 <= LAST_ELEMENT; counter1++)
 	{
 		for (counter2 = FIRST_ELEMENT; counter2 <= LAST_ELEMENT; counter2++)
 		{
 			printf("%3c", walk[counter1] [counter2]);
		}
		printf("\n");
	}
 }
