#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part
{
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
};

int find_part(struct part *inventory, int number, int num_parts);
int compare_parts(const void *p, const void *q);

int main(int argc, char *argv[])
{
	struct part temp_part, inventory[MAX_PARTS];
	FILE *src1_fp, *src2_fp, *dest_fp;
	int rep_index;
	int num_parts = 0;
	bool mismatch = false, overflow = false;

	if (argc != 4)
	{
		fprintf(stderr, "usage: merge source-filename source-filename destination-filename\n");
		exit(EXIT_FAILURE);
	}

	if ((src1_fp = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((src2_fp = fopen(argv[2], "rb")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	if ((dest_fp = fopen(argv[3], "wb")) == NULL)
	{
		fprintf(stderr, "Can't open/create %s\n", argv[3]);
		exit(EXIT_FAILURE);
	}

	num_parts = fread(inventory, sizeof(struct part), MAX_PARTS, src1_fp);
	
	fprintf(stderr, "Error Log:\n");
	fprintf(stderr, "----------\n");
	for (; num_parts < MAX_PARTS;)
	{
		if (fread(&temp_part, sizeof(struct part), 1, src2_fp) == 0)
			break;
		rep_index = find_part(inventory, temp_part.number, num_parts);
		if (rep_index >= 0)
		{
			if (strcmp(inventory[rep_index].name, temp_part.name) != 0)
			{
				fprintf(stderr, "-> %s and %s have an identical part number (%d);\n", inventory[rep_index].name, temp_part.name, temp_part.number);
				fprintf(stderr, "   unable to merge %s into %s file.\n", temp_part.name, argv[3]);
				mismatch = true;
				continue;
			}
			inventory[rep_index].on_hand += temp_part.on_hand;
			continue;
		}
		inventory[num_parts].number = temp_part.number;
		strcpy(inventory[num_parts].name, temp_part.name);
		inventory[num_parts].on_hand = temp_part.on_hand;
		num_parts++;
	}

	if ((fread(&temp_part, sizeof(struct part), 1, src2_fp) != 0) && (num_parts + 1) == MAX_PARTS)
		overflow = true;

	if (overflow)
	{
		fprintf(stderr, "-> merge at maximum capacity; succesful up to, but not including:\n");
		fprintf(stderr, "    Part number: %d\n", temp_part.number);
		fprintf(stderr, "    Part name: %s\n", temp_part.name);
		fprintf(stderr, "    Location: %s\n", argv[2]);
	}

	if (!mismatch && !overflow)
		fprintf(stderr, "No errors detected; operation succesful\n");
	fprintf(stderr, "\n");

	qsort(inventory, num_parts, sizeof(struct part), compare_parts);
	fwrite(inventory, sizeof(struct part), num_parts, dest_fp);

	fclose(src1_fp);
	fclose(src2_fp);
	fclose(dest_fp);
	return 0;
}

int find_part(struct part *inventory, int number, int num_parts)
{
	int i;

	for (i = 0; i < num_parts; i++, inventory++)
		if (inventory->number == number)
			return i;
	return -1;
}

int compare_parts(const void *p, const void *q)
{
	const struct part *p1 = p;
	const struct part *q1 = q;

	if (p1->number < q1->number)
		return -1;
	else if (p1->number == q1->number)
		return 0;
	else
		return 1;
}
