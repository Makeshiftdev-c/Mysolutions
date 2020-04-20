#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_nums.h"
#include "format.h"

#define MAX_DIGITS 10

int main(int argc, char *argv[])
{
	FILE *fp;
	char buffer[15];
	int read_val, entries;

	if (argc != 2)
	{
		fprintf(stderr, "usage: ftelformat filename\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can't locate %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (entries = 0;; entries++)
	{
		read_val = read_numbers(fp, buffer, MAX_DIGITS);
		if (read_val == EOF)
			break;
		if (read_val < 10)
		{
			entries--;
			continue;
		}

		format(buffer);

		printf("%s\n", buffer);
	}

	fclose(fp);
	return 0;
}
