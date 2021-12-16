/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:20:46 by rel-maza          #+#    #+#             */
/*   Updated: 2021/12/15 16:50:27 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

void	ft_putchar(char c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(int n, int *count);
void	ft_printhexa_add(unsigned long int nbr, int *count);
void	ft_printhexa(unsigned long int nbr, int toUpper, int *count);
void	ft_print(const char form, va_list args, char flag, int *count);
void	ft_putnbr_unsigned(unsigned int n, int *count);
void	check_sharp_print(int nbr, int *count, int up);
int		ft_printf(const char *form, ...);
int		ft_check(const char c);

#endif
