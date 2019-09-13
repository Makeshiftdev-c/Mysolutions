/* Name: Abdirisak Arr
 * Date: 13/09/2019
 * Description: Modification of power function taking further advantage of index properties to improve speed  
 				of recursive power function call
 */
 
 #include <stdio.h>
 
 int power(int x, int n);
 
 int main(void)
 {
 	int x, n, value;
 	
 	printf("Enter an integer and its index (in x^n format): ");
 	scanf("%d^%d", &x, &n);
 	
 	value = power(x, n);
 	
 	printf("Value: %d", value);
 	
 	return 0;
 }
 
 int power(int x, int n)
 {
 	if (n == 0)
 	{
 		return 1;
	}
	if (n % 2 == 0)
	{
		int even_x = power(x, n / 2);
		return even_x * even_x;
	}
	else
	{
		return x * power(x, n - 1);
	}
 }
