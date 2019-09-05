/* Name: Abdirisak Arr
 * Date: 05/09/2019
 * Description: Reverses the words in a sentence
 */
 
 #include <stdio.h>
 
 #define LENGTH 100
 
 int main(void)
 {
 	signed char ch, sentence[LENGTH], punctuation;
 	int input_counter = 0, parse_value = 0, word_parse, output_counter;
 	
 	printf("Enter a sentence: ");
 	while ((ch = getchar()) != '\n')
 	{
 		if (ch == '.' || ch == '?' || ch == '!')
 		{
 			punctuation = ch;
 			break;
		}
		
 		sentence[input_counter] = ch;
 		input_counter++;
	}
	
	printf("Reversal of sentence:");
	for (output_counter = input_counter - 1; output_counter >= 0; output_counter--)
	{
		parse_value++;
		if (sentence[output_counter] == ' ')
		{
			for (word_parse = output_counter; word_parse < (output_counter + parse_value); word_parse++)
			{
				printf("%c", sentence[word_parse]);
			}
			parse_value = 0;
		}
		else if (output_counter == 0)
		{
			word_parse = output_counter;
			printf(" ");
			while (sentence[word_parse] != ' ')
			{
				printf("%c", sentence[word_parse]);
				word_parse++;
			}
		}
	}
	printf("%c", punctuation);
	
 	return 0;
 }
