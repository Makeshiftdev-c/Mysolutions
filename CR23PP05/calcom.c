#include <stdio.h>
#include <math.h>

double sumapp(double amount, double years, double interest);

int main(void)
{
	double amount, r, t;
	
	printf("Enter original amount deposited: $");
	scanf("%lf", &amount);
	printf("Enter interest rate (percentage): ");
	scanf("%lf%*s", &r);
	printf("Enter number of years elapsed: ");
	scanf("%lf%*s", &t);

	printf("Final value of account: $%.2f\n", sumapp(amount, t, r / 100));

	return 0;
}

double sumapp(double amount, double years, double interest)
{
	double final_value = amount * exp(interest * years);
	return final_value;
}
