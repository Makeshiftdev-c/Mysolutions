#include <stdio.h>

#define TAX 5.0f/100.0f

int main(void)
{
	float input;

	printf("Enter an amount: ");
	scanf("%f", &input);

	input += (input * TAX);

	printf("With tax added: $%.2f\n", input);

	return 0;
}
