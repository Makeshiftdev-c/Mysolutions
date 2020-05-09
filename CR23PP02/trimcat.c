#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;

	for (;;)
	{
		while (isspace(ch = getc(stdin)))
			;
		while (ch != '\n' && ch != EOF)
		{
			putc(ch, stdout);
			ch = getc(stdin);
		}
		if (ch == EOF)
			break;
		putc(ch, stdout);
	}

	return 0;
}
