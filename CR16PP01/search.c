#include <stdio.h>
#include "search.h"

#define NUM_COUNTRIES (sizeof(country_codes) / sizeof(country_codes[0]))

void find_country(char *array, int array_length, int code)
{
	int i, j;
	struct dailing_code
	{
		char *country;
		int code;
	};
	const struct dailing_code country_codes[] = {{"Argentina",           54},  {"Bangladesh",      880}
	,                                            {"Brazil",              55},  {"Burma (Myanmar)", 95}
	,                                            {"China",               86},  {"Colombia",        57}
	,                                            {"Congo, Dem. Rep. of", 243}, {"Egypt",           20}
	,                                            {"Ethiopia",            251}, {"France",          33}
	,                                            {"Germany",             49},  {"India",           91}
	,                                            {"Indonesia",           62},  {"Iran",            98}
	,                                            {"Italy",               39},  {"Japan",           81}
	,                                            {"Mexico",              52},  {"Nigeria",         234}
	,                                            {"Pakistan",            92},  {"Philippines",     63}
	,                                            {"Poland",              48},  {"Russia",          7}
	,                                            {"South Africa",        27},  {"South Korea",     82}
	,                                            {"Spain",               34},  {"Sudan",           249}
	,                                            {"Thailand",            66},  {"Turkey",          90}
	,                                            {"Ukraine",             380}, {"United Kingdom",  44}
	,                                            {"United States",       1},   {"Vietnam",         84}};
	
	for (i = 0; country_codes[i].code != code; i++)
	{
		if (i == NUM_COUNTRIES - 1)
		{
			printf("Error; dailing code not recognised");
			return;
		}
	}
	for (j = 0; country_codes[i].country[j]; j++)
	{
		if (j == array_length)
		{
			break;
		}
		array[j] = country_codes[i].country[j];
	}
	array[j] = '\0';
}
