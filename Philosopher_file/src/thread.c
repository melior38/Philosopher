/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:04:32 by marvin            #+#    #+#             */
/*   Updated: 2023/05/19 17:04:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*routine(/*void *arg*/)// tu veut lui passez la struct ducoup
{
	return 0;
}

void	set_philo(t_rules *rules, int actual_philo)
{
	t_philosopher *philo;

	philo = rules->philosopher;
	if (rules->number_of_philosophers = 1)
	{
		philo[actual_philo].right_fork_id = actual_philo;
		return ;
	}
	if( actual_philo == 0)
		philo[actual_philo].left_fork_id = rules->number_of_philosophers - 1;
	else
		philo[actual_philo].left_fork_id = actual_philo - 1;
	philo[actual_philo].last_meal = 0;
}

void	init_philo(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		set_philo(rules, i);
		i++;
	}
}

void	make_philo_thread(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		if (pthread_create(&rules->philosopher[i].thread , NULL, &routine,NULL))
		{
				perror("create problem:");
				exit (1);
		} 
		i++;
	}
// 	return (0);
}