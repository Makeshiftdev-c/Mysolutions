/* Name: Abdirisak Arr
 * Date: 30/08/2019
 * Description: Modification of interest.c program so that it compounds interest monthly instead of annually
 */
 
#include <stdio.h>

#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int main(void)
{
	int i, low_rate, num_years, year;
	const int compound_frequency = 12;
	double value[5];
	
	printf("Enter interest rate: ");
	scanf("%d", &low_rate);
	printf("Enter number of years: ");
	scanf("%d", &num_years);
	
	printf("\nYears");
	for (i = 0; i < NUM_RATES; i++)
	{
		printf("%8d%%", low_rate + i);
		value[i] = INITIAL_BALANCE;
	}
	printf("\n");
	
	for (year = 1; year <= num_years; year++)
	{
		printf("%3d      ", year);
		for (i = 0; i < NUM_RATES; i++)
		{
			value[i] += (low_rate + i) / 100.0 * value[i] * compound_frequency;
			printf("%8.2f", value[i]);
		}
		printf("\n");
	}
	
	return 0;
}
