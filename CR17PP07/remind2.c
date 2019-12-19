#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "readline.h"

#define MAX_REMIND 50
#define MSG_LEN 60

struct vstring
{
	int len;
	char reminder[];
};

int main(void)
{
	struct vstring *reminders[MAX_REMIND];
	char day_str[3], msg_str[MSG_LEN + 1];
	int day, i, j, num_reminds = 0;
	
	for (;;)
	{
		if (num_reminds == MAX_REMIND)
		{
			printf("-- No space left --\n");
			break;
		}
		
		printf("Enter day and reminder: ");
		scanf("%2d", &day);
		if (day == 0)
		{
			break;
		}
		sprintf(day_str, "%2d", day);
		read_line(msg_str, MSG_LEN);
		
		for (i = 0; i < num_reminds; i++)
		{
			if (strcmp(day_str, reminders[i]->reminder) < 0)
			{
				break;
			}
		}
		for (j = num_reminds; j > i; j--)
		{
			reminders[j] = reminders[j - 1];
		}
		
		reminders[i] = malloc(2 + sizeof(struct vstring) + strlen(msg_str) + 1);
		reminders[i]->len = strlen(msg_str);
		if (reminders[i] == NULL)
		{
			printf("-- No space left --\n");
			break;
		}
		
		strcpy(reminders[i]->reminder, day_str);
		strcat(reminders[i]->reminder, msg_str);
		
		num_reminds++;
	}
	
	printf("\nDay Reminder\n");
	for (i = 0; i < num_reminds; i++)
	{
		printf(" %s\n", reminders[i]->reminder);
	}
	
	return 0;
}
