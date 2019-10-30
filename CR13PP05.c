/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 30/10/2019                                          *
* Description: Program adds up it's command-line arguments. *
*              (Assumed to be integers)                     *
*************************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, sum = 0;
	
	for (i = 1; i < argc; i++)
	{
		sum += atoi(argv[i]);
	}
	
	printf("Total: %d\n", sum);
	
	return 0;
}
