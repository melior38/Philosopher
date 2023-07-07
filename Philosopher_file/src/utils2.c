/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:35:51 by asouchet          #+#    #+#             */
/*   Updated: 2023/07/07 09:31:43 by marvin           ###   ########.fr       */
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

int	validity_check(char **av, int ac)
{
	if (ft_atoi(av[1]) >= 201 || ft_atoi(av[1]) <= 0)
		return (1);
	if (ac == 6)
		if (ft_atoi(av[5]) == 0)
			return (2);
	return (0);
}
