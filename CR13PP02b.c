/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 26/10/2019                                          *
* Description: Modification of remind.c program from        *
*              Chapter 13 Section 13.5, allowing for the    *
*              user to a day, a 24-hour time, and a         *
*              reminder                                     *
*************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void)
{
	char reminders[MAX_REMIND] [MSG_LEN + 3];
	char day_str[4], msg_str[MSG_LEN + 1];
	char time_str[6], day_time_str[9];
	int day, i, j, num_remind = 0;
	char time_delimiter;
	int hh, mm;
	
	for (;;)
	{
		if (num_remind == MAX_REMIND)
		{
			printf("-- No space left --\n");
			break;
		}
		
		printf("Enter a day, 24-hour time, and reminder: ");
		scanf("%2d", &day);
		if (day == 0)
		{
			break;
		}
		sprintf(day_str, "%2d%c", day, ' ');
		scanf("%2d%c%2d", &hh, &time_delimiter, &mm);
		sprintf(time_str, "%2.2d%c%.2d", hh, time_delimiter, mm);
		strcpy(day_time_str, day_str);
		strcat(day_time_str, time_str);
		read_line(msg_str, MSG_LEN);
		
		for (i = 0; i < num_remind; i++)
		{
			if (strcmp(day_time_str, reminders[i]) < 0)
			{
				break;
			}
		}
		for (j = num_remind; j > i; j--)
		{
			strcpy(reminders[j], reminders[j - 1]);
		}
			
		strcpy(reminders[i], day_time_str);
		strcat(reminders[i], msg_str);
		
		num_remind++;
	}
	
	printf("\nDay Time  Reminder\n");
	for (i = 0; i < num_remind; i++)
	{
		printf(" %s\n", reminders[i]);
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
