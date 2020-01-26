#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 100

int main(int argc, char *argv[])
{
	FILE *fp;
	char buff[BUFF_SIZE];
	int ch, i;

	if (argc < 2)
	{
		fprintf(stderr, "usage: fcat filename (or fcat filename1 filename2 ...)\n");
		exit(EXIT_FAILURE);
	}

	for (i = 1; i < argc; i++)
	{
		if ((fp = fopen(argv[i], "r")) == NULL)
		{
			fprintf(stderr, "Can't open %s", argv[i]);
			exit(EXIT_FAILURE);
		}
		while ((fgets(buff, sizeof(buff), fp)) != NULL)
			fprintf(stdout, "%s", buff);
		fclose(fp);
	}

	return 0;
}
