#include <string.h>
#include <stdlib.h>
#include "format.h"

#define PUBLIC
#define PRIVATE static

PRIVATE void delimit(char *str)
{
	str[0] = '(';
	str[4] = ')';
	str[5] = ' ';
	str[9] = '-';
}

PUBLIC void format(char *str)
{
	int i, j;
	char *buffer = malloc(strlen(str));

	strcpy(buffer, str);
	delimit(str);

	for (i = 0, j = 1; i < strlen(buffer); i++, j++)
	{
		if (i == 3)
			j += 2;
		if (i == 6)
			j++;
		str[j] = buffer[i];
	}

	free(buffer);
}
