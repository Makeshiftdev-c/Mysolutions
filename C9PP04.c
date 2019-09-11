/* Name: Abdirisak Arr
 * Date: 11/09/2019
 * Description: Modification of Programming Project 16 from Chapter 8
 */
 
 #include <stdio.h>
 #include <stdbool.h>
 #include <ctype.h>
 
 void read_word(int counts[26]);
 bool equal_array(int counts1[26], int counts2[26]);
 
 int main(void)
 {
 	int word1[26] = {0}, word2[26] = {0};
 	
 	printf("Enter first word: ");
 	read_word(word1);
 	
 	printf("Enter second word: ");
 	read_word(word2);
 	
 	if (equal_array(word1, word2))
 	{
 		printf("The words are anagrams.");
	}
	else
	{
		printf("The words are not anagrams.");
	}
	
	return 0;
 }
 
 void read_word(int counts[26])
 {
 	signed char letter;
 	int letter_num;
 	
 	while ((letter = getchar()) != '\n')
 	{
 		switch (toupper(letter))
 		{
 			case 'A':
 				letter_num = 0;
 				counts[letter_num]++;
 				break;
 			case 'B':
 				letter_num = 1;
 				counts[letter_num]++;
 				break;
 			case 'C':
 				letter_num = 2;
 				counts[letter_num]++;
 				break;
 			case 'D':
 				letter_num = 3;
 				counts[letter_num]++;
 				break;
 			case 'E':
 				letter_num = 4;
 				counts[letter_num]++;
 				break;
 			case 'F':
 				letter_num = 5;
 				counts[letter_num]++;
 				break;
 			case 'G':
 				letter_num = 6;
 				counts[letter_num]++;
 				break;
 			case 'H':
 				letter_num = 7;
 				counts[letter_num]++;
 				break;
 			case 'I':
 				letter_num = 8;
 				counts[letter_num]++;
 				break;
 			case 'J':
 				letter_num = 9;
 				counts[letter_num]++;
 				break;
 			case 'K':
 				letter_num = 10;
 				counts[letter_num]++;
 				break;
 			case 'L':
 				letter_num = 11;
 				counts[letter_num]++;
 				break;
 			case 'M':
 				letter_num = 12;
 				counts[letter_num]++;
 				break;
 			case 'N':
 				letter_num = 13;
 				counts[letter_num]++;
 				break;
 			case 'O':
 				letter_num = 14;
 				counts[letter_num]++;
 				break;
 			case 'P':
 				letter_num = 15;
 				counts[letter_num]++;
 				break;
 			case 'Q':
 				letter_num = 16;
 				counts[letter_num]++;
 				break;
 			case 'R':
 				letter_num = 17;
 				counts[letter_num]++;
 				break;
 			case 'S':
 				letter_num = 18;
 				counts[letter_num]++;
 				break;
 			case 'T':
 				letter_num = 19;
 				counts[letter_num]++;
 				break;
 			case 'U':
 				letter_num = 20;
 				counts[letter_num]++;
 				break;
 			case 'V':
 				letter_num = 21;
 				counts[letter_num]++;
 				break;
 			case 'W':
 				letter_num = 22;
 				counts[letter_num]++;
 				break;
 			case 'X':
 				letter_num = 23;
 				counts[letter_num]++;
 				break;
 			case 'Y':
 				letter_num = 24;
 				counts[letter_num]++;
 				break;
 			case 'Z':
 				letter_num = 25;
 				counts[letter_num]++;
 				break;
		}
		letter_num++;
	}
 }
 
 bool equal_array(int counts1[26], int counts2[26])
 {
 	int counter;
 	
 	for (counter = 0; counter < 26; counter++)
 	{
 		if (counts1[counter] != counts2[counter])
 		{
 			return false;
		}
	}
	
	return true;
 }
 
