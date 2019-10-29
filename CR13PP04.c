/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 29/10/2019                                          *
* Description: Echos it's command line arguments in reverse *
*              order                                        *
*************************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, j;
	
	for (i = argc - 1; i > 0; i--)
	{
		printf("%s ", argv[i]);
	}
	printf("\n");
	
	return 0;
}
