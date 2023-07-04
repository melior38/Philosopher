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

#include "Philosopher.h"

void	*routine(void *arg)// tu veut lui passez la struct ducoup
{
	t_philosopher *philo;
	
	philo = (t_philosopher*)arg;
	//construire les trois behavior
	//sleep
	//eating
	//thinking
	return 0;
}

void	make_philo_thread(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		if (pthread_create(&rules->philosopher[i].thread , NULL, &routine, rules->philosopher + i))
		{
				perror("thread create problem:");
				exit (1);
		} 
		i++;
	}
	i = 0;
	while (i < rules->number_of_philosophers)
	{
		if (pthread_join(rules->philosopher[i].thread , NULL))
		{
				perror("thread joining problem:");
				exit (1);
		} 
		i++;
	}
// 	return (0);
}