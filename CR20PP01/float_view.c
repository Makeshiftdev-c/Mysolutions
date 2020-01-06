#include <stdio.h>

int main(void)
{
	union
	{
		float value;
		struct
		{
			unsigned int fraction: 23;
			unsigned int exponent: 8;
			unsigned int sign: 1;
		} bitfields;
	} float_view;
	
	float_view.bitfields.sign = 1;
	float_view.bitfields.exponent = 128;
	float_view.bitfields.fraction = 0;
	
	printf("Value: %f\n", float_view.value);
	
	return 0;
}
