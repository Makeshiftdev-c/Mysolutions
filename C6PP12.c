/*Name: Abdirisak Arr
 *Date: 17/08/2019
 *Description: Extension of C6PP11 whereby user enter value of e and program continues adding terms until 
               the current term becomes less than e
 */
 
 #include <stdio.h>
 
 int main(void)
 {
 	float e, sum = 2.00f, counter = 2.00f, sum2 = 1.00f, hold;
 	
 	printf("Enter input value of e: ");
 	scanf("%f", &e);
 	
 	while (e >= sum)
 	{
 		hold = counter * sum2;
 		sum2 = hold;
 		counter++;
 		
 		sum = sum + (1.00f / hold);
	}
	
	printf("The approximate computed value of e is: %g", sum);
	
	return 0;
 }
