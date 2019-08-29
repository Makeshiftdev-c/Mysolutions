/* Name: Abdirisak Arr
 * Date: 23/08/2019
 * Description: Promps user to input first name and last name respectively, and outputs the last name and iniial
 */
 
 #include <stdio.h>
 
 int main(void)
 {
 	signed char initial, last_name;
 	
 	printf("Enter a first and last name: ");
 	scanf(" %c", &initial);
 	
	while (getchar() != ' ')
	{
		getchar();
	}
	
	while ((last_name = getchar()) != '\n')
	{
		if (last_name != ' ')
		{
			putchar(last_name);
		}
		else
		{
			continue;
		}
	}
	
	putchar(',');
	putchar(' ');
	putchar(initial);
	putchar('.');
	
	return 0;
 } 
