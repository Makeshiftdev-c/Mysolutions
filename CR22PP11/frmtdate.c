#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	char *month_str[] = {"January",   "February", "March", "April"
	,                    "May",       "June",     "July",  "August"
	,                    "September", "October",  "November"
	,                    "December"};
	bool day_error = false, month_error = false;
	int month, day, year;

	if (argc < 2 || argc > 2)
	{
		fprintf(stderr, "usage: frmtdate date (mm-dd-yyyy or mm/dd/yyyy)\n");
		exit(EXIT_FAILURE);
	}

	if (sscanf(argv[1], "%d-%d-%d", &month, &day, &year) == 3)
		;
	else if (sscanf(argv[1], "%d/%d/%d", &month, &day, &year) == 3)
		;
	else
	{
		fprintf(stderr, "Date not in the proper form\n");
		exit(EXIT_FAILURE);
	}

	if (month < 1 || month > 12)
	{
		month_error = true;
	}
	
	switch (month)
	{
		case 1: case 3: case 5: case 7: case 8:
		case 10: case 12:
			if (day < 1 || day > 31)
				day_error = true;
			break;
		case 2:
			if (year % 4 == 0)
			{
				if (day < 1 || day > 29)
					day_error = true;
			}
			else
				if (day < 1 || day > 28)
					day_error = true;
			break;
		default:
			if (day < 1 || day > 30)
				day_error = true;
			break;
	}

	if (month_error || day_error)
	{
		if (month_error && day_error)
			fprintf(stderr, "Both month and day out of bounds\n");
		else if (month_error)
			fprintf(stderr, "Month out of bounds\n");
		else if (day_error)
			fprintf(stderr, "Day out of bounds\n");
		exit(EXIT_FAILURE);
	}

	printf("%s %d, %.4d\n", month_str[month - 1], day, year);

	return 0;
}
