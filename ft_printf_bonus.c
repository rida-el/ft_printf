/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:19:57 by rel-maza          #+#    #+#             */
/*   Updated: 2021/12/17 15:59:54 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_check(char const c)
{
	char	*str;

	str = "cspdiuxX%";
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

void	check_and_print(int nbr, int *count, int isSpace)
{
	if (nbr >= 0 && isSpace == 1)
		ft_putchar(' ', count);
	else if (nbr >= 0)
		ft_putchar('+', count);
	ft_putnbr(nbr, count);
}

void	check_sharp_print(int nbr, int *count, int up)
{
	if (nbr != 0 && up == 0)
	{
		ft_putstr("0x", count);
		ft_printhexa(nbr, up, count);
	}
	else if (nbr != 0 && up != 0)
	{
		ft_putstr("0X", count);
		ft_printhexa(nbr, up, count);
	}
	else
		ft_putnbr(0, count);
}

void	ft_print(const char form, va_list args, char flag, int *count)
{
	if (form == 'd' || form == 'i')
	{
		if (flag == '+')
			check_and_print(va_arg(args, int), count, 0);
		else if (flag == ' ')
			check_and_print(va_arg(args, int), count, 1);
		else
			ft_putnbr((va_arg(args, int)), count);
	}
	else if (form == 'x' || form == 'X')
	{
		if (flag == '#')
			check_sharp_print(va_arg(args, unsigned long int), count,
				(form == 'X'));
		else
			ft_printhexa((va_arg(args, unsigned long int)), form == 'X', count);
	}
	else if (form == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, form);
	while (form[i])
	{
		if (form[i] == '%' && ft_check(form[i + 2]))
		{
			if (form[i + 1] == '+' || form[i + 1] == ' ' || form[i + 1] == '#')
			{
				ft_print(form[i + 2], args, form[i + 1], &count);
				i += 3;
			}
		}
		else
		{
			count += write(1, &form[i], 1);
			i++;
		}
	}
	va_end(args);
	return (count);
}
