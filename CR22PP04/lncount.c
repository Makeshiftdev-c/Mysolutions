#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int ch, num_lns = 0;

	if (argc != 2)
	{
		fprintf(stderr, "usage: lncount filename\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF)
		if (ch == '\n')
			num_lns++;

	printf("Number of lines in \"%s\": %d\n", argv[1], num_lns);

	fclose(fp);
	return 0;
}
