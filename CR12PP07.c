/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 21/10/2019                                          *
* Description: Modification of maxmin.c program from        *
*              Section 9.6 using pointers instead of array  *
*              subscipting                                  *
*************************************************************/

#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *min, int *max);

int main(void)
{
	int a[N], *elment, big, small;
	
	printf("Enter %d numbers: ", N);
	for (elment = a; elment < a + N; elment++)
	{
		scanf("%d", elment);
	}
	
	max_min(a, N, &small, &big);
	
	printf("Largest: %d\nSmallest: %d", big, small);
	
	return 0;
}

void max_min(int a[], int n, int *min, int *max)
{
	int *elment;
	
	*min = *max = *a;
	for (elment = a + 1; elment < a + n; elment++)
	{
		if (*elment > *max)
		{
			*max = *elment;
		}
		else if (*elment < *min)
		{
			*min = *elment;
		}
	}
}
