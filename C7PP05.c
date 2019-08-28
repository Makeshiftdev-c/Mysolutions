/*Name: Abdirisak Arr
 *Date: 20/08/2019
 *Description: Computes the scrabble value of a word by summing the values of its letters. Face values:
               1 - AEILNORSTU, 2 - DG, 3 - BCMP, 4 - FHVWY, 5 - K, 8 - JX, 10 - QZ
 */
 
 #include <stdio.h>
 #include <ctype.h>
 
 int main(void)
 {
 	char ch;
 	int sum = 0, value;
 	
 	printf("Enter a word: ");
 	
 	while ((ch = getchar()) != '\n')
 	{
 		value = 0;
 		ch = toupper(ch);
 		switch (ch)
 		{
 			case 'A': case 'E': case 'I': case 'L':
 			case 'N': case 'O': case 'R': case 'S':
 			case 'T': case 'U':
 				value = 1;
 				sum += value;
 				break;
 			case 'D': case 'G':
 				value = 2;
 				sum += value;
 				break;
 			case 'B': case 'C': case 'M': case 'P':
 				value = 3;
 				sum += value;
 				break;
 			case 'F': case 'H': case 'V': case 'W':
 			case 'Y':
 				value = 4;
 				sum += value;
 				break;
 			case 'K':
 				value = 5;
 				sum += 5;
 				break;
 			case 'J': case 'X':
 				value = 8;
 				sum += value;
 				break;
 			case 'Q': case 'Z':
 				value = 10;
 				sum += value;
 				break;
 			default:
 				value = 0;
 				break;
		}
	}
	
	printf("Scrabble value: %d", sum);
	
	return 0;
 }
