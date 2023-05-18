/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:14:08 by asouchet          #+#    #+#             */
/*   Updated: 2022/11/04 15:14:09 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int				ft_putnbr_modified(int nb);
int				ft_putchar_modified(char c);
int				ft_putstr_modified(const char *str);
int				ft_printstr(const char *str);
int				ft_print_percent(void);
int				ft_printf(const char *str, ...);
unsigned int	ft_unsigned_putnbr_modified(unsigned int nb);
int				ft_find_forms(va_list args, const char form);
int				ft_putnbr_p(unsigned long long ptr);
int				ft_putnbr_h_m(unsigned long long nb);
int				ft_putnbr_h_x(unsigned long long nb);

#endif