/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:04:40 by marvin            #+#    #+#             */
/*   Updated: 2023/05/19 17:04:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosopher.h"


int	main(int ac, char **av)
{
	// pthread_mutex_t mutex;
	t_rules	rules;
	
	if (ac < 5 || ac > 6)
	{
		perror("wrong amount of argument");// a changer par un printf
		return (1);
	}
	if (make_rules(&rules, av, ac))
		return (1);
	// print_philo(&rules);
	make_philo_thread(&rules);
	return (0);
}