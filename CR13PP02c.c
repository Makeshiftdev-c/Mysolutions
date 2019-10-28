/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 27/10/2019                                          *
* Description: Modification of remind.c program from Chapter*
*              13 Section 13.5. The program prints a        *
*              one-year reminder list as opposed to         *
*              one-month. Requires user to enter days in    *
*              the form month/day                           *
*************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void)
{
	char reminders[MAX_REMIND] [MSG_LEN];
	char date_str[6], msg_str[MSG_LEN + 1];
	int month, day, i, j, num_remind = 0;
	char buffflush;
	bool invalid = false;
	
	printf("-- One-Year Reminder List --\n\n");
	printf("#Enter date in mm/dd format\n");
	printf("#Enter zero to terminate\n\n");
	
	for (;;)
	{
		if (num_remind == MAX_REMIND)
		{
			printf("-- No space left --\n");
			break;
		}
		
		if (invalid)
		{
			printf("Please re-enter date and reminder: ");
			invalid = false;
		}
		else
		{
			printf("Enter date and reminder: ");
		}
		scanf("%2d/%2d", &month, &day);
		if (day == 0 || month == 0)
		{
			break;
		}
		else if (month < 0 || month > 12)
		{
			printf("Invalid input; month out of bounds, ignored\n");
			while ((buffflush = getchar()) != '\n')
			{
				;
			}
			invalid = true;
			continue;
		}
		else if (day < 0 || day > 31)
		{
			printf("Invalid input; day out of bounds, ignored\n");
			while ((buffflush = getchar()) != '\n')
			{
				;
			}
			invalid = true;
			continue;
		}
		sprintf(date_str, "%2d%c%2.2d", month, '/', day);
		read_line(msg_str, MSG_LEN);
		
		for (i = 0; i < num_remind; i++)
		{
			if (strcmp(date_str, reminders[i]) < 0)
			{
				break;
			}
		}
		for (j = num_remind; j > i; j--)
		{
			strcpy(reminders[j], reminders[j - 1]);
		}
		
		strcpy(reminders[i], date_str);
		strcat(reminders[i], msg_str);
		
		num_remind++;
	}
	
	printf("\n Date Reminder\n");
	for (i = 0; i < num_remind; i++)
	{
		printf("%s\n", reminders[i]);
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
