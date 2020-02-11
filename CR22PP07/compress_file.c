#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
	FILE *fp_in, *fp_out;
	BYTE datum, prev;
	BYTE rep_cnt = 1;
	int n;

	if (argc != 2)
	{
		fprintf(stderr, "usage: compress_file filename\n");
		exit(EXIT_FAILURE);
	}

	if ((fp_in = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((fp_out = fopen(strcat(argv[1], ".rle"), "wb")) == NULL)
	{
		fprintf(stderr, "Could not create %s\n", strcat(argv[1], ".rle"));
		fclose(fp_in);
		exit(EXIT_FAILURE);
	}

	prev = getc(fp_in);
	while ((n = fread(&datum, sizeof(BYTE), 1, fp_in)) != 0)
	{
		if (datum == prev)
			rep_cnt++;
		else
		{
			putc(rep_cnt, fp_out);
			putc(prev, fp_out);
			prev = datum;
			rep_cnt = 1;
		}
	}

	fclose(fp_in);
	fclose(fp_out);
	return 0;
}
