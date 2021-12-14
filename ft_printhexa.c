
#include "ft_printf.h"

void ft_printhexa_add(unsigned long int nbr, int *count)
{
	int i;
	char c;
	int ignoreZero;

	i = 64;
	ignoreZero = 1;
	if (nbr == 0)
		*count += write(1, "0", 1);
	while (i)
	{
		i -= 4;
		c = nbr >> i;
		c = c & 0xf;
		if (c == 0 && ignoreZero)
			continue;
		else
		{
			ignoreZero = 0;
			if (c > 9)
				c += 'a' - 10;
			else
				c += '0';
		}
		*count += write(1, &c, 1);
	}
}

void ft_printhexa(unsigned long int nbr, int toUpper, int *count)
{
	int i;
	char c;
	int ignoreZero;
	int tmp;

	tmp = 0;
	i = 32;
	ignoreZero = 1;
	while (i)
	{
		i -= 4;
		c = nbr >> i;
		c = c & 0xf;
		if (c == 0 && ignoreZero)
			continue;
		else
		{
			tmp = 1;
			ignoreZero = 0;
			if (c > 9)
				c += 'a' - 10 - toUpper;
			else
				c += '0';
		}
		*count += write(1, &c, 1);
	}
	if (tmp == 0)
		*count += write(1, "0", 1);
}