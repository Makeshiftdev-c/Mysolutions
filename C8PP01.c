/* Name: Abdirisak Arr
 * Date: 27/08/2019
 * Description: Modification of repdigit.c so that it shows which digits (if any) were repeated
 */
 
 #include <stdio.h>
 #include <stdbool.h>
 
 #define N 10 // Change this to increase maximum number of integers for input
 
 int main (void)
 {
 	// Variables identifiers could have been better chosen... But, after the fact ofcourse... I can C clearly now (bad pun intended)
 	bool digit_seen[N] = {false};
 	int digit, i = 0, j, repeated_digits[N] = {0};
 	long n;
 	
 	printf("Enter a positive %d digit integer: ", N);
 	scanf("%ld", &n);
 	
 	while (n > 0) //Checks for repeat digits and saves them in repeated_digits array for processing
 	{
 		digit = n % 10;
 		if (digit_seen[digit])
 		{
 			repeated_digits[i] = digit;
 			i++;
		}
		digit_seen[digit] = true;
		n /= 10;
	}
	
	if (i > 0) // Outputs whether or not there are repeated digits
	{
		printf("Repeated digits:");
		for (j = N - 1; j >= 0; j--) // Parses array for repeated input
		{
			if (repeated_digits[j] == repeated_digits[j + 1]) // Prevents repeated console output
			{
				continue;
			}
			if (repeated_digits[j] == 0) // Skips unchanged elements
			{
				continue;
			}
			else
			{
				printf(" %d", repeated_digits[j]);
			}
		}
	}
	else
	{
		printf("There are no repeated digits");
	}
	
	return 0;
 }
