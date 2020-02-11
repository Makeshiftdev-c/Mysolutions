#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned char BYTE;

bool is_RLEcomp(const char *filename);

int main(int argc, char *argv[])
{
	char *outputf_name = malloc(1 * strlen(argv[1]) - 3);
	FILE *fp_in, *fp_out;
	BYTE datum;
	int rep, n;

	if (argc != 2)
	{
		fprintf(stderr, "usage: uncompress_file filename\n");
		exit(EXIT_FAILURE);
	}

	if (!is_RLEcomp(argv[1]))
	{
		fprintf(stderr, "Error: %s is not RLE compressed\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((fp_in = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	outputf_name = malloc(strlen(argv[1]) - 3);
	if (outputf_name == NULL)
	{
		fprintf(stderr, "%.*s could not be created\n", (int) strlen(argv[1]) - 4, argv[1]);
		exit(EXIT_FAILURE);
	}

	strncpy(outputf_name, argv[1], strlen(argv[1]) - 4);
	if ((fp_out = fopen(outputf_name, "wb")) == NULL)
	{
		fprintf(stderr, "%s could not be created\n", outputf_name);
		free(outputf_name);
		fclose(fp_in);
		exit(EXIT_FAILURE);
	}
	free(outputf_name);

	for (;;)
	{
		rep = getc(fp_in);
		n = fread(&datum, sizeof(BYTE), 1, fp_in);
		if (n == 0)
			break;
		while (rep > 0)
		{
			putc(datum, fp_out);
			rep--;
		}
	}

	fclose(fp_in);
	fclose(fp_out);
	return 0;
}

bool is_RLEcomp(const char *filename)
{
	const char *p = filename;

	while (*p)
		p++;
	p -= 4;
	if (strcmp(p, ".rle") == 0)
		return true;
	return false;
}
