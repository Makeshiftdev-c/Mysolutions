/*Name: Abdirisak Arr
 *Date: 20/09/2019
 *Description: Improved C3PP6 whereby user may add, multiply, divide, subract two factions (using +, *, / and - operators)
 */
 
 #include <stdio.h>
 
 int main(void)
 {
 	int new_numer, new_denom, numer1, denom1, numer2, denom2;
 	char op;
 	int n, m, r, gcd;
 	
 	printf("Enter two fractions and operation (separated by space): ");
 	scanf("%d/%d%d/%d", &numer1, &denom1, &numer2, &denom2);
 	if (getchar() == ' ')
 	{
 		getchar();
	}
	else
	{
		op = getchar();
	}
 	
 	switch (op) // handles different operations on fractions 
 	{
 		case '+':
 			new_denom = denom1 * denom2;
 			new_numer = (numer1 * denom2) + (numer2 * denom1);
 			break;
 		case '*':
 			new_denom = denom1 * denom2;
 			new_numer = numer1 * numer2;
 			break;
 		case '/':
 			new_denom = denom1 * numer2;
 			new_numer = denom2 * numer1;
 			break;
 		case '-':
 			new_denom = denom1 * denom2;
 			new_numer = (numer1 * denom2) - (numer2 * denom1);
 			break;
	}
	
	/* Set up of variables for applying algorithm to determine GCD */
	n = new_numer; 
	m = new_denom;
	
	for (;;) // Ueclids algoirthm for GCD
	{
		if (n == 0)
		{
			gcd = m;
			break;
		}
		else
		{
			r = m % n;
			m = n;
			n = r;
		}
	}
	
	if (new_numer >= new_denom && new_numer % new_denom == 0) // simplifies value/expression then prints
	{
		printf("The result is: %d", new_numer / new_denom);
	}
	else
	{
		printf("The result is: %d/%d", new_numer / gcd, new_denom / gcd);
	}
	
	return 0;
 }
