/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:13:49 by asouchet          #+#    #+#             */
/*   Updated: 2022/11/04 15:15:48 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_find_forms(va_list args, const char form)
{
	int	le;

	le = 0;
	if (form == 'c')
		le += ft_putchar_modified(va_arg(args, int));
	else if (form == 's')
		le += ft_printstr(va_arg(args, char *));
	else if (form == '%')
		le += ft_print_percent();
	else if (form == 'p')
		le += ft_putnbr_p((unsigned long long)va_arg(args, unsigned long long));
	else if (form == 'i')
		le += ft_putnbr_modified(va_arg(args, int));
	else if (form == 'd')
		le += ft_putnbr_modified(va_arg(args, int));
	else if (form == 'u')
		le += ft_unsigned_putnbr_modified(va_arg(args, unsigned int));
	else if (form == 'x')
		le += ft_putnbr_h_x((unsigned int)va_arg(args, unsigned long long));
	else if (form == 'X')
		le += ft_putnbr_h_m((unsigned int)va_arg(args, unsigned long long));
	return (le);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		length_total;

	va_start(args, str);
	i = 0;
	length_total = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			length_total += ft_find_forms(args, str[i + 1]);
			i++;
		}
		else
			length_total += ft_putchar_modified(str[i]);
		i++;
	}
	va_end(args);
	return (length_total);
}
