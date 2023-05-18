/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:47:46 by asouchet          #+#    #+#             */
/*   Updated: 2022/11/07 11:47:49 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_modified(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_modified(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_modified(str[i]);
		i++;
	}
	return (i);
}

int	ft_printstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (ft_printstr("(null)"));
	}
	i = ft_putstr_modified(str);
	return (i);
}

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
