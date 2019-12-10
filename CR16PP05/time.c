#include "time.h"

#define MINS_IN_HOUR 60
#define NUM_FLIGHTS (sizeof(flight_times) / sizeof(flight_times[0]))

int total_minutes(int hours, int minutes)
{
	int total = (hours * MINS_IN_HOUR) + minutes;
	
	return total;
}

void find_closest(int minutes, int *departure, int *arrival)
{
	int i, prev;
	struct times
	{
		int departure;
		int arrival;
	};
	const struct times flight_times[] = {{480,   616},  {583,  712}
	,                                    {679,   811},  {767,  900}
	,                                    {840,   968},  {945, 1075}
	,                                    {1140, 1280}, {1305, 1438}};
	
	for (i = 1, prev = flight_times[0].departure; i < NUM_FLIGHTS; i++)
	{
		if (minutes < prev)
		{
			*departure = flight_times[0].departure;
			*arrival = flight_times[0].arrival;
			return;
		}
		else if (minutes >= prev && minutes <= flight_times[i].departure)
		{
			if (minutes < ((prev + flight_times[i].departure) / 2))
			{
				*departure = flight_times[i - 1].departure;
				*arrival = flight_times[i - 1].arrival;
				return;
			}
			else
			{
				*departure = flight_times[i].departure;
				*arrival = flight_times[i].arrival;
				return;
			}
		}
		else if (minutes >= flight_times[NUM_FLIGHTS - 1].departure)
		{
			*departure = flight_times[NUM_FLIGHTS -1].departure;
			*arrival = flight_times[NUM_FLIGHTS - 1].arrival;
			return;
		}
		prev = flight_times[i].departure;
	}
}

int to_24hour(int minutes)
{
	return (minutes / MINS_IN_HOUR);
}

int to_12hour(int minutes)
{
	int hours = minutes / MINS_IN_HOUR;
	
	if (hours <= 12)
	{
		return hours;
	}
	else
	{
		return hours - 12;
	}
}

int to_minutes(int minutes)
{
	return ((minutes) - ((minutes / MINS_IN_HOUR) * MINS_IN_HOUR));
}
