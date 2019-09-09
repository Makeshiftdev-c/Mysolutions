/* Name: Abdirisak
 * Date: 08/09/2019
 * Description: Asks the user to enter a series of integers (which it stores in an array), then sorts the integers
                by calling the function selection_sort
 */
 
 #include <stdio.h>
 
 #define SIZE 10 /* Change this to change size of list of numbers to be sorted */
 
 void selection_sort(int a[], int last_element);
 
 int main(void)
 {
 	int a[SIZE], counter;
 	
 	printf("Enter %d numbers: ", SIZE);
 	for (counter = 0; counter < SIZE; counter++)
 	{
 		scanf("%d", &a[counter]);
	}
	
	selection_sort(a, SIZE - 1);
	
	printf("In sorted order: ");
	for (counter = 0; counter < SIZE; counter++)
	{
		printf("%d ", a[counter]);
	}
	
	return 0;
 }
 
 void selection_sort(int a[], int last_element)
 {
 	int high, position, i;
 	
 	if (last_element <= 0) return;
 	
 	high = a[0];
 	position = 0;
 	
 	for (i = 1; i <= last_element; i++)
 	{
 		if (a[i] >= high)
 		{
 			high = a[i];
 			position = i;
		}
	}
 	a[position] = a[last_element];
 	a[last_element] = high;
 	
 	last_element--;
 	selection_sort(a, last_element);
 }
 
