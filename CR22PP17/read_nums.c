#include <stdio.h>
#include <ctype.h>
#include "read_nums.h"

#define PUBLIC
#define PRIVATE static

PRIVATE int is_digit(const char ch)
{
	if (ch >= '0' && ch <= '9')
		return 1;
	return 0;
}

PUBLIC int read_numbers(FILE *source, char str[], int n)
{
	int ch, pos = 0;

	while (isspace(ch = getc(source)))
		;
	while (ch != '\n' && ch != EOF)
	{
		if (pos < n && is_digit(ch))
			str[pos++] = ch;
		ch = getc(source);
	}
	str[pos] = '\0';
	if (ch == EOF)
		return EOF;
	return pos;
}
