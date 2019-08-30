/* Name: Abdirisak Arr
 * Date: 30/08/2019
 * Description: Prompts user to enter more than one number and checks for repeat digits
 */
 
 #include <stdio.h>
 #include <stdbool.h>
 
 #define N 10 // Change this to increase maximum number of digits input can have
 
 int main(void)
 {
 	bool digit_seen[N] = {false};
 	int digit, i = 0, j, repeated_digits[N] = {0};
 	long n, inside_n;
 	
 	printf("Program prompts user to enter more than one number and checks for repeat digits.\n");
 	printf("Enter postive integers (separated by space, input zero to exit): ");
 	
 	scanf("%ld", &n);
 	inside_n = n; // inside_n variable is for processing individual values entered by user
 	while (n > 0)
 	{
 		    inside_n = n;
 		 	while (inside_n > 0) //Checks for repeat digits and saves them in repeated_digits array for processing
        	{
 	        	digit = inside_n % 10;
 	        	if (digit_seen[digit])
 	        	{
 	        		repeated_digits[i] = digit;
 	        		i++;
	        	}
	        	digit_seen[digit] = true;
		        inside_n /= 10;
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
        	
        	for (j = 0, i = 0; j < N; j++) // Clears arrays and variables for subsequent input
            {
            	digit_seen[j] = false;
            	repeated_digits[j] = 0;
        	}
        	
        	printf("\n");
        	scanf("%ld", &n);
    }
	
	return 0;
	
}
