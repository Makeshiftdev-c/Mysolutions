/* Name: Abdirisak Arr
 * Date: 05/09/2019
 * Description: Encrypts a meesage using a Caesar cipher. User will enter message to be encrypted and shift amount
 */
 
 #include <stdio.h>
 
 #define SIZE 80
 
 int main(void)
 {
 	signed ch, message[SIZE];
 	int shift, input_counter = 0, pando_counter;
 	
 	/* Input */
 	printf("Enter message to be encrypted: ");
 	while ((ch = getchar()) != '\n')
 	{
 		message[input_counter] = ch;
 		input_counter++;
	}
	
	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift);
	
	/* Processing */
	for (pando_counter = 0; pando_counter < input_counter; pando_counter++)
	{
		if (message[pando_counter] >= 'A' && message[pando_counter] <= 'Z')
		{
			message[pando_counter] = ((message[pando_counter] - 'A') + shift) % 26 + 'A';
		}
		else if (message[pando_counter] >= 'a' && message[pando_counter] <= 'z')
		{
			message[pando_counter] = ((message[pando_counter] - 'a') + shift) % 26 + 'a';
		}
		else
		{
			message[pando_counter] = message[pando_counter];
		}
	}
 	
 	/* Output */
 	printf("Encrypted message: ");
 	for (pando_counter = 0; pando_counter < input_counter; pando_counter++)
 	{
 		printf("%c", message[pando_counter]);
	}
	
	return 0;
 }
