#include <stdio.h>
#include "time.h"

#define MIDDAY 12

int main(void)
{
	int hh, mm, since_midnight;
	int departure, arrival;
	
	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hh, &mm);
	
	since_midnight = total_minutes(hh, mm);
	find_closest(since_midnight, &departure, &arrival);
	
	printf("Closest departure time is %d:%.2d", to_12hour(departure), to_minutes(departure));
	if (to_24hour(departure) < MIDDAY)
	{
		printf(" a.m.,");
		printf(" arriving at %d:%.2d ", to_12hour(arrival), to_minutes(arrival));
		if (to_24hour(arrival) < MIDDAY)
		{
			printf("a.m.");
		}
		else
		{
			printf("p.m.");
		}
	}
	else
	{
		printf(" p.m.,");
		printf(" arriving at %d:%.2d ", to_12hour(arrival), to_minutes(arrival));
		if (to_24hour(arrival) < MIDDAY)
		{
			printf("a.m.");
		}
		else
		{
			printf("p.m.");
		}
	}
	printf("\n");
	
	return 0;
}
