/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:35:51 by asouchet          #+#    #+#             */
/*   Updated: 2023/07/07 14:53:00 by asouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"

void	dynamic_sleep(long long t_to_sleep, t_rules *rules)
{
	int			death_instance;
	long long	i;

	pthread_mutex_lock(&rules->write_lock);
	death_instance = rules->dieded;
	pthread_mutex_unlock(&rules->write_lock);
	i = get_time_in_ms();
	while (!(death_instance))
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
	if (ft_atoi(av[2]) <= 0 || ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
		return (1);
	if (ac == 6)
		if (ft_atoi(av[5]) == 0)
			return (2);
	return (0);
}
