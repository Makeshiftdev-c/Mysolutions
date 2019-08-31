/* Name: Abdirisak Arr
 * Date: 31/08/2019
 *Description: "B1FF filter" that reads a message entered by the user and translates it into B1FF-speak
 */
 
 #include <stdio.h>
 #include <ctype.h>
 
#define MAXIMUM_LETTERS 100
 
 int main(void)
 {
 	int count1, count2;
 	signed char letter, ch[MAXIMUM_LETTERS] = {'0'};
 	
 	printf("Enter message (press enter to continue): ");
 	count1 = 0;
 	while ((letter = getchar()) != '\n')
 	{
 		ch[count1] = toupper(letter);
 		count1++;
	}
	
	printf("In B1FF-speak: ");
	
	for (count2 = 0; count2 < count1; count2++)
	{
		switch(ch[count2])
		{
			case 'A':
				ch[count2] = '4';
				break;
			case 'B':
				ch[count2] = '8';
				break;
			case 'E':
				ch[count2] = '3';
				break;
			case 'I':
				ch[count2] = '1';
				break;
			case 'O':
				ch[count2] = '0';
				break;
			case 'S':
				ch[count2] = '5';
				break;
			default:
				break;
		}
		
		printf("%c", ch[count2]);
	}
	
	printf("!!!!!!!!!!\n");
	
 	return 0;
 }
