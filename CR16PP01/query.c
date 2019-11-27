/* Searches for Country corresponding to International dailing code */

#include <stdio.h>
#include "search.h"

#define MAX_LENGTH 25

int main(void)
{
	char country[MAX_LENGTH];
	int country_code;
	
	printf("Enter an international dailing code: ");
	scanf("%d", &country_code);
	
	printf("Country: ");
	find_country(country, MAX_LENGTH, country_code);
	printf("%s\n", country);
	
	return 0;
}
