#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFF_SIZE 10

int main(int argc, char *argv[])
{
	FILE *fp;
	int i, n, m, ch;
	unsigned char buff[BUFF_SIZE];

	if (argc != 2)
	{
		fprintf(stderr, "usage: viewc filename\n");
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
		if (ch == EOF)
			break;
		printf("%6d   ", i);
		for (n = 0; n < BUFF_SIZE && (ch = getc(fp)) != EOF; n++)
		{
			buff[n] = ch;
			printf("%.2X ", buff[n]);
		}
		for (m = n; m < BUFF_SIZE; m++)
			printf("   ");
		printf("  ");
		for (m = 0; m < n; m++)
		{
			if (iscntrl(buff[m]))
				buff[m] = '.';
			printf("%c", buff[m]);
		}
		printf("\n");
	}

	fclose(fp);
	return 0;

}
