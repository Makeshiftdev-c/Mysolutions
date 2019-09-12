/* Name: Abdirisak Arr
 * Date: 12/09/2019
 * Description: Modification of Prorgamming Project 17 from Chapter 8, using two functions
 */
 
 #include <stdio.h>
 
 void create_magic_square(int n, char magic_square[99] [99]);
 void print_magic_square(int n, char magic_square[99] [99]);
 
 int main(void)
 {
 	char array[99] [99];
 	int number;
 	
 	printf("This program creates a magic square of a specified size.\n");
 	printf("The size must be an odd number between 1 and 99.\n");
 	printf("Enter size of magic square: ");
 	scanf("%d", &number);
 	
 	create_magic_square(number, array);
 	
 	print_magic_square(number, array);
 	
 	return 0;
 }
 
 void create_magic_square(int n, char magic_square[99] [99])
 {
 	int row, column, middle, count = 1;
 	
 	for (row = 0; row < n; row++)
 	{
 		for (column = 0; column < n; column++)
 		{
 			magic_square[row] [column] = '0';
		}
	}
	
	middle = n / 2;
	row = 0;
	column = middle;
	magic_square[row] [column] = count;
	
	for (;;)
	{
		row--;
		column++;
		count++;
		
		if (row < 0 && column > (n - 1))
		{
			row += 2;
			column--;
			magic_square[row] [column] = count;
		}
			
		else if (row < 0)
		{
			row = n - 1;
			if (magic_square[row] [column] == '0')
			{
				magic_square[row] [column] = count;
			}
			else
			{
				row = 0;
				row++;
				column--;
				magic_square[row] [column] = count;
			}
		}
		
		else if (column > (n - 1))
		{
			column = 0;
			if (magic_square[row] [column] == '0')
			{
				magic_square[row] [column] = count;
			}
			else
			{
			row += 2;
			column = n - 1;
			magic_square[row] [column] = count;
			}
		}
		
		else if (row >= 0 && column <= (n - 1))
		{
			if (magic_square[row] [column] == '0')
			{
				magic_square[row] [column] = count;
			}
			else
			{
				row += 2;
				column--;
				magic_square[row] [column] = count;
			}
		}
		
		if (count == (n*n))
		{
			break;
		}
	}
 }
 
 void print_magic_square(int n, char magic_square[99] [99])
 {
 	int row, column;
 	
 	for (row = 0; row < n; row++)
 	{
 		for (column = 0; column < n; column++)
 		{
 			printf("%5d", magic_square[row] [column]);
		}
		printf("\n");
	}
 }
