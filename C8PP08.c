/* Name: Abdirisak Arr
 * Date: 01/09/2019
 * Description: Prompts for five quiz grades for each of five students, then computes the total score and average
 *              score for each student, and the average score, high score, and low score for each quiz
 */
 
 #include <stdio.h>
 
 #define SIZE 5
 
 int main(void)
 {
 	int row[SIZE], scores_for_high[SIZE] [SIZE], scores_for_low[SIZE] [SIZE], count1, count2;
 	int count3, count4, count5, high[SIZE] = {0}, low[SIZE] = {0}, student_total[SIZE] = {0}, quiz_total[SIZE] = {0};
 	double student_average[SIZE], quiz_average[SIZE];
 	
 	printf("Enter the %d quiz grades for each student.\n", SIZE);
 	
 	/* Input, secondary processing setup, and primary processing and primary output loop */
 	for (count1 = 0; count1 < SIZE; count1++)
 	{
 		printf("\nStudent %d: ", count1 + 1);
 		for (count2 = 0; count2 < SIZE; count2++)
 		{
 			scanf("%d", &row[count2]);
 			scores_for_high[count1] [count2] = row[count2];
 			scores_for_low[count1] [count2] = row[count2];
 			
 			student_total[count1] += row[count2];
 			quiz_total[count2] += row[count2];
		}
		student_average[count1] = (double) student_total[count1] / SIZE;
		
		printf("\n");
		printf("Student %d's total: %d\n", count1 + 1, student_total[count1]);
		printf("Student %d's average: %lg\n", count1 + 1, student_average[count1]);
	}
	
	/* Secondary processing loop */
	for (count1 = 0; count1 < SIZE; count1++)
	{
		quiz_average[count1] = (double) quiz_total[count1] / SIZE;
		
		for (count2 = 0, count3 = 1; count2 < (SIZE - 1), count3 < SIZE; count2++, count3++)
		{
			
			if (scores_for_high[count3] [count1] >= scores_for_high[count2] [count1])
			{
				high[count1] = scores_for_high[count3] [count1];
				scores_for_high[count2] [count1] = scores_for_high[count3] [count1];
				
			}
			else
			{
				high[count1] = scores_for_high[count2] [count1]; 
				scores_for_high[count3] [count1] = scores_for_high[count2] [count1];
			}
		}
		
		for (count4 = 0, count5 = 1; count4 < (SIZE - 1), count5 < SIZE; count4++, count5++)
		{
			if (scores_for_low[count5] [count1] <= scores_for_low[count4] [count1])
			{
				low[count1] = scores_for_low[count5] [count1];
				scores_for_low[count4] [count1] = scores_for_low[count5] [count1];
			}
			else
			{
				low[count1] = scores_for_low[count4] [count1];
				scores_for_low[count5] [count1] = scores_for_low[count4] [count1];
			}
		}
	}
	
	/* Secondary output loops */
	printf("\n");
	printf("Average quiz grade: ");
	for (count1 = 0; count1 < SIZE; count1++)
	{
		printf("%lg ", quiz_average[count1]);
	}
	
	printf("\n");
	printf("Highest quiz grades: ");
	for (count2 = 0; count2 < SIZE; count2++)
	{
		printf("%d ", high[count2]);
	}
	
	printf("\n");
	printf("Lowest quiz grades: ");
	for (count3 = 0; count3 < SIZE; count3++)
	{
		printf("%d ", low[count3]);
	}
	
	return 0;
 }
