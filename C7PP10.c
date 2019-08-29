/* Name: Abdirisak Arr
 * Date: 23/08/2019
 * Description: Computes and outputs the number of vowels in a sentense entered by the user
 */
 
 #include <stdio.h>
 
 int main(void)
 {
 	int count = 0;
 	signed char ch;
 	
 	printf("Enter a sentence: ");
 	while ((ch = getchar()) != '\n')
 	{
 		ch = toupper(ch);
 		switch (ch)
 		{
 			case 'A': case 'E':
 			case 'I': case 'O':
 			case 'U':
 				count++;
 				break;
 			default:
 				break;
		}
	}
	
	printf("The input contains %d vowel(s)", count);
	
	return 0;
 }
