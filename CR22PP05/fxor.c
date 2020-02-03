#include <stdio.h>
#include <stdlib.h>

#define KEY '&'
#define BUFF_SIZE 10

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
	FILE *fp_in, *fp_out;
	BYTE buff[BUFF_SIZE];
	int n, m;

	if (argc != 3)
	{
		fprintf(stderr, "usage: fxor source-filename destination-filename\n");
		exit(EXIT_FAILURE);
	}

	if ((fp_in = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((fp_out = fopen(argv[2], "wb")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[2]);
		fclose(fp_in);
		exit(EXIT_FAILURE);
	}

	while ((n = fread(buff, 1, BUFF_SIZE, fp_in)) != 0)
	{
		for (m = 0; m < n; m++)
			buff[m] ^= KEY;
		fwrite(buff, 1, n, fp_out);
	}

	fclose(fp_in);
	fclose(fp_out);
	return 0;
}
