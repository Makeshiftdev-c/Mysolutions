/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 31/10/2019                                          *
* Description: Modification of planets.c program from       *
*              Chapter 13 Section 13.7. Ignores case when   *
*              comparing commind-line arguments with        *
*              strings in the planets array                 *
************************************************************/

#include <stdio.h>
#include <ctype.h>

#define NUM_PLANETS 9

int main(int argc, char *argv[])
{
	char *planets[] = {"mercury", "venus", "earth", "mars"
	,                  "jupiter", "saturn", "uranus", "saturn"
	,                   "neptune", "pluto"};
	int i, j;
	
	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i] [j] != '\0'; j++)
		{
			if (argv[i] [j] >= 'A' && argv[i] [j] <= 'Z')
			 argv[i] [j] = argv[i] [j] - 'A' + 'a';
		}
	}
	
	for (i = 1; i < argc; i++)
	{
		for (j = 0; j < NUM_PLANETS; j++)
		{
			if (strcmp(argv[i], planets[j]) == 0)
			{
				argv[i] [0] = toupper(argv[i] [0]); 
				printf("%s is planet %d\n", argv[i], j + 1);
				break;
			}
		}
		if (j == NUM_PLANETS)
		{
			printf("%s is not a planet\n", argv[i]);
		}
	}
	
	return 0;
}
