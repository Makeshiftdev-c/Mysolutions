#include <stdio.h>

int main(void)
{
	int gs1_prefix, group_identifier, publisher_code, item_number, check_digit;
	
	printf("Enter ISBN: ");
	scanf("%d-%d-%d-%d-%d", &gs1_prefix, &group_identifier, &publisher_code, &item_number, &check_digit);
	
	printf("GS1 prefix: %d ", gs1_prefix);
	printf("\nGroup identifier: %d", group_identifier);
	printf("\nPublisher code: %d", publisher_code);
	printf("\nItem number: %d", item_number);
	printf("\nCheck digit: %d", check_digit);
	return 0;
}
