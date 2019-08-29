/* Name: Abdirisak Arr
 * Date: 24/08/2019
 * Description: Uses Newton's method to compute the square root of a positive floating-point number
 */
 
 #include <stdio.h>
 #include<math.h>
 
 int main(void)
 {
 	double x, old_y = 0, new_y = 1.00, average;
 	
 	printf("Enter a positive number: ");
 	scanf("%lf", &x);
 	
 	while (fabs(old_y - new_y) > (.00001 * new_y))
 	{
 		average = (new_y + (x / new_y)) / 2.00;
 		old_y = new_y;
 		new_y = average;
 		printf("%f\n", new_y);
	}
 	
 	printf("Square root: %.5f", average);
 	
 	return 0;
 }
