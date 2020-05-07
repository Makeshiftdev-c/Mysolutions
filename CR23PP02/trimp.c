#include <stdio.h>
#include <stdlib.h>
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
			putchar(ch);
			ch = getc(stdin);
		}
		if (ch == EOF)
			break;
		putchar(ch);
	}

	return 0;
}
