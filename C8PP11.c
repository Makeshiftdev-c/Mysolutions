/* Name: Abdirisak Arr
 * Date: 03/09/2019
 * Description: Modification of chapter 7 programming project 4 in which phone number is stored in array
 */
 
 #include <stdio.h>
 #include <ctype.h>
 
 #define SIZE 15
 
 int main(void)
 {
 	signed char ch, input[SIZE];
 	int count = 0, count_out;
 	
 	printf("Enter a phone number: ");
 	while ((ch = getchar()) != '\n')
 	{
 		switch (toupper(ch))
 		{
 			case 'A': case 'B': case 'C':
 				ch = '2';
 				break;
 			case 'D': case 'E': case'F':
 				ch = '3';
 				break;
 			case 'G': case 'H': case 'I':
 				ch = '4';
 				break;
 			case 'J': case 'K': case 'L':
 				ch = '5';
 				break;
 			case 'M': case 'N': case 'O':
 				ch = '6';
 				break;
 			case 'P': case 'R': case 'S':
 				ch = '7';
 				break;
 			case 'T': case 'U': case 'V':
 				ch = '8';
 				break;
 			case 'W': case 'X': case 'Y':
 				ch = '9';
 				break;
		}
 		input[count] = ch;
 		count++;
	}
	
	
	printf("In numeric form: ");
	for (count_out = 0; count_out < count; count_out++)
	{
		printf("%c", input[count_out]);
	}
	
	return 0;
 }
