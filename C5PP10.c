/*Name: Abdirisak Arr
 *Date: 04/08/2019
 *Description: Converts a numerical grade into a letter grade using switch statement
               using following scale A = 90-100, B = 80-89, c = 70-79, D = 60-69,
               F = 0-59
*/

#include <stdio.h>

int main(void)
{
	int num_grade, tens_digit;
	
	printf("Enter numerical grade: ");
	scanf("%d", &num_grade);
	
	if (num_grade < 10 && num_grade >= 6)
	 tens_digit = num_grade - 4;
	else if (num_grade < 6)
	 tens_digit = num_grade;
	else
	  tens_digit = num_grade / 10;
	
	switch (tens_digit)
	{
		case 0:
			printf("Letter grade: F");
			break;
		case 1:
			printf("Letter grade: F");
			break;
		case2:
			printf("Letter grade: F");
			break;
		case 3:
			printf("Letter grade: F");
			break;
		case 4:
			printf("Letter grade: F");
			break;
		case 5:
			printf("Letter grade: F");
			break;
		case 6:
			printf("Letter grade: D");
			break;
		case 7:
			printf("Letter grade: C");
			break;
		case 8:
			printf("Letter grade: B");
			break;
		case 9:
			printf("Letter grade: A");
			break;
		case 10:
    		printf("Letter grade: F");
			break;
		default:
			printf("Invalid input");
			break;
	}
	
	return 0;
}
