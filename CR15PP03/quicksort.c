#include "quicksort.h"

void quicksort(int array[], int low, int high)
{
	int middle;
	
	if (low >= high) return;
	
	middle = split(array, low, high);
	quicksort(array, low, middle - 1);
	quicksort(array, middle + 1, high);
}

int split(int array[], int low, int high)
{
	int part_element = array[low];
	
	for (;;)
	{
		while (low < high && part_element <= array[high])
		{
			high--;
		}
		if (low >= high) break;
		array[low++] = array[high];
		
		while (low < high && array[low] <= part_element)
		{
			low++;
		}
		if (low >= high) break;
		array[high--] = array[low];
	}
	
	array[high] = part_element;
	return high;
}
