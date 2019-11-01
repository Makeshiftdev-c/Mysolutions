/************************************************************
* Name: Abdirisak Arr                                       *
* Date: 01/11/2019                                          *
* Description: Modification of planets.c program from       *
*              Chapter 13 Section 13.7. Ignores case when   *
*              comparing commind-line arguments with        *
*              strings in the planets array                 *
************************************************************/

#include <stdio.h>

#define NUM_PLANETS 9

void uncap_elmts(char *str_clm[], int num_strs);
void cap_frst_ch(char *str_ptr[], int str_num);

int main(int argc, char *argv[])
{
	char *planets[] = {"mercury", "venus", "earth", "mars"
	,                  "jupiter", "saturn", "uranus", "saturn"
	,                   "neptune", "pluto"};
	int i, j;
	
	uncap_elmts(argv, argc);
	
	for (i = 1; i < argc; i++)
	{
		for (j = 0; j < NUM_PLANETS; j++)
		{
			if (strcmp(argv[i], planets[j]) == 0)
			{
				cap_frst_ch(argv, i);
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

void uncap_elmts(char *str_clm[], int num_strs)
{
	int i, j;
	
	for (i = 1; i < num_strs; i++)
	{
		for (j = 0; str_clm[i] [j] != '\0'; j++)
		{
			if (str_clm[i] [j] >= 'A' && str_clm[i] [j] <= 'Z')
			{
				str_clm[i] [j] = str_clm[i] [j] - 'A' + 'a';
			}
		}
	}
}

void cap_frst_ch(char *str_ptr[], int str_num)
{
	str_ptr[str_num] [0] = str_ptr[str_num] [0] - 'a' + 'A';
}
