/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:05:09 by rel-maza          #+#    #+#             */
/*   Updated: 2021/12/16 15:58:33 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_print(const char form, va_list args, char flag, int *count)
{
	if (form == 'd' || form == 'i')
		ft_putnbr((va_arg(args, int)), count);
	else if (form == 'u')
		ft_putnbr_unsigned((va_arg(args, unsigned int)), count);
	else if (form == 'c')
		ft_putchar((va_arg(args, int)), count);
	else if (form == 's')
		ft_putstr((va_arg(args, char *)), count);
	else if (form == 'p')
	{
		ft_putstr("0x", count);
		ft_printhexa_add((va_arg(args, unsigned long int)), count);
	}
	else if (form == 'x')
		ft_printhexa((va_arg(args, unsigned long int)), 0, count);
	else if (form == 'X')
		ft_printhexa((va_arg(args, unsigned long int)), 32, count);
	else if (form == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		i;
	char	flag;
	int		count;

	count = 0;
	i = 0;
	va_start(args, form);
	while (form[i])
	{
		flag = '0';
		if (form[i] == '%' && ft_check(form[i + 1]))
		{
			ft_print(form[i + 1], args, flag, &count);
			i += 2;
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
