/* Name: Abdirisak Arr
 * Date: 24/08/2019
 * Description: Computes the factorial of a positive integer
 */
 
 #include <stdio.h>
 
 int main(void)
 {
 	int i, j;
	short int sum = 1;
 	
 	printf("Enter a positive integer: ");
 	scanf("%d", &i);
 	
 	for (j = i; j > 0; j--)
 	{
 		sum *= j;
	}
	
	printf("Factorial of %d: %hd", i, sum);
	
	return 0;
 }
 
 /* Largest value of n for which program correctly prints the factorial of n is 7 */ 
