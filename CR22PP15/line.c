#include <stdio.h>
#include <string.h>
#include "line.h"

#define PUBLIC
#define PRIVATE static

#define MAX_LINE_LEN 60

PRIVATE char line[MAX_LINE_LEN + 1];
PRIVATE int line_len = 0;
PRIVATE int num_words = 0;

PUBLIC void clear_line(void)
{
	line[0] = '\0';
	line_len = 0;
	num_words = 0;
}

PUBLIC void add_word(const char *word)
{
	if (num_words > 0)
	{
		line[line_len] = ' ';
		line[line_len + 1] = '\0';
		line_len++;
	}
	strcat(line, word);
	line_len += strlen(word);
	num_words++;
}

PUBLIC int space_remaining(void)
{
	return MAX_LINE_LEN - line_len;
}

PUBLIC void write_line(FILE *output)
{
	int extra_spaces, spaces_to_insert, i, j;

	extra_spaces = space_remaining();
	for (i = 0; i < line_len; i++)
	{
		if (line[i] != ' ')
			putc(line[i], output);
		else
		{
			spaces_to_insert = extra_spaces / (num_words - 1);
			for (j = 1; j <= spaces_to_insert + 1; j++)
				putc(' ', output);
			extra_spaces -= spaces_to_insert;
			num_words--;
		}
	}
	putc('\n', output);
}

PUBLIC void flush_line(FILE *output)
{
	if (line > 0)
		fputs(line, output);
}
