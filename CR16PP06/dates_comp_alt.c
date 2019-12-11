#include <stdio.h>

struct date
{
	int year;
	int month;
	int day;
} date1, date2;

int compare_dates(struct date d1, struct date d2);
void print(int comparison);

int main(void)
{
	int outcome;
		
	printf("Enter first date (mm/dd/yy): ");
	scanf("%2d/%2d/%2d", &date1.month, &date1.day, &date1.year);
	
	printf("Enter second date (mm/dd/yy): ");
	scanf("%2d/%2d/%2d", &date2.month, &date2.day, &date2.year);
	
	outcome = compare_dates(date1, date2);
	
	print(outcome);
	
	return 0;
}

int compare_dates(struct date d1, struct date d2)
{
	if (d1.year - d2.year < 0)
	{
		return -1;
	}
	else if (d1.year - d2.year > 0)
	{
		return 1;
	}
	else
	{
		if (d1.month - d2.month < 0)
		{
			return -1;
		}
		else if (d1.month - d2.month > 0)
		{
			return 1;
		}
		else
		{
			if (d1.day - d2.day < 0)
			{
				return -1;
			}
			else if (d1.day - d2.day > 0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}

void print(int outcome)
{
	if (outcome > 0)
	{
		printf("%d/%d/%.2d", date2.month, date2.day, date2.year);
		printf(" is earlier than ");
		printf("%d/%d/%.2d", date1.month, date1.day, date1.year);
	}
	else if (outcome < 0)
	{
		printf("%d/%d/%.2d", date1.month, date1.day, date1.year);
		printf(" is earlier than ");
		printf("%d/%d/%.2d", date2.month, date2.day, date2.year);
	}
	else
	{
		printf("Identical dates entered");
	}
	printf("\n");
}
