#include "stats.h"

int max(int array[], int length)
{
	int i, largest = array[0];
	for (i = 1; i < length; i++)
		if (array[i] > largest)
			largest = array[i];
	return largest;
}

int min(int array[], int length)
{
	int i, smallest = array[0];
	for (i = 1; i < length; i++)
		if (array[i] < smallest)
			smallest = array[i];
	return smallest;
}

int median(int array[], int length)
{
	int median, middle = (length - 1) / 2;
	if (length % 2 != 0)
		median = array[middle];
	else
		median = (array[middle] + array[middle + 1]) / 2;
	return median;
	
}
