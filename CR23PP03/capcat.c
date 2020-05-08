#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch, prev;

	while ((ch = getc(stdin)) != EOF)
	{
		if (!isalpha(prev))
			ch = toupper(ch);
		putc(ch, stdout);
		prev = ch;
	}

	return 0;
}
