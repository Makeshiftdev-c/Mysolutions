#include <stdio.h>
#include <stddef.h>

struct s
{
	char a;
	int b[2];
	float c;
};

int main(void)
{
	struct s record;
	
	printf("Sizeof s: %u\n", sizeof(record));
	printf("Sizeof a: %u Offsetof a: %u\n", sizeof(record.a), offsetof(struct s, a));
	printf("Sizeof b: %u Offsetof b: %u\n", sizeof(record.b), offsetof(struct s, b));
	printf("Sizeof c: %u Offsetof c: %u\n", sizeof(record.c), offsetof(struct s, c));
	
	return 0;
}

/*
   The structure has one hole of three bytes
   after a, between the members a and b.
*/
