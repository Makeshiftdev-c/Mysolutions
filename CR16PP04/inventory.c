#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part
{
	int number;
	char name[NAME_LEN + 1];
	float price;
	int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

int find_parts(int number);
void insert(void);
void search(void);
void update(void);
void reprice(void);
void print(void);

/************************************************************
* main: Prompts the user to enter an operation code, then   *
*       calls a function to perform the requested action.   *
*       Repeats until the user enters the command 'q'.      *
*       Prints an error message if the user enters an       *
*       illegal code.                                       *
*************************************************************/

int main(void)
{
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
				insert();
				break;
			case 's':
				search();
				break;
			case 'u':
				update();
				break;
			case 'r':
				reprice();
				break;
			case 'p':
				print();
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

int find_part(int number)
{
	int i;
	
	for (i = 0; i < num_parts; i++)
	{
		if (inventory[i].number == number)
		{
			return i;
		}
	}
	return -1;
}

/************************************************************
* insert: Prompts the user for information about a new      *
*         part and then inserts the part into the databse.  *
*         Prints an error message and returns prematurely   *
*         if the part already exists or the database is     *
*         full.                                             *
*************************************************************/

void insert(void)
{
	int part_number;
	
	if (num_parts == MAX_PARTS)
	{
		printf("Database is full; can't add more parts.\n");
		return;
	}
	
	printf("Enter part number: ");
	scanf("%d", &part_number);
	if (find_part(part_number) >= 0)
	{
		printf("Part already exists.\n");
		return;
	}
	
	inventory[num_parts].number = part_number;
	printf("Enter part name: ");
	read_line(inventory[num_parts].name, NAME_LEN);
	printf("Enter unit price: $");
	scanf("%f", &inventory[num_parts].price);
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[num_parts].on_hand);
	num_parts++;
}

/************************************************************
* search: Prompts the user to enter a part number, then     *
*         looks up the part in the database. If the part    *
*         exists, prints the name, quantity on hand, and    *
*         unit price; if not, prints an error message.      *
*************************************************************/

void search(void)
{
	int i, number;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0)
	{
		printf("Part name: %s\n", inventory[i].name);
		printf("Unit price: %.2f\n", inventory[i].price);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
	}
	else
	{
		printf("Part not found.\n");
	}
}

/************************************************************
* update: Prompts the user to enter a part number. Prints   *
*         an error message if the part doesn't exists;      *
*         otherwise, prompts the user to enter change       *
*         in quantity on hand and updates the database.     *
*************************************************************/

void update(void)
{
	int i, number, change;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0)
	{
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		inventory[i].on_hand += change;
	}
	else
	{
		printf("Part not found.\n");
	}
}

/************************************************************
* reprice: Prompts the user to enter a part number. Prints  *
*          an error message if the part doesn't exist;      *
*          otherwise, prompts the user to enter change      *
*          in unit price and updates the database.          *
*************************************************************/

void reprice(void)
{
	int i, number;
	float change;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0)
	{
		printf("Enter change in unit price: ");
		scanf("%f", &change);
		inventory[i].price += change;
	}
	else
	{
		printf("Part not found.\n");
	}
}

/************************************************************
* price: Prints a listing of all parts in the database,     *
*        showing the part number, part name, unit price,    *
*        and quantity on hand. Parts are printed in the     *
*        order in which they were entered into the          *
*        database.                                          *
*************************************************************/

void print(void)
{
	int i;
	
	printf("Part Number   Part Name     Unit Price   Quantity on hand\n");
	for (i = 0; i < num_parts; i++)
	{
		printf("%5d         %-13s%7.2f%17d\n", inventory[i].number, inventory[i].name, inventory[i].price, inventory[i].on_hand);
	}
}
