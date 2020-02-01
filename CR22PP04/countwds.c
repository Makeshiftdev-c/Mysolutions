#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int ch, alpha_count = 0, num_words = 0;

	if (argc != 2)
	{
		fprintf(stderr, "usage: countwds filename\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(fp)) != EOF)
	{
		if (isalpha(ch))
			alpha_count++;
		if (isspace(ch) && alpha_count > 0)
		{
			num_words++;
			alpha_count = 0;
		}
	}
	if (ch == EOF && alpha_count > 0)
		num_words++;

	printf("Number of words in \"%s\": %d\n", argv[1], num_words);

	fclose(fp);
	return 0;
}
