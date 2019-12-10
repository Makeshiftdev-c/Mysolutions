#ifndef TIME_H
#define TIME_H

/************************************************************
* to_minutes: Returns the number of minutes since midnight. *
*************************************************************/

int total_minutes(int hours, int minutes);

/************************************************************
* find_closest: Locates the closest departure time of a     *
*               flight. Saves the arrival and departure     *
*               into variables passed to pointer            *
*               parameters.                                 *
*************************************************************/

void find_closest(int minutes, int *departure, int *arrival);

/************************************************************
* to_24hour: Returns number of hours in 24-hour format when *
*            passed the number of hours since midnight.     *
*************************************************************/

int to_24hour(int minutes);

/************************************************************
* to_12hour: Returns number of hours in 12-hour format when *
*            passed the number of hours since midnight.     *
*************************************************************/

int to_12hour(int minutes);

/************************************************************
* to_minutes: Returns the number of minutes with respect    *
*             to the hours in formatted time when passed    *
*             the number of minutes since midnight.         *
*************************************************************/

int to_minutes(int minutes);


#endif
