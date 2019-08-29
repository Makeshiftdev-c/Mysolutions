/* Name: Abdirisak Arr
 * Date 24/08/2019
 * Description: Calculates the average word length for a sentence
 */
 
 #include <stdio.h>
 
 int main(void)
 {
 	float sum = 0.00f, count = 1.00f, average;
 	signed char ch;
 	
 	printf("Enter a sentence (indicate end of sentence with a period): ");
 	while ((ch = getchar()) != '.')
 	{
 		if (ch == ' ')
 		{
 			count++;
		}
		else
		{
			sum++;
		}
	}
	
	average = sum / count;
	
	printf("Average word length: %.1f", average);
	
	return 0;
 }
