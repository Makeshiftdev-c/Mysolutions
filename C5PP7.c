/*Name: Abdirisak Arr
 *Date: 03/08/2019
 *Description: Finds the largest and smallest of four integers entered by the user
*/

#include <stdio.h>

int main(void)
{
	int i1, i2, i3, i4, large, small;
	
	printf("Enter four integers (Each separated by a space): ");
	scanf("%d %d %d %d", &i1, &i2, &i3, &i4);
	
	if (i1 > i2 && i1 > i3 && i1 > i4) /*Outer selection statements compute the largest input value*/
	{
		large = i1;
		if (i2 > i3 && i2 > i4)        /*Inner selection statements compute the smallest input value*/ 
		 small = i3 < i4 ? i3 : i4;
		else if (i3 > i4 && i3 > i2)
		 small = i4 < i2 ? i4 : i2;
		else
		 small = i2 < i3 ? i2 : i3;
	}
	else if (i2 > i1 && i2 > i3 && i2 > i4)
	{
		large = i2;
		if (i1 > i3 && i1 > i4)
		 small = i3 < i4 ? i3 : i4;
		else if (i3 > i4 && i3 > i1)
		 small = i4 < i1 ? i4 : i1;
		else
		 small = i1 < i3 ? i1 : i3;
	}
	else if (i3 > i1 && i3 > i2 && i3 > i4)
	{
		large = i3;
		if (i1 > i2 && i1 > i4)
		 small = i2 < i4 ? i2 : i4;
		else if (i2 > i4 && i2 > i1)
		 small = i4 < i1 ? i4 : i1;
		else
		 small = i1 < i2 ? i1 : i2;
	}
	else
	{
		large = i4;
		if (i1 > i2 && i1 > i3)
		 small = i2 < i3 ? i2 : i3;
		else if (i2 > i3 && i2 > i1)
		 small = i3 < i1 ? i3 : i1;
		else
		 small = i1 < i2 ? i1 : i2;
	}
	 
	 printf("Largest: %d\nSmallest: %d", large, small);
	 
	 return 0;
}
