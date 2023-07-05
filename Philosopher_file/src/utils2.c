/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:35:51 by asouchet          #+#    #+#             */
/*   Updated: 2023/07/05 13:44:20 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

void	dynamic_sleep(long long t_to_sleep, t_rules *rules)
{
	long long i;

	i = get_time_in_ms();
	while (!(rules->dieded))
	{
		if (time_diff(i, get_time_in_ms()) >= t_to_sleep)
			break ;
		usleep(50);
	}
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}