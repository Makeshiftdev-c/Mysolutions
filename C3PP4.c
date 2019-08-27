#include <stdio.h>

int main(void)
{
	int x, y,z;
	
	printf("Enter phone number [(xxx) xxx-xxxx] : ");
	scanf("(%d) %d-%d", &x, &y, &z);
	
	printf("You entered %.3d.%.3d.%.4d", x, y, z);
	
	return 0;
}
