/* Name: Abdirisak Arr
 * Date: 31/08/2019
 * Description: Reads a 5*5 array of integers and then prints the row sums and the columns sums
 */
 
 #include <stdio.h>
 
 #define SIZE 5
 
 int main(void)
 {
 	int row[SIZE], row_sum[SIZE] = {0}, column_sum[SIZE] = {0};
 	int count1, count2;
 	
 	count2 = 0;
 	while (count2 < SIZE)
 	{
 		printf("Enter row %d: ", count2 + 1);
 		for (count1 = 0; count1 < SIZE; count1++)
 		{
 			scanf("%d", &row[count1]);
 			row_sum[count2] += row[count1];
 			column_sum[count1] += row[count1];
		}
		
		count2++;
	}
	
	printf("\nRow totals:");
	for (count1 = 0; count1 < SIZE; count1++)
	{
		printf(" %d", row_sum[count1]);
	}
	
	printf("\nColumn totals:");
	for (count1 = 0; count1 < SIZE; count1++)
	{
		printf(" %d", column_sum[count1]);
	}
	
	return 0;
 }
