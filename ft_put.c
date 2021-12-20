/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:21:19 by rel-maza          #+#    #+#             */
/*   Updated: 2021/12/18 14:21:42 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s != NULL)
	{
		while (s[len])
			len++;
	}
	return (len);
}

void	ft_putchar(char c, int *count)
{
	*count += write(1, &c, 1);
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
		ft_putstr("(null)", count);
	else
	{
		while (str[i])
		{
			*count += write(1, &str[i], 1);
			i++;
		}
	}
}

void	ft_putnbr(int n, int *count)
{
	if (n >= 0 && n < 10)
		ft_putchar((n + '0'), count);
	else if (n == -2147483648)
		*count += write(1, "-2147483648", 11);
	else if (n >= 10)
	{
		ft_putnbr((n / 10), count);
		ft_putnbr((n % 10), count);
	}
	else if (n < 0)
	{
		ft_putchar(('-'), count);
		ft_putnbr((n * -1), count);
	}
}

void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	if (n >= 0 && n < 10)
		ft_putchar((n + '0'), count);
	else if (n >= 10)
	{
		ft_putnbr((n / 10), count);
		ft_putnbr((n % 10), count);
	}
}
