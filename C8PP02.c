/* Name: Abdirisak Arr
 * Date: 29/08/2019
 * Description: Prints a table showing how many times each digit apprears in a number
 */
 
 #include <stdio.h>
 
 #define N 10
 
 int main(void)
 {
 	long n;
 	int digit, i, times_seen[N] = {0};
 	const int number[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
 	
 	printf("Enter a number: ");
 	scanf("%ld", &n);
 	
 	while (n > 0)
 	{
 		digit = n % 10;
 		switch (digit)
 		{
 			case 0:
 				times_seen[digit]++;
 				break;
 			case 1:
 				times_seen[digit]++;
 				break;
 			case 2:
 				times_seen[digit]++;
 				break;
 			case 3:
 				times_seen[digit]++;
 				break;
 			case 4:
 				times_seen[digit]++;
 				break;
 			case 5:
 				times_seen[digit]++;
 				break;
 			case 6:
 				times_seen[digit]++;
 				break;
 			case 7:
 				times_seen[digit]++;
 				break;
 			case 8:
 				times_seen[digit]++;
 				break;
 			case 9:
 				times_seen[digit]++;
 				break;
		}
		n /= 10;
	}
	
	printf("Digit:\t\t");
	for (i = 0; i < N; i++)
	{
		printf("%3d", number[i]);
	}
	
	printf("\nOccurrences:\t");
	for (i = 0; i < N; i++)
	{
		printf("%3d", times_seen[i]);
	}
	
	return 0;
 }
