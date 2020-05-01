#ifndef STATS_H
#define STATS_H

/***********************************************************
 * max: Returns the largest integer in an array of         *
 *      integers.                                          *
 ***********************************************************/

int max(int array[], int length);

/***********************************************************
 * min: Returns the smallest integer in an array of        *
 *      integers.                                          *
 ***********************************************************/

int min(int array[], int length);

/***********************************************************
 * median: Returns the integer nearest the middle in an    *
 *         array of sorted integers. If number of elements *
 *         is even, returns down-rounded average of        *
 *         the two integers nearest the middle.            *
 ***********************************************************/

int median(int array[], int length);

#endif
