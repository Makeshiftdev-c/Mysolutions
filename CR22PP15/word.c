#include <stdio.h>
#include "word.h"

#define PUBLIC
#define PRIVATE static

PRIVATE int read_char(FILE *input)
{
	int ch = getc(input);

	if (ch == '\n' || ch == '\t')
		return ' ';
	return ch;
}

PUBLIC int read_word(FILE *input, char *word, int len)
{
	int ch, pos = 0;

	while ((ch = read_char(input)) == ' ')
		;
	while (ch != ' ' && ch != EOF)
	{
		if (pos < len)
			word[pos++] = ch;
		ch = read_char(input);
	}
	word[pos] = '\0';
	return pos;
}
