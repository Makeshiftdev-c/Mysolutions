#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part
{
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
};

int find_part(int number, struct part record[], int *index);
void insert(struct part record[], int *index);
void search(struct part record[], int *index);
void update(struct part record[], int *index);
void print(struct part record[], int *index);

/************************************************************
* main: Prompts the user to enter an operatoin code, then   *
*       calls a function to perform the requested action.   *
*       Repeats until the user enters the command 'q'.      *
*       Prints an error message if the user enters an       *
*       illegal code.                                       *
*************************************************************/

int main(void)
{
	struct part inventory[MAX_PARTS];
	int num_parts = 0;
	char code;
	
	for (;;)
	{
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n')
		{
			;
		}
		switch (code)
		{
			case 'i':
				insert(inventory, &num_parts);
				break;
			case 's':
				search(inventory, &num_parts);
				break;
			case 'u':
				update(inventory, &num_parts);
				break;
			case 'p':
				print(inventory, &num_parts);
				break;
			case 'q':
				return 0;
			default:
				printf("Illegal code\n");
		}
		printf("\n");
	}
}

/************************************************************
* find_part: Looks up a part number in the inventory array. *
*            Returns the array index if the part number is  *
*            found; otherwise, returns -1.                  *
*************************************************************/

int find_part(int number, struct part record[], int *index)
{
	int i;
	
	for (i = 0; i < *index; i++)
	{
		if (record[i].number == number)
		{
			return i;
		}
	}
	return -1;
}

/************************************************************
* insert: Prompts the user for information about a new      *
*         part and then inserts the part into the database. *
*         Prints an error message and returns prematurely   *
*         if the part already exists or the database is     *
*         full.                                             *
*************************************************************/

void insert(struct part record[], int *index)
{
	int part_number;
	
	if (*index == MAX_PARTS)
	{
		printf("Database is full; can't add more parts.\n");
		return;
	}
	
	printf("Enter part number: ");
	scanf("%d", &part_number);
	if (find_part(part_number, record, index) >= 0)
	{
		printf("Part already exists.\n");
		return;
	}
	
	record[*index].number = part_number;
	printf("Enter part name: ");
	read_line(record[*index].name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &record[*index].on_hand);
	(*index)++;
}

/************************************************************
* search: Prompts the user to enter a part number, then     *
*         looks up the part in the database. If the part    *
*         exists, prints the name and quantity on hand;     *
*         if not, prints an error message.                  *
*************************************************************/

void search(struct part record[], int *index)
{
	int i, number;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number, record, index);
	if (i >= 0)
	{
		printf("Part name: %s\n", record[i].name);
		printf("Quantity on hand: %d\n", record[i].on_hand);
	}
	else
	{
		printf("Part not found.\n");
	}
}

/************************************************************
* update: Prompts the user to enter a part number. Prints   *
*         an error message if the part doesn't exist;       *
*         otherwise, prompts the user to enter change       *
*         in quantity on hand and updates the database.     *
*************************************************************/

void update(struct part record[], int *index)
{
	int i, number, change;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number, record, index);
	if (i >= 0)
	{
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		record[i].on_hand += change;
	}
	else
	{
		printf("Part not found.\n");
	}
}

/************************************************************
* print: Prints a listing of all parts in the database,     *
*        showing the part number, part name, and quantity   *
*        on hand. Parts are printed in the order in which   *
*        they were entered into the database.               *
*************************************************************/

void print(struct part record[], int *index)
{
	int i;
	
	printf("Part Number        Part Name        Quantity on Hand\n");
	for (i = 0; i < *index; i++)
	{
		printf("%5d              %-11s%15d\n", record[i].number, record[i].name, record[i].on_hand);
	}
}
