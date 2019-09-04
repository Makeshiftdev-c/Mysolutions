/* Name: Abdirisak Arr
 * Date: 04/09/2019
 * Description: Modification of chapter 7 programming project 11 in which last name is stored in 
 				array of characters until it can be printed
 */
 
 #include <stdio.h>
 
 #define SIZE 20
 
 int main(void)
 {
 	signed char ch, initial;
 	signed char last_name[SIZE];
 	int input_counter = 0, output_counter;
 	
 	printf("Enter a first name and last name: ");
 	initial = getchar();
 	while ((ch = getchar()) != ' ')
 	{
 		getchar();
	}
	while ((ch = getchar()) != '\n')
	{
		last_name[input_counter] = ch;
		input_counter++;
	}
	
	printf("You entered the name: ");
	for (output_counter = 0; output_counter < input_counter; output_counter++)
	{
		putchar(last_name[output_counter]);
	}
	printf(", %c.", initial);
	
	return 0;
 }
