/* Name: Abdirisak Arr
 * Date: 06/09/2019
 * Description: Prints an n*n magic square
 */
 
 #include <stdio.h>
 
 #define MAX_DIMENSION 99
 
 int main(void)
 {
 	int array[MAX_DIMENSION] [MAX_DIMENSION], n, middle;
 	int counter1, counter2, row, column;
 	
 	/* Description and input prompt */
 	printf("This program creates a magic square of a specified size.");
 	printf("\nThe size must be an odd number between 1 and 99.");
 	printf("\nEnter size of magic square: ");
 	scanf("%d", &n);
 	
 	/* Array, variables, and initial position initialisation for processing */
 	for (counter1 = 0; counter1 < n; counter1++)
 	{
 		for (counter2 = 0; counter2 < n; counter2++)
 		{
 			array[counter1] [counter2] = 0;
		}
	}
 	
 	middle = n / 2;
 	row = 0;
 	column = middle;
 	array[row] [column] = 1;
 	
 	/* Processing */
 	for (counter1 = 2; counter1 <= ((n*n)); counter1++)
 	{
 		row--;
 		column++;
 		if (row < 0 && column > (n - 1))
 		{
 			row += 2;
 			column--;
 			array[row] [column] = counter1;
		}
 		else if (row < 0)
 		{
 			row = n - 1;
 			if (array[row] [column] == 0)
 			{
 				array[row] [column] = counter1;
			}
			else
			{
				row = 0;
				row++;
				column--;
				array[row] [column] = counter1;
			}
		}
		else if (column > (n - 1))
		{
			column = 0;
			if (array[row] [column] == 0)
			{
				array[row] [column] = counter1;
			}
			else
			{
				column = n - 1;
				row += 2;
				array[row] [column] = counter1;
			}
		}
		else if (row >= 0 && column <= (n - 1))
		{
			if (array[row] [column] == 0)
			{
				array[row] [column] = counter1;
			}
			else
			{
				row += 2;
				column--;
				array[row] [column] = counter1;
			}
		}
	}
		
	/* Output */
	for (counter1 = 0; counter1 < n; counter1++)
	{
		for (counter2 = 0; counter2 < n; counter2++)
		{
			printf("%5d", array[counter1] [counter2]);
		}
		printf("\n");
	}
	
	return 0;
 }
