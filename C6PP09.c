/*Name: Abdirisak Arr
 *Date: 11/08/2019
 *Description: Calculates the remaining balance on a loan. Asks the user to enter the number of payments
               and then displays the balance remaining after each of these payments
 */
 
 #include <stdio.h>
 
 int main(void)
 {
 	int i;
 	float balance, monthly_p, interest, monthly_b;
 	
 	printf("Enter amount of loan: ");
 	scanf("%f", &balance);
 	printf("Enter interest rate: ");
 	scanf("%f", &interest);
 	printf("Enter monthly payment: ");
 	scanf("%f", &monthly_p);
 	printf("Enter number of payments: ");
 	scanf("%d", &i);
 	
 	interest = ((interest / 100.00f) / 12);
 	monthly_b = balance;
 	while (i > 0)
 	{
 		monthly_b = ((monthly_b - monthly_p) + (monthly_b * interest));
 		i--;
 		printf("Balance remaining after each monthly payment: $%.2f\n", monthly_b);
	}
 	
 	return 0;
 }
