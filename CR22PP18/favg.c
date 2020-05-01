#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

#define MAX 10000

int compare_parts(const void *p, const void *q);

int main(int argc, char *argv[])
{
	FILE *fp;
	int buffer[MAX], i = 0;

	if (argc != 2)
	{
		fprintf(stderr, "usage: favg filename\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Can't locate %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fscanf(fp, "%d", &buffer[i++]) > 0)
		if (i == MAX)
			break;

	qsort(buffer, i - 1, sizeof(int), compare_parts);

	printf("Largest: %d\n", max(buffer, i - 1));
	printf("Smallest: %d\n", min(buffer, i - 1));
	printf("Median: %d\n", median(buffer, i - 1));

	return 0;
}

int compare_parts(const void *p, const void *q)
{
	const int *p1 = p;
	const int *q1 = q;

	if (*p1 < *q1)
		return -1;
	else if (*p1 == *q1)
		return 0;
	else
		return 1;
}
