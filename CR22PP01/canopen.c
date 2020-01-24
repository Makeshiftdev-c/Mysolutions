#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int i;
	bool error = false;

	if (argc < 2)
	{
		printf("usage: canopen filename\n");
		exit(EXIT_FAILURE);
	}

	for (i = 1; i < argc; i++)
	{
		if ((fp = fopen(argv[i], "r")) == NULL)
		{
			printf("%s can't be opened\n", argv[i]);
			error = true;
		}
		else
		{
			printf("%s can be opened\n", argv[i]);
			fclose(fp);
		}
	}

	if (error)
		exit(EXIT_FAILURE);
	return 0;
}
