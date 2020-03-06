#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25

struct part
{
	struct
	{
		int number;
		char name[NAME_LEN + 1];
		int on_hand;
	} data;
	struct part *next;
};

struct part *inventory = NULL;

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);

/***********************************************************
 * main: Prompts the user to enter an operation code, then *
 *       calls a function to perform the requested action. *
 *       Repeats until the user enters the command 'q'.    *
 *       Prints an error message if the user enters an     *
 *       illegal code.                                     *
 ***********************************************************/

int main(void)
{
	char code;

	for (;;)
	{
		printf("Enter an operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n')
			;
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
			case 'p':
				print();
				break;
			case 'd':
				dump();
				break;
			case 'r':
				restore();
				break;
			case 'q':
				return 0;
			default:
				fprintf(stderr, "Illegal code\n");
		}
		printf("\n");
	}
}

/***********************************************************
 * find_part: Looks up a part number in the inventory      *
 *            list. Returns a pointer to the node          *
 *            containing the part number; if the part      *
 *            number is not found, returns NULL.           *
 ***********************************************************/

struct part *find_part(int number)
{
	struct part *p;

	for (p = inventory;
	     p != NULL && number > p->data.number;
	     p = p->next)
		;
	if (p != NULL && number == p->data.number)
		return p;
	return NULL;
}

/***********************************************************
 * insert: Prompts the user for information about a new    *
 *         part and then inserts the part into the         *
 *         inventory list; the list remains sorted by      *
 *         part number. Prints an error message and        *
 *         return prematurely if the part already exists   *
 *         or space could not be allocated for the part.   *
 ***********************************************************/

void insert(void)
{
	struct part *cur, *prev, *new_node;

	new_node = malloc(sizeof(struct part));
	if (new_node == NULL)
	{
		fprintf(stderr, "Database is full; can't add more parts.\n");
		return;
	}

	printf("Enter part number: ");
	scanf("%d", &new_node->data.number);

	for (cur = inventory, prev = NULL;
	     cur != NULL && new_node->data.number > cur->data.number;
	     prev = cur, cur = cur->next)
		;
	if (cur != NULL && new_node->data.number == cur->data.number)
	{
		fprintf(stderr, "Part already exists.\n");
		free(new_node);
		return;
	}

	printf("Enter part name: ");
	read_line(new_node->data.name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &new_node->data.on_hand);

	new_node->next = cur;
	if (prev == NULL)
		inventory = new_node;
	else
		prev->next = new_node;
}

/***********************************************************
 * search: Prompts the user to enter a part number, then   *
 *         looks up the part in the database. If the part  *
 *         exists, prints the name and quantity on hand;   *
 *         if not, prints an error message.                *
 ***********************************************************/

void search(void)
{
	int number;
	struct part *p;

	printf("Enter part number: ");
	scanf("%d", &number);
	p = find_part(number);
	if (p != NULL)
	{
		printf("Part name: %s\n", p->data.name);
		printf("Quantity on hand: %d\n", p->data.on_hand);
	}
	else
		fprintf(stderr, "Part not found.\n");
}

/***********************************************************
 * update: Prompts the user to enter a part number.        *
 *         Prints an error message if the part doesn't     *
 *         exist; otherwise, prompts the user to enter     *
 *         change in quantity on hand and updates the      *
 *         database.                                       *
 ***********************************************************/

void update(void)
{
	int number, change;
	struct part *p;

	printf("Enter part number: ");
	scanf("%d", &number);
	p = find_part(number);
	if (p != NULL)
	{
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		p->data.on_hand += change;
	}
	else
		fprintf(stderr, "Part not found.\n");
}

/***********************************************************
 * print: Prints a listing of all parts in the database,   *
 *        showing the part number, part name, and          *
 *        quantity on hand. Part numbers will appear in    *
 *        ascending order.                                 *
 ***********************************************************/

void print(void)
{
	struct part *p;

	printf("Part Number     Part Name          Quantity on Hand\n");
	for (p = inventory; p != NULL; p = p->next)
		printf("%5d           %-19s%11d\n", p->data.number, p->data.name, p->data.on_hand);
}

/***********************************************************
 * dump: Writes the contents of the database into a file.  *
 *       Prompts the user for the filename; prints an      *
 *       error message and returns prematurely if the      *
 *       file can't be opened or created. Prints error     *
 *       message if a write error occurs. Indicates        *
 *       operation completion.                             *
 ***********************************************************/

void dump(void)
{
	FILE *fp_out;
	struct part *p;
	char fname[NAME_LEN];

	printf("Enter name of output file: ");
	read_line(fname, NAME_LEN);
	if ((fp_out = fopen(fname, "wb")) == NULL)
	{
		fprintf(stderr, "Can't create/open %s\n", fname);
		return;
	}

	for (p = inventory;
	     p != NULL;
	     p = p->next)
		if (fwrite(&(p->data), sizeof(p->data), 1, fp_out) == 0)
		{
			fprintf(stderr, "Error: %s (Part number: %d)", p->data.name, p->data.number);
			fprintf(stderr, " could not be written to %s\n", fname);
		}
	printf("Operation Succesful...\n");
	fclose(fp_out);
}

/***********************************************************
 * restore: Retrieves database contents from file          *
 *          specified by the user; prompts user for        *
 *          filename. Prints error message if file can't   *
 *          be opened and returns prematurely. Prints      *
 *          error message and returns prematurely if       *
 *          the database if full. Prints error message     *
 *          and skips part if it already exists in         *
 *          the database. Sorts parts retrieved by         *
 *          ascending part number. Indicates completion    *
 *          of operation.                                  *
 ***********************************************************/

void restore(void)
{
	FILE *fp_in;
	struct part *new_node, *cur, *prev;
	char fname[NAME_LEN];

	printf("Enter name of input file: ");
	read_line(fname, NAME_LEN);
	if ((fp_in = fopen(fname, "rb")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", fname);
		return;
	}


	for (;;)
	{
		new_node = malloc(sizeof(struct part));
		if (new_node == NULL)
		{
			fprintf(stderr, "Database is full; can't add more parts.\n");
			return;
		}

		if (fread(&(new_node->data), sizeof(new_node->data), 1, fp_in) == 0)
		{
			printf("Operation Successful...\n");
			fclose(fp_in);
			free(new_node);
			return;
		}
		
		for (cur = inventory, prev = NULL;
		     cur != NULL && new_node->data.number > cur->data.number;
		     prev = cur, cur = cur->next)
			;
		if (cur != NULL && new_node->data.number == cur->data.number)
		{
			fprintf(stderr, "Error: %s (Part number: %d)", cur->data.name, cur->data.number);
			fprintf(stderr, " already exists; part skipped...\n");
			free(new_node);
			continue;
		}

		new_node->next = cur;
		if (prev == NULL)
			inventory = new_node;
		else
			prev->next = new_node;
	}
}
