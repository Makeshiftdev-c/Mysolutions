/* Sorts an array of integers using Quicksort algorithm */

#include <stdio.h>
#include "quicksort.h"

#define MAX_LENGTH 10

int main(void)
{
	int a[MAX_LENGTH];
	int i;
	
	printf("Enter %d numbers to be sorted: ", MAX_LENGTH);
	for (i = 0; i < MAX_LENGTH; i++)
	{
		scanf("%d", &a[i]);
	}
	
	quicksort(a, 0, MAX_LENGTH - 1);
	
	printf("In sorted order: ");
	for (i = 0; i < MAX_LENGTH; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return 0;
}
