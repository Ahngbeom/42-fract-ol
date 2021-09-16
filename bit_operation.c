#include <stdio.h>
#include <math.h>

// gcc bit_operation.c -lm

int	rgb_bitset(int color)
{
	int	bit = color;
	int	power;
	// int	count = 16;
	
	// while (--count)
	// {
		power = 0;
		while (power < 24)
		{
			bit = bit - (int)pow(2, power);
			power += 4;
		}
	// }

	return(bit);
}

int main(void)
{
	printf("%#08X\n", rgb_bitset(0xFFFFFF));
	return (0);
}
