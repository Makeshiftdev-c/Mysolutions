/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 04/11/2019                                          *
* Description: Modification of Programming Project 15 from  *
*              from Chapter 8 so as to include the function:*
*            void encrypt(char *message, int shift)         *
*************************************************************/

#include <stdio.h>

#define MAX_LENGTH 80

int read_line(char str[], int n);
void encrypt(char *message, int shift);

int main(void)
{
	char input[MAX_LENGTH];
	int shift_num;
	char *p;
	
	printf("Enter message to be encrypted: ");
	read_line(input, MAX_LENGTH);
	
	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift_num);
	
	encrypt(input, shift_num);
	
	printf("Encrypted message: ");
	for (p = input; *p != '\0'; p++)
	{
		putchar(*p);
	}
	
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

void encrypt(char *message, int shift)
{
	while (*message)
	{
		if (*message >= 'a' && *message <= 'z')
		{
			*message = (((*message - 'a') + shift) % 26 + 'a');
		}
		else if (*message >= 'A' && *message <= 'Z')
		{
			*message = (((*message - 'A') + shift) % 26 + 'A');
		}
		message++;
	}
}
