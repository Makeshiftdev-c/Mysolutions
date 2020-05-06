#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int a, b, c;
	double x1, x2;
	double determinant;

	printf("Enter coefficient a: ");
	scanf("%d", &a);
	printf("Enter coefficient b: ");
	scanf("%d", &b);
	printf("Enter coefficient c: ");
	scanf("%d", &c);

	determinant = (b * b) - (4 * a * c);
	if (determinant < 0)
	{
		fprintf(stderr, "Error: equation has complex roots\n");
		exit(EXIT_FAILURE);
	}

	x1 = ((double) -b + sqrt(determinant)) / (2 * a);
	x2 = ((double) -b - sqrt(determinant)) / (2 * a);

	printf("x = %g or x = %g\n", x1, x2);

	return 0;
}
