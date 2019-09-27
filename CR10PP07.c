/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 26/09/2019                                          *
* Description: Prompts user for a number and then displays  *
*              the number, using characters to simulate the *
*              effect of a seven-segmeent display.          *
*************************************************************/

#include <stdio.h>

#define MAX_DIGITS 10
#define SEGMENTS 7

/* external variables */
const int segments[MAX_DIGITS] [SEGMENTS] = {{1, 1, 1, 1, 1, 1, 0}   /* 0 */
,                                            {0, 1, 1, 0, 0, 0, 0}   /* 1 */
,                                            {1, 1, 0, 1, 1, 0, 1}   /* 2 */
,                                            {1, 1, 1, 1, 0, 0, 1}   /* 3 */
,                                            {0, 1, 1, 0, 0, 1, 1}   /* 4 */
,                                            {1, 0, 1, 1, 0, 1, 1}   /* 5 */
,                                            {1, 0, 1, 1, 1, 1, 1}   /* 6 */
,                                            {1, 1, 1, 0, 0, 0, 0}   /* 7 */
,                                            {1, 1, 1, 1, 1, 1, 1}   /* 8 */
,                                            {1, 1, 1, 1, 0, 1, 1}}; /* 9 */
char digits[3] [MAX_DIGITS * 4];

/* prototypes */
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

/************************************************************
* main: Calls clear_digits_array; reads user input, ignoring*
*       non-numerical characters; passes each digit in input*
*       and its relative position to process_digit; calls   *
*       print_digits_array.                                 *
*************************************************************/

int main(void)
{
	char input_ch;
	int digit, position = 0;
	
	clear_digits_array();
	
	printf("Enter a number: ");
	while ((input_ch = getchar()) != '\n')
	{
		switch (input_ch)
		{
			case '0':
				digit = 0;
				process_digit(digit, position);
				break;
			case '1':
				digit = 1;
				process_digit(digit, position);
				break;
			case '2':
				digit = 2;
				process_digit(digit, position);
				break;
			case '3':
				digit = 3;
				process_digit(digit, position);
				break;
			case '4':
				digit = 4;
				process_digit(digit, position);
				break;
			case '5':
				digit = 5;
				process_digit(digit, position);
				break;
			case '6':
				digit = 6;
				process_digit(digit, position);
				break;
			case '7':
				digit = 7;
				process_digit(digit, position);
				break;
			case '8':
				digit = 8;
				process_digit(digit, position);
				break;
			case '9':
				digit = 9;
				process_digit(digit, position);
				break;
			default:
				position--;
		}
		
		if (position >= MAX_DIGITS)
		{
			break;
		}
		
		position++;
	}
	
	print_digits_array();
	
	return 0;
}

/************************************************************
* clear_digits_array: Stores blank characters into all      *
*                     elements of external array variable,  *
*                     digits.                               *
*************************************************************/

void clear_digits_array(void)
{
	int row, column;
	
	for (row = 0; row < MAX_DIGITS; row++)
	{
		for (column = 0; column < SEGMENTS; column++)
		{
			digits[row] [column] = ' ';
		}
	}
}

/************************************************************
* process_digit: Stores the seven-segment representation    *
*                of digit into a specified position in      *
*                the external array variable, digits.       *
*************************************************************/

void process_digit(int digit, int position)
{
	int reference;
	
	switch(position)
	{
		case 0:
			reference = 0;
			break;
		case 1:
			reference = 4;
			break;
		case 2:
			reference = 8;
			break;
		case 3:
			reference = 12;
			break;
		case 4:
			reference = 16;
			break;
		case 5:
			reference = 20;
			break;
		case 6:
			reference = 24;
			break;
		case 7:
			reference = 28;
			break;
		case 8:
			reference = 32;
			break;
		case 9:
			reference = 36;
			break;
	}
	
	/* horizontal segments */
	if (segments[digit] [0] == 1)
	{
		digits[0] [reference + 1] = '_';
	}
	if (segments[digit] [6] == 1)
	{
		digits[1] [reference + 1] = '_';
	}
	if (segments[digit] [3] == 1)
	{
		digits[2] [reference + 1] = '_';
	}
	
	/* first-column vertical segments */
	if (segments[digit] [4] == 1)
	{
		digits[2] [reference] = '|';
	}
	if (segments[digit] [5] == 1)
	{
		digits[1] [reference] = '|';
	}
	
	/* second-column vertical segments */
	if (segments[digit] [1] == 1)
	{
		digits[1] [reference + 2] = '|';
	}
	if (segments[digit] [2] == 1)
	{
		digits[2] [reference + 2] = '|';
	}
}

/************************************************************
* print_digits_array: Displays the rows of the digits array,*
*                     each on a single line.                *
*************************************************************/

void print_digits_array(void)
{
	int row, column;
	
	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < (MAX_DIGITS * 4); column++)
		{
			printf("%c", digits[row] [column]);
		}
		printf("\n");
	}
}
