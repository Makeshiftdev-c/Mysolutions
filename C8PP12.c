/* Name: Abdirisak Arr
 * Date: 04/09/2019
 * Description: Modificaton of chapter 7 programming project 5 whereby scrabble values of letters are stored in an array
 */
 
 #include <stdio.h>
 
 #define ALPHABET 26
 #define WRAP 65
 
 int main(void)
 {
 	const int scrabble_values[ALPHABET] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 
	 										1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
 	signed char ch;
 	int scrabble_sum = 0;
 	
 	printf("Enter a word: ");
 	while ((ch = getchar()) != '\n')
 	{
 		ch = toupper(ch);
 		ch -= WRAP;
 		scrabble_sum += scrabble_values[ch];
	}
	
	printf("Scrabble value: %d", scrabble_sum);
 	
 	return 0;
 }
