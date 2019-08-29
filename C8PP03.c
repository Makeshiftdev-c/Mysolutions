/* Name: Abdirisak Arr
 * Date: 29/08/2018
 * Description: Prompts user to enter more than one number and checks for repeat digits
 */
 
 #include <stdio.h>
 #include <stdbool.h>
 
 #define N 10 // Change this to increase length of number that can be processed
 
 int main(void)
 {
 	bool digit_seen[N] = {false};
 	int digit, i = 0, j, repeated_digits[N] = {0};
 	long n;
 	
 	for (;;) // Repeatedly asks user for input, and outputs processed output
 	{
    	printf("Enter a positive %d digit integer: ", N);
    	scanf("%ld", &n);
    	
    	if (n <= 0) // Terminates program is a number less than or equal to zero is entered
    	{
    		break;
		}
		
		else
		{
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
	   	}
    
    for (j = 0; j < N; j++) // Clears arrays for subsequent input
    {
    	digit_seen[j] = false;
    	repeated_digits[j] = 0;
	}
	
	printf("\n");
	}
 	
	return 0;
 }
