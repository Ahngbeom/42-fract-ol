#include <stdio.h>
#include <math.h>

int	main(void)
{
	int	bit = 0xFFFFFFFF;
	int	power;
	int	count = 16;
	
	printf("%#010X\n", bit);
	while (--count)
	{
		power = 0;
		while (power < 32)
		{
			bit = bit - (int)pow(2, power);
			power += 4;
		}
		printf("%#010X\n", bit);
	}
	return(0);
}
