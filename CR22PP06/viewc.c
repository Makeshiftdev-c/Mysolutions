#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFF_SIZE 10

int main(int argc, char *argv[])
{
	FILE *fp;
	unsigned char buff[BUFF_SIZE];
	int i, n, m;

	if (argc != 2)
	{
		fprintf(stderr, "usage: viewcv2 filename\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("Offset               Bytes               Characters\n");
	printf("------   -----------------------------   ----------\n");

	for (i = 0;; i += BUFF_SIZE)
	{
		n = fread(buff, 1, BUFF_SIZE, fp);
		if (n == 0)
			break;
		printf("%6d   ", i);
		for (m = 0; m < n; m++)
			printf("%.2X ", buff[m]);
		for (; m < BUFF_SIZE; m++)
			printf("   ");
		printf("  ");
		for (m = 0; m < n; m++)
		{
			if (!isprint(buff[m]))
				buff[m] = '.';
			printf("%c", buff[m]);
		}
		printf("\n");
	}

	fclose(fp);
	return 0;
}
