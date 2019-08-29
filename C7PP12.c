/* Name: Abdirisak Arr
 * Date: 24/08/2019
 * Description: Evaluates an expression
 */
 
 #include <stdio.h>
 
 int main(void)
 {
 	float sum = 0.00f, n, m;
 	signed char op;
 	
 	printf("Enter an expression: ");
 	scanf("%f", &n);
 	sum += n;
 	while ((op = getchar()) != '\n')
 	{
 		scanf("%f", &n);
 		switch (op)
 		{
 			case '+':
 				sum += n;
 				break;
 			case '-':
 				sum -= n;
 				break;
 			case '*':
 				sum *= n;
 				break;
 			case '/':
 				sum /= n;
 				break;
		}
	}
	
	printf("Value of expression: %g %c", sum, op);
	
	return 0;
 }
