#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 512

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
	FILE *source_fp, *dest_fp;
	BYTE buffer[BUFF_SIZE];
	int n;

	if (argc != 3)
	{
		fprintf(stderr, "usage: fcopy source destination\n");
		exit(EXIT_FAILURE);
	}

	if ((source_fp = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Can't locate %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((dest_fp = fopen(argv[2], "wb")) == NULL)
	{
		fprintf(stderr, "Can't create/open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while ((n = fread(buffer, sizeof(BYTE), BUFF_SIZE, source_fp)) > 0)
		fwrite(buffer, sizeof(BYTE), n, dest_fp);

	fclose(source_fp);
	fclose(dest_fp);
	return 0;
}
