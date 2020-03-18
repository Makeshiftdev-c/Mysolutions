#include <stdio.h>
#include <stdlib.h>

#define CONV_FACTOR 60

struct node
{
	int departure_time;
	int arrival_time;
	struct node *next;
};

struct node *first = NULL;

void read_flight_data(const char *filename);
struct node *find_nearest(int time_mins);
void clearwmem(void);

int main(int argc, char *argv[])
{
	struct node *nearest;
	int hhi, mmi, totalMSM;
	int hhd, mmd, hha, mma;

	if (argc != 2)
	{
		fprintf(stderr, "usage: checkFlights filename (specified file");
		fprintf(stderr, " should contain flight time data\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hhi, &mmi);
	read_flight_data(argv[1]);
	nearest = find_nearest((hhi * CONV_FACTOR) + mmi);

	hhd = nearest->departure_time / CONV_FACTOR;
	mmd = nearest->departure_time - (hhd * CONV_FACTOR);
	hha = nearest->arrival_time / CONV_FACTOR;
	mma = nearest->arrival_time - (hha * CONV_FACTOR);

	printf("Closest departure time is %d:%.2d, ", hhd, mmd);
	printf("arriving at %d:%.2d\n", hha, mma);

	clearwmem();
	return 0;
}

void read_flight_data(const char *filename)
{
	struct node *new_node, *prev, *cur;
	int mmd, hhd, mma, hha;
	FILE *fp;

	if ((fp = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", filename);
		exit(EXIT_FAILURE);
	}

	for (;;)
	{
		new_node = malloc(sizeof(struct node));
		if (new_node == NULL)
		{
			fprintf(stderr, "Insufficient memory available\n");
			exit(EXIT_FAILURE);
		}
		if (fscanf(fp, "%d:%d%*[ ]%d:%d", &hhd, &mmd, &hha, &mma) == EOF)
		{
			free(new_node);
			return;
		}

		new_node->departure_time = (hhd * CONV_FACTOR) + mmd;
		new_node->arrival_time = (hha * CONV_FACTOR) + mma;

		for (cur = first, prev = NULL;
		     cur != NULL && new_node->departure_time > cur->departure_time;
		     prev = cur, cur = cur->next)
			;
		new_node->next = cur;
		if (prev == NULL)
			first = new_node;
		else
			prev->next = new_node;
	}
}

struct node *find_nearest(int time_mins)
{
	struct node *cur = first, *prev = NULL;
	int mid_point;

	if (cur->departure_time > time_mins)
		return cur;
	for (prev = cur, cur = cur->next;
	     cur != NULL;
	     prev = cur, cur = cur->next)
		if (time_mins >= prev->departure_time && time_mins <= cur->departure_time)
			break;
	if (cur == NULL)
		return prev;

	mid_point = (prev->departure_time + cur->departure_time) / 2;
	if (time_mins <= mid_point)
		return prev;
	return cur;
}

void clearwmem(void)
{
	struct node *old;

	while (first)
	{
		old = first;
		first = first->next;
		free(old);
	}
}
