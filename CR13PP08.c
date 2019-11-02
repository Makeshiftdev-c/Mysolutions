/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 02/11/2019                                          *
* Description: Modification of Programming Project 5 from   *
*             chapter 7 so as to include the function:      *
*           int compute_scrabble_value(const char *word);   *
*************************************************************/

#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 12

int read_line(char str[], int n);
int compute_scabble_value(const char *word);

int main(void)
{
	char str[MAX_LENGTH];
	int value;
	
	printf("Enter a word: ");
	read_line(str, MAX_LENGTH);
	
	value = compute_scrabble_value(str);
	
	printf("Scrabble value: %d\n", value);
	
	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;
	
	while ((ch = getchar()) != '\n')
	{
		if (i < n)
		{
			str[i++] = ch;
		}
	}
	str[i] = '\0';
	return i;
}

int compute_scrabble_value(const char *word)
{
	int sum = 0;
	
	while (*word)
	{
		switch (tolower(*word))
		{
			case 'a': case 'e': case 'i': case 'l':
			case 'n': case 'o': case 'r': case 's':
			case 't': case 'u':
				sum++;
				break;
			case 'd': case 'g':
				sum += 2;
				break;
			case 'b': case 'c': case 'm': case 'p':
				sum += 3;
				break;
			case 'f': case 'h': case 'v': case 'w':
			case 'y':
				sum += 4;
				break;
			case 'k':
				sum += 5;
				break;
			case 'j': case 'x':
				sum += 8;
				break;
			case 'q': case 'z':
				sum += 10;
				break;
			default:
				break;
		}
		word++;
	}
	return sum;
}
