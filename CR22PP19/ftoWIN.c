#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *src, *dest;
	int ch;

	if (argc != 3)
	{
		fprintf(stderr, "usage: ftoWIN source destination\n");
		exit(EXIT_FAILURE);
	}

	if ((src = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Can't locate %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((dest = fopen(argv[2], "wb")) == NULL)
	{
		fprintf(stderr, "Can't create/open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(src)) != EOF)
	{
		if (ch == '\n')
			putc('\r', dest);
		putc(ch, dest);
	}

	fclose(src);
	fclose(dest);
	return 0;
}
