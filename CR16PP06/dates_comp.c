#include <stdio.h>

struct date
{
	int year;
	int month;
	int day;
};

int compare_dates(struct date d1, struct date d2);

int main(void)
{
	struct date date1, date2;
	int outcome;
	
	printf("Enter first date (mm/dd/yy): ");
	scanf("%2d/%2d/%2d", &date1.month, &date1.day, &date1.year);
	
	printf("Enter second date (mm/dd/yy): ");
	scanf("%2d/%2d/%2d", &date2.month, &date2.day, &date2.year);
	
	outcome = compare_dates(date1, date2);
	
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
	
	return 0;
}

int compare_dates(struct date d1, struct date d2)
{
	int result = 0;
	
	d1.year > d2.year ? result = 1 : result;
	if (result > 0)
	{
		return result;
	}
	d2.year > d1.year ? result = -1 : result;
	if (result < 0)
	{
		return result;
	}
	d1.month > d2.month ? result = 1 : result;
	if (result > 0)
	{
		return result;
	}
	d2.month > d1.month ? result = -1 : result;
	if (result < 0)
	{
		return result;
	}
	d1.day > d2.day ? result = 1 : result;
	if (result > 0)
	{
		return result;
	}
	d2.day > d1.day ? result = -1 : result;
						
	return result;
}
