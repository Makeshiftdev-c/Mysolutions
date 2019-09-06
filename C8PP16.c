/* Name: Abdirisak Arr
 * Date: 05/09/2019
 * Description: Tests whether two words are anagrams
 */
 
 #include <stdio.h>
 #include <ctype.h>
 
 #define ALPHABET 26
 
 int main(void)
 {
 	int manipulator, pando_counter, test_match[ALPHABET] = {0};
 	signed char word_letters;
 	
 	/* Input and processing */
 	printf("Enter first word: ");
 	while ((word_letters = getchar()) != '\n')
 	{
 		if (isalpha(word_letters))
 		{
 			switch (tolower(word_letters))
 			{
 				case 'a':
 					manipulator = 0;
 					test_match[manipulator]++;
 					break;
 				case 'b':
 					manipulator = 1;
 					test_match[manipulator]++;
 					break;
 				case 'c':
 					manipulator = 2;
 					test_match[manipulator]++;
 					break;
 				case 'd':
 					manipulator = 3;
 					test_match[manipulator]++;
 					break;
 				case 'e':
 					manipulator = 4;
 					test_match[manipulator]++;
 					break;
 				case 'f':
 					manipulator = 5;
 					test_match[manipulator]++;
 					break;
 				case 'g':
 					manipulator = 6;
 					test_match[manipulator]++;
 					break;
 				case 'h':
 					manipulator - 7;
 					test_match[manipulator]++;
 					break;
 				case 'i':
 					manipulator = 8;
 					test_match[manipulator]++;
 					break;
 				case 'j':
 					manipulator = 9;
 					test_match[manipulator]++;
 					break;
 				case 'k':
 					manipulator = 10;
 					test_match[manipulator]++;
 					break;
 				case 'l':
 					manipulator = 11;
 					test_match[manipulator]++;
 					break;
 				case 'm':
 					manipulator = 12;
 					test_match[manipulator]++;
 					break;
 				case 'n':
 					manipulator = 13;
 					test_match[manipulator]++;
 					break;
 				case 'o':
 					manipulator = 14;
 					test_match[manipulator]++;
 					break;
 				case 'p':
 					manipulator = 15;
 					test_match[manipulator]++;
 					break;
 				case 'q':
 					manipulator = 16;
 					test_match[manipulator]++;
 					break;
 				case 'r':
 					manipulator = 17;
 					test_match[manipulator]++;
 					break;
 				case 's':
 					manipulator = 18;
 					test_match[manipulator]++;
 					break;
 				case 't':
 					manipulator = 19;
 					test_match[manipulator]++;
 					break;
 				case 'u':
 					manipulator = 20;
 					test_match[manipulator]++;
 					break;
 				case 'v':
 					manipulator = 21;
 					test_match[manipulator]++;
 					break;
 				case 'w':
 					manipulator = 22;
 					test_match[manipulator]++;
 					break;
 				case 'x':
 					manipulator = 23;
 					test_match[manipulator]++;
 					break;
 				case 'y':
 					manipulator = 24;
 					test_match[manipulator]++;
 					break;
 				case 'z':
 					manipulator = 25;
 					test_match[manipulator]++;
 					break;
			}
		}
	}
	
	printf("Enter second word: ");
	while ((word_letters = getchar()) != '\n')
	{
		if (isalpha(word_letters))
		{
			switch (tolower(word_letters))
			{
				case 'a':
					manipulator = 0;
					test_match[manipulator]--;
					break;
				case 'b':
					manipulator = 1;
					test_match[manipulator]--;
					break;
				case 'c':
					manipulator = 2;
					test_match[manipulator]--;
					break;
				case 'd':
					manipulator = 3;
					test_match[manipulator]--;
					break;
				case 'e':
					manipulator = 4;
					test_match[manipulator]--;
					break;
				case 'f':
					manipulator = 5;
					test_match[manipulator]--;
					break;
				case 'g':
					manipulator = 6;
					test_match[manipulator]--;
					break;
				case 'h':
					manipulator = 7;
					test_match[manipulator]--;
					break;
				case 'i':
					manipulator = 8;
					test_match[manipulator]--;
					break;
				case 'j':
					manipulator = 9;
					test_match[manipulator]--;
					break;
				case 'k':
					manipulator = 10;
					test_match[manipulator]--;
					break;
				case 'l':
					manipulator = 11;
					test_match[manipulator]--;
					break;
				case 'm':
					manipulator = 12;
					test_match[manipulator]--;
					break;
				case 'n':
					manipulator = 13;
					test_match[manipulator]--;
					break;
				case 'o':
					manipulator = 14;
					test_match[manipulator]--;
					break;
				case 'p':
					manipulator = 15;
					test_match[manipulator]--;
					break;
				case 'q':
					manipulator = 16;
					test_match[manipulator]--;
					break;
				case 'r':
					manipulator = 17;
					test_match[manipulator]--;
					break;
				case 's':
					manipulator = 18;
					test_match[manipulator]--;
					break;
				case 't':
					manipulator = 19;
					test_match[manipulator]--;
					break;
				case 'u':
					manipulator = 20;
					test_match[manipulator]--;
					break;
				case 'v':
					manipulator = 21;
					test_match[manipulator]--;
					break;
				case 'w':
					manipulator = 22;
					test_match[manipulator]--;
					break;
				case 'x':
					manipulator = 23;
					test_match[manipulator]--;
					break;
				case 'y':
					manipulator = 24;
					test_match[manipulator]--;
					break;
				case 'z':
					manipulator = 25;
					test_match[manipulator]--;
					break;
			}
		}
	}
	
	/* Output */
	printf("The words are ");
	for (pando_counter = 0; pando_counter < ALPHABET; pando_counter++)
	{
		if (test_match[pando_counter] != 0)
		{
			printf("not anagrams.");
			break;
		}
		if (pando_counter == (ALPHABET - 1))
		{
			printf("anagrams.");
		}
	}
 	
 	return 0;
 }
