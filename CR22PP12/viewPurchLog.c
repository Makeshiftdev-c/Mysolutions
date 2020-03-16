#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int day, month, year;
	float price;
	int number;
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "usage: viewPurchLog filename\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}


	printf("Item     Unit          Purchase\n");
	printf("         Price         Date\n");
	while (fscanf(fp, "%d,%f,%d/%d/%d", &number, &price, &month, &day, &year) != EOF)
	{
		printf("%-9d$%7.2f      %d/%d/%.4d\n", number, price, month, day, year);
	}

	return 0;
}
