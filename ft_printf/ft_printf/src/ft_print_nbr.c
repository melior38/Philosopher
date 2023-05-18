/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 02:22:47 by asouchet          #+#    #+#             */
/*   Updated: 2022/11/10 02:22:53 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putnbr_modified(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		ft_putstr_modified("-2147483648");
		return (11);
	}
	if (nb < 0)
	{
		nb *= -1;
		count += ft_putchar_modified('-');
	}
	if (nb >= 10)
	{
		count += ft_putnbr_modified(nb / 10);
		count += ft_putnbr_modified(nb % 10);
	}
	else if (nb < 10)
		count += ft_putchar_modified((nb + 48));
	return (count);
}

unsigned int	ft_unsigned_putnbr_modified(unsigned int nb)
{
	unsigned int	count;

	count = 0;
	if (nb >= 10)
	{
		count += ft_putnbr_modified(nb / 10);
		count += ft_putnbr_modified(nb % 10);
	}
	else if (nb < 10)
		count += ft_putchar_modified((nb + 48));
	return (count);
}

int	ft_putnbr_h_x(unsigned long long nb)
{
	int	count;

	count = 0;
	if (nb > 15)
	{
		count += ft_putnbr_h_x(nb / 16);
		count += ft_putnbr_h_x(nb % 16);
	}
	if (nb >= 10 && nb <= 15)
		count += ft_putchar_modified(nb - 10 + 'a');
	if (nb <= 9)
		count += ft_unsigned_putnbr_modified(nb);
	return (count);
}

int	ft_putnbr_h_m(unsigned long long nb)
{
	int	count;

	count = 0;
	if (nb > 15)
	{
		count += ft_putnbr_h_m(nb / 16);
		count += ft_putnbr_h_m(nb % 16);
	}
	if (nb >= 10 && nb <= 15)
		count += ft_putchar_modified(nb - 10 + 'A');
	if (nb <= 9)
		count += ft_unsigned_putnbr_modified(nb);
	return (count);
}

int	ft_putnbr_p(unsigned long long ptr)
{
	int					count;

	count = ft_printstr("0x");
	if (!ptr)
	{
		count += ft_putchar_modified('0');
		return (count);
	}
	count += ft_putnbr_h_x(ptr);
	return (count);
}
