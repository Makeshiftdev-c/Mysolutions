/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 01/10/2019                                          *
* Description:  Modification of Programming Project 8 from  *
*               Chapter 5; addition of function:            *
*           void find_closest_flight(int desired_time,      *
*                                    int *departure_time,   *
*                                    int *arrival_time);    *
*************************************************************/

#include <stdio.h>

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

/************************************************************
* main: Reads user input; converts input to minutes since   *
*       midnight; calls find_cloest_flight; processes       *
*       argument variables for outputing.                   *
*************************************************************/

int main(void)
{
	int hh, mm, minute_time, departure, arrival;
	int hh_dep, mm_dep, hh_arr, mm_arr;
	char dep_m_prefix, arr_m_prefix;
	
	printf("Entera 24-hour time: ");
	scanf("%d:%d", &hh, &mm);
	
	minute_time = (hh * 60) + mm;
	find_closest_flight(minute_time, &departure, &arrival);
	
	/* minute to hour and minute conversion for output*/
	hh_dep = departure / 60;
	mm_dep = departure - (hh_dep * 60);
	hh_arr = arrival / 60;
	mm_arr = arrival - (hh_arr * 60);
	
	/* 12-hour am xor pm */
	if (hh_dep <= 11)
	{
		dep_m_prefix = 'a';
	}
	else if (hh_dep >= 12)
	{
		dep_m_prefix = 'p';
	}
	if (hh_arr <= 11)
	{
		arr_m_prefix = 'a';
	}
	else if (hh_arr >= 12)
	{
		arr_m_prefix = 'p';
	}
	
	/* 24-hour to 12-hour conversion */
	if (hh_dep > 12)
	{
		hh_dep -= 12;
	}
	else if (hh_dep == 0)
	{
		hh_dep = 12;
	}
	
	if (hh_arr > 12)
	{
		hh_arr -= 12;
	}
	else if (hh_dep == 0)
	{
		hh_arr == 12;
	}
	
	
	printf("Closest depature time is %d:%.2d %c.m., ", hh_dep, mm_dep, dep_m_prefix);
	printf("arriving at %d:%.2d %c.m.", hh_arr, mm_arr, arr_m_prefix);
	
	return 0;
}

/************************************************************
* find_closest_flight: Assigns value to arguemnts that      *
*                      correspond to pointer parameters     *
*                      using argument that is passed to     *
*                      desired_time parameter.              *
*************************************************************/

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
	if (desired_time < 532)
	{
		*departure_time = 480;
		*arrival_time = 616;
	}
	else if (desired_time >= 532 && desired_time < 630)
	{
		*departure_time = 583;
		*arrival_time = 712;
	}
	else if (desired_time >= 630 && desired_time < 724)
	{
		*departure_time = 679;
		*arrival_time = 811;
	}
	else if (desired_time >= 724 && desired_time < 804)
	{
		*departure_time = 767;
		*arrival_time = 900;
	}
	else if (desired_time >= 804 && desired_time < 893)
	{
		*departure_time = 840;
		*arrival_time = 968;
	}
	else if (desired_time >= 893 && desired_time < 1043)
	{
		*departure_time = 945;
		*arrival_time = 1075;
	}
	else if (desired_time >= 1043 && desired_time < 1223)
	{
		*departure_time = 1140;
		*arrival_time = 1280;
	}
	else
	{
		*departure_time = 1305;
		*arrival_time = 1438;
	}
}
