/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:21:01 by rel-maza          #+#    #+#             */
/*   Updated: 2021/12/16 16:35:31 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhexa_add(unsigned long int nbr, int *count)
{
	int		i;
	char	c;
	int		ignore_zero;

	i = 64;
	ignore_zero = 1;
	if (nbr == 0)
		*count += write(1, "0", 1);
	while (i)
	{
		i -= 4;
		c = nbr >> i;
		c = c & 0xf;
		if (c == 0 && ignore_zero)
			continue ;
		else
		{
			ignore_zero = 0;
			if (c > 9)
				c += 'a' - 10;
			else
				c += '0';
		}
		*count += write(1, &c, 1);
	}
}

static int	ft_putnewchar(char c, int toUpper)
{
	int	up;

	up = 0;
	if (toUpper)
		up = 32;
	if (c > 9)
		c += 'a' - 10 - up;
	else
		c += '0';
	return (c);
}

void	ft_printhexa(unsigned long int nbr, int toUpper, int *count)
{
	int		i;
	char	c;
	int		ignore_zero;
	int		tmp;

	tmp = 0;
	i = 32;
	ignore_zero = 1;
	while (i)
	{
		i -= 4;
		c = nbr >> i;
		c = c & 0xf;
		if (c == 0 && ignore_zero)
			continue ;
		else
		{
			tmp = 1;
			ignore_zero = 0;
			c = ft_putnewchar(c, toUpper);
		}
		*count += write(1, &c, 1);
	}
	if (tmp == 0)
		*count += write(1, "0", 1);
}
