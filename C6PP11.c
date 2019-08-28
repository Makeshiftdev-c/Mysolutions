/*Name: Abdirisak Arr
 *Date: 16/08/2019
 *Description: Approximates e by computing the value of 1 + 1/1!+ 1/2! + ... + 1/n!
 */
 
 #include <stdio.h>
 
 int main(void)
 {
 	float n, sum = 2.00f, counter = 2.00f, sum2 = 1.00f, hold;
 	
 	printf("Enter value of n: ");
 	scanf("%f", &n);
 	
 	while (n > 1)
 	{
 		hold = counter * sum2;
 		sum2 = hold;
 		counter++;
 		
 		sum = sum + (1.00f / hold);
 		n--;
	}
	
	printf("The approximate value of e is: %f", sum);
	
	return 0;
 }
