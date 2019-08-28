/*Name: Abdirisak Arr
 *Date: 18/08/2019
 *Description: Sums two floating point double values
 */
 
 #include <stdio.h>
 
 int main(void)
 {
 	double value, sum = 0;
 	
 	printf("Enter a floating point value (Enter zero to commense): ");
 	
 	scanf("%lf", &value);
 	while (value != 0)
 	{
 		sum += value;
 		scanf("%lf", &value);
	}
	
	printf("The sum is %f", sum);
	
	return 0;
 }
