#include <stdio.h>
#include <stdlib.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(int argc, char *argv[])
{
	char word[MAX_WORD_LEN + 2];
	FILE *fp_in, *fp_out;
	int word_len;

	if (argc != 3)
	{
		fprintf(stderr, "usage: justify source destination\n");
		exit(EXIT_FAILURE);
	}

	if ((fp_in = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can't locate %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((fp_out = fopen(argv[2], "w")) == NULL)
	{
		fprintf(stderr, "Can't create/open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	clear_line();
	for (;;)
	{
		word_len = read_word(fp_in, word, MAX_WORD_LEN + 1);
		if (word_len == 0)
		{
			flush_line(fp_out);
			fclose(fp_in);
			fclose(fp_out);
			return 0;
		}
		if (word_len > MAX_WORD_LEN)
			word[MAX_WORD_LEN] = '*';
		if (word_len + 1 > space_remaining())
		{
			write_line(fp_out);
			clear_line();
		}
		add_word(word);
	}
}
