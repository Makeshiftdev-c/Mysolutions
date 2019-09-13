/* Name: Abdirisak Arr
 * Date: 13/09/2019
 * Description: Asks user to enter a value for x, then calculates the value of a polynomial expression
 */
 
 #include <stdio.h>
 
 int cal_poly(int x);
 
 int main(void)
 {
 	int comp_val, x;
 	
 	printf("Enter value of x: ");
 	scanf("%d", &x);
 	
 	comp_val = cal_poly(x);
 	
 	printf("The value of the expression is: %d", comp_val);
 	
 	return 0;
 }
 
 int cal_poly(int x)
 {
 	int value;
 	
 	value = (3 * x * x * x * x * x) + (2 * x * x * x * x) - (5 * x * x * x) - (x * x) + (7 * x) - 6;
 	
 	return value;
 }
