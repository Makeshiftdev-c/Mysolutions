#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int ch, num_ch = 0;

	if (argc != 2)
	{
		fprintf(stderr, "usage: chcount filename\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF)
	{
		if (!iscntrl(ch))
			num_ch++;
	}

	printf("Number of characters in \"%s\": %d\n", argv[1], num_ch);

	fclose(fp);
	return 0;
}
